#include <X11/Xlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "KeyboardHook.h"

typedef struct mouse_listener {
    jobject mouseHookObject;
    jobject globalMouseListenerObject;
    pthread_t pollingThread;
    pthread_mutex_t termLock;
} MouseListener;

Window root;
Display *disp;
JavaVM *jvm;
jmethodID processMouseButtonMethod, processMouseMoveMethod;
MouseListener *listeners;
int listenerCount = 0;

void *poll_input_x11(void *arg) {
    int index = *((int*) arg);
    free(arg); // deallocate arg pointer
    MouseListener ml = listeners[index];
    struct timespec t1, t2;
    t1.tv_sec = 0;
    t1.tv_nsec = 10000000L; // 10ms sleep timer on polling loop
    int lastX, lastY;
    unsigned int lastMask;
    while (nanosleep(&t1, &t2) == 0) {
        int termSignal = pthread_mutex_trylock(&ml.termLock);
        if (termSignal)
            pthread_exit(NULL);
        Window ptrRoot, childRoot;
        int rootX, rootY, winX, winY;
        unsigned int mask;
        XQueryPointer(disp, root, &ptrRoot, &childRoot, &rootX, &rootY, &winX, &winY, &mask);
        JNIEnv *env;
        if ((*jvm)->AttachCurrentThread(jvm, (void **) &env, NULL) >= 0) {
           // (*env)->CallVoidMethod(env, ml.mouseHookObject, processKeyMethod, transitionState, (jint) keyCode,
                                   ml.globalMouseListenerObject);
        } else {
            puts("NATIVE: poll_input_x11 - Error on attaching current thread.\n");
            fflush(stdout);
        }
        prev[i] = currKeyByte;
        pthread_mutex_unlock(&ml.termLock);
    }
}

void delete_listener(int index) {
    if (listenerCount == 0)
        return;
    MouseListener *lreduced = malloc(--listenerCount * sizeof(MouseListener));
    int offs0 = index * sizeof(MouseListener);
    int offs1 = offs0 + sizeof(MouseListener);
    memcpy(lreduced, listeners, index * sizeof(MouseListener));
    memcpy(lreduced + offs0, listeners + offs1, (listenerCount - index) * sizeof(MouseListener));
    free(listeners);
    listeners = lreduced;
}

JNIEXPORT void JNICALL JNIEXPORT void JNICALL Java_de_ksquared_system_mouse_MouseHook_registerHook(JNIEnv *,jobject thisObj,jobject listenerObj);(JNIEnv *env,jobject obj,jobject _globalMouseListenerObject) {
    puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Registering input hook...");
    fflush(stdout);

    const size_t alloc_size = ++listenerCount*sizeof(MouseListener);
    if (listeners == NULL) listeners = (MouseListener*) malloc(alloc_size);
    else listeners = (MouseListener*) realloc(listeners, alloc_size);

    MouseListener ml;

    ml.globalMouseListenerObject = (*env)->NewGlobalRef(env, _globalMouseListenerObject);
    ml.mouseHookObject = (*env)->NewGlobalRef(env, thisObj);

    if (!processMouseButtonMethod || !processMouseMoveMethod) {
        jclass cls = (*env)->GetObjectClass(env, ml.mouseHookObject);
        processMouseButtonMethod = env->GetMethodID(cls,"processButton","(ILde/ksquared/system/mouse/GlobalMouseListener;)V");
        processMouseMoveMethod = env->GetMethodID(cls,"processMove","(IILde/ksquared/system/mouse/GlobalMouseListener;)V");
    }

    if(!disp) disp = XOpenDisplay(0);
    if (!disp) {
        puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Failed to open display '0'");
        return;
    }

    root = DefaultRootWindow(disp);

    (*env)->GetJavaVM(env, &jvm);

    pthread_mutex_init(&ml.termLock, NULL);
    pthread_attr_t thread_config;
    pthread_attr_init(&thread_config);
    int *arg = malloc(sizeof(int));
    *arg = listenerCount - 1;
    // start thread with thread_config and the current listener index as the argument
    int err = pthread_create(&ml.pollingThread, &thread_config, poll_input_x11, (void*) arg);

    if (err) {
        puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Failed to launch new pthread.");
        return;
    }

    pthread_detach(ml.pollingThread);

    listeners[listenerCount - 1] = ml;

    puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Successfully initialized event polling!");
    fflush(stdout);
}

JNIEXPORT void JNICALL JNIEXPORT void JNICALL Java_de_ksquared_system_mouse_MouseHook_unregisterHook(JNIEnv *env, jobject object) {
    MouseListener ml;
    int i, index = -1;
    for (i = 0; i < listenerCount; i++) {
        ml = listeners[i];
        if ((*env)->IsSameObject(env, object, ml.mouseHookObject)) {
            index = i;
            break;
        }
    }
    if (index < 0) {
        puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_unregisterHook - No matching registered hook.");
        fflush(stdout);
        return;
    }
    // kill thread and clean up
    pthread_mutex_lock(&ml.termLock);
    pthread_mutex_destroy(&ml.termLock);
    (*env)->DeleteGlobalRef(env, ml.mouseHookObject);
    (*env)->DeleteGlobalRef(env, ml.globalMouseListenerObject);
    delete_listener(index);
    if (listenerCount == 0) {
        XCloseDisplay(disp);
        disp = NULL;
    }

    puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_unregisterHook - Sucessfully unregistered hook.");
    fflush(stdout);
}
