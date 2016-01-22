#include <X11/Xlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "KeyboardHook.h"

typedef struct key_listener {
    jobject keyboardHookObject;
    jobject globalKeyListenerObject;
    pthread_t pollingThread;
    pthread_mutex_t termLock;
} KeyListener;

Display *disp;
JavaVM *jvm;
jmethodID processKeyMethod;
KeyListener *listeners;
int listenerCount = 0;

void *poll_input_x11(void *arg) {
    int index = *((int*)arg);
    free(arg); // deallocate arg pointer
    KeyListener kl = listeners[index];
    struct timespec t1, t2;
    t1.tv_sec = 0;
    t1.tv_nsec = 10000000L; // 10ms sleep timer on polling loop
    char prev[32];
    char curr[32];
    while (nanosleep(&t1, &t2) == 0) {
        int termSignal = pthread_mutex_trylock(&kl.termLock);
        if (termSignal) pthread_exit(NULL);
        XQueryKeymap(disp, curr);
        int i,j,k;
        for (i = 0; i < 32; i++) {
            char prevKeyByte = prev[i], currKeyByte = curr[i];
            for (j = 0; j < 8; j++) {
                int keyCode = i*8 + j;
                int prevKeyBit = (0x1 << j) & prevKeyByte;
                int currKeyBit = (0x1 << j) & currKeyByte;
                if (prevKeyBit == currKeyBit) continue;
                jboolean transitionState;
                transitionState = (prevKeyBit > 0) ? JNI_FALSE : JNI_TRUE;
                JNIEnv *env;
                if ((*jvm)->AttachCurrentThread(jvm, (void **) &env, NULL) >= 0) {
                    (*env)->CallVoidMethod(env, kl.keyboardHookObject, processKeyMethod, transitionState,
                                           (jint) keyCode, kl.globalKeyListenerObject);
                } else {
                    puts("NATIVE: poll_input_x11 - Error on attaching current thread.\n");
                    fflush(stdout);
                }
                prev[i] = currKeyByte;
            }
        }
        pthread_mutex_unlock(&kl.termLock);
    }
}

void delete_listener(int index) {
    if (listenerCount == 0) return;
    KeyListener *lreduced = malloc(--listenerCount * sizeof(KeyListener));
    int offs0 = index * sizeof(KeyListener);
    int offs1 = offs0 + sizeof(KeyListener);
    memcpy(lreduced, listeners, index * sizeof(KeyListener));
    memcpy(lreduced + offs0, listeners + offs1, (listenerCount - index) * sizeof(KeyListener));
    free(listeners);
    listeners = lreduced;
}

JNIEXPORT void JNICALL Java_de_ksquared_system_keyboard_KeyboardHook_registerHook(JNIEnv *env,jobject obj,jobject _globalKeyListenerObject) {
    puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Registering input hook...");
    fflush(stdout);

    const size_t alloc_size = ++listenerCount*sizeof(KeyListener);
    if (listeners == NULL) listeners = (KeyListener*) malloc(alloc_size);
    else listeners = (KeyListener*) realloc(listeners, alloc_size);

    KeyListener kl;

    kl.globalKeyListenerObject = (*env)->NewGlobalRef(env, _globalKeyListenerObject);
    kl.keyboardHookObject = (*env)->NewGlobalRef(env, obj);

    if (!processKeyMethod) {
        jclass cls = (*env)->GetObjectClass(env, kl.keyboardHookObject);
        processKeyMethod = (*env)->GetMethodID(env, cls, "processKey", "(ZILde/ksquared/system/keyboard/GlobalKeyListener;)V");
    }

    if(!disp) disp = XOpenDisplay(0);
    if (!disp) {
        puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Failed to open display '0'");
        return;
    }

    (*env)->GetJavaVM(env, &jvm);

    pthread_mutex_init(&kl.termLock, NULL);
    pthread_attr_t thread_config;
    pthread_attr_init(&thread_config);
    int *arg = malloc(sizeof(int));
    *arg = listenerCount - 1;
    // start thread with thread_config and the current listener index as the argument
    int err = pthread_create(&kl.pollingThread, &thread_config, poll_input_x11, (void*) arg);

    if (err) {
        puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Failed to launch new pthread.");
        return;
    }
    
    pthread_detach(kl.pollingThread);

    listeners[listenerCount - 1] = kl;

    puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Successfully initialized event polling!"); 
    fflush(stdout);   
}

JNIEXPORT void JNICALL Java_de_ksquared_system_keyboard_KeyboardHook_unregisterHook(JNIEnv *env, jobject object) {
    KeyListener kl;
    int i, index = -1;
    for (i = 0; i < listenerCount; i++) {
        kl = listeners[i];
        if ((*env)->IsSameObject(env, object, kl.keyboardHookObject)) {
            index = i;
            break;
        }
    }
    if (index < 0) {
        puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_unregisterHook - No matching registered hook.");
        fflush(stdout);
        return;
    }
    // kill thread and clean up
    pthread_mutex_lock(&kl.termLock);
    pthread_mutex_destroy(&kl.termLock);
    pthread_destroy(&kl.pollingThread);
    (*env)->DeleteGlobalRef(env, kl.keyboardHookObject);
    (*env)->DeleteGlobalRef(env, kl.globalKeyListenerObject);
    delete_listener(index);
    if (listenerCount == 0) {
        XCloseDisplay(disp);
        disp = NULL;
    }
    
    puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_unregisterHook - Sucessfully unregistered hook.");
    fflush(stdout);
}
