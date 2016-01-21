#include <X11/Xlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KeyboardHook.h"

typedef struct key_listener {
    jobject keyboardHookObject;
    jobject globalKeyListenerObject;
    pthread_t pollingThread;
} KeyListener;

Window root;
Display *disp;
JNIEnv *env;
JavaVM *jvm;
jmethodID *processKeyMethod;
KeyListener *listeners;
int listenerCount = 0;

void *poll_input_x11(void *threadId) {
    struct timespec t1, t2;
    t1.tv_sec = 0;
    t1.tv_nsec = 10000000L; // 10ms sleep timer on polling loop
    XEvent event;
    while (nanosleep(&t1, &t2) == 0) {
        XNextEvent(disp, &event);
        if (event.type)
            if ((*jvm)->AttachCurrentThread(jvm, (void **) &env, NULL) >= 0) {
                jboolean transitionState = JNI_FALSE;
                int i;
                switch (event.type) {
                case KeyPress:
                    transitionState = JNI_TRUE;
                case KeyRelease:
                    for (i = 0; i < listenerCount; i++) {
                        KeyListener kl = listeners[i];
                        (*env)->CallVoidMethod(env, kl.keyboardHookObject, *processKeyMethod, transitionState,
                                               event.xkey.keycode, kl.globalKeyListenerObject);
                    }
                    break;
                default:
                    break;
                }
            } else {
                puts("NATIVE: poll_input_x11 - Error on attaching current thread.\n");
            }
    }
}

void delete_listener(int index) {
    KeyListener *lreduced = malloc(--listenerCount * sizeof(KeyListener));
    int offs0 = index * sizeof(KeyListener);
    int offs1 = offs0 + sizeof(KeyListener);
    memcpy(lreduced, listeners, index * sizeof(KeyListener));
    memcpy(lreduced + offs0, listeners + offs1, (listenerCount - index) * sizeof(KeyListener));
    free(listeners);
    listeners = lreduced;
}

JNIEXPORT void JNICALL Java_de_ksquared_system_keyboard_KeyboardHook_registerHook(JNIEnv *env,jobject obj,jobject _globalKeyListenerObject) {
    puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Hooking started!\n");

    if (listeners == NULL) listeners = (KeyListener*) malloc(sizeof(KeyListener));
    else listeners = (KeyListener*) realloc(listeners, ++listenerCount*sizeof(KeyListener));

    KeyListener kl;

    kl.globalKeyListenerObject = _globalKeyListenerObject;
    kl.keyboardHookObject = (*env)->NewGlobalRef(env, obj);

    if (processKeyMethod == NULL) {
        jclass cls = (*env)->GetObjectClass(env, kl.keyboardHookObject);
        jmethodID method = (*env)->GetMethodID(env, cls, "processKey", "(ZILde/ksquared/system/keyboard/GlobalKeyListener;)V");
        processKeyMethod = &method;
    }

    disp = XOpenDisplay(0);
    if (!disp) {
        puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Failed to open display '0'");
        return;
    }

    root = DefaultRootWindow(disp);

    (*env)->GetJavaVM(env, &jvm);

    int err = pthread_create(&(kl.pollingThread), NULL, poll_input_x11, (void*) 0);

    if (err) {
        puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Failed to launch new pthread.");
        return;
    }

    listeners[listenerCount - 1] = kl;
}

JNIEXPORT void JNICALL Java_de_ksquared_system_keyboard_KeyboardHook_unregisterHook(JNIEnv *env, jobject object) {
    KeyListener kl;
    int i, found;
    for (i = 0; i < listenerCount; i++) {
        kl = listeners[i];
        if ((*env)->IsSameObject(env, object, kl.keyboardHookObject)) {
            found = 1;
            break;
        }
    }
    if (!found) {
        puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_unregisterHook - No matching registered hook.");
        return;
    }
    pthread_cancel(kl.pollingThread);
    pthread_exit(NULL);
}
