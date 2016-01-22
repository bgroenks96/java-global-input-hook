#include <X11/Xlib.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MouseHook.h"

// emulated win32 mouse button event identifiers
#define WM_LBUTTONDOWN 513
#define WM_LBUTTONUP 514
#define WM_RBUTTONDOWN 515
#define WM_RBUTTONUP 516

// declare utility functions
int index_of_listener(JNIEnv*, jobject);
void delete_listener(JNIEnv*, int);

typedef struct mouse_listener {
        jobject mouseHookObject;
        jobject globalMouseListenerObject;
        pthread_t pollingThread;
        volatile int shouldStop;
} MouseListener;

Window root;
Display *disp;
JavaVM *jvm;
jmethodID processMouseButtonMethod, processMouseMoveMethod;
MouseListener *listeners;
int listenerCount = 0;

void *poll_mouse_input_x11(void *arg) {
    int index = *((int*) arg);
    free(arg); // deallocate arg pointer
    MouseListener *ml = &listeners[index];
    struct timespec t1, t2;
    t1.tv_sec = 0;
    t1.tv_nsec = 10000000L; // 10ms sleep timer on polling loop
    JNIEnv *env;
    int lastX, lastY;
    unsigned int lastMask;
    while (nanosleep(&t1, &t2) == 0) {
        if (ml->shouldStop) pthread_exit(NULL);

        if ((*jvm)->AttachCurrentThread(jvm, (void **) &env, NULL) >= 0) {
            Window ptrRoot, childRoot;
            int rootX, rootY, winX, winY;
            unsigned int mask;
            XQueryPointer(disp, root, &ptrRoot, &childRoot, &rootX, &rootY, &winX, &winY, &mask);
            // process mouse moved event
            if (rootX != lastX || rootY != lastY) {
                (*env)->CallVoidMethod(env, ml->mouseHookObject, processMouseMoveMethod, (jint) rootX, (jint) rootY, ml->globalMouseListenerObject);
                lastX = rootX;
                lastY = rootY;
            }
            // process mouse button events
            if (mask != lastMask) {
                // button 1 state change
                if (Button1Mask & lastMask != Button1Mask & mask) {
                    jint evt;
                    if (Button1Mask & lastMask == 0) evt = WM_LBUTTONDOWN;
                    else if (Button1Mask & mask == 0) evt = WM_LBUTTONUP;
                    (*env)->CallVoidMethod(env, ml->mouseHookObject, processMouseButtonMethod, evt, ml->globalMouseListenerObject);
                }
                // button 2 state change
                if (Button2Mask & lastMask != Button2Mask & mask) {
                    jint evt;
                    if (Button1Mask & lastMask == 0) evt = WM_RBUTTONDOWN;
                    else if (Button1Mask & mask == 0) evt = WM_RBUTTONUP;
                    (*env)->CallVoidMethod(env, ml->mouseHookObject, processMouseButtonMethod, evt, ml->globalMouseListenerObject);
                }
                lastMask = mask;
            }

            (*jvm)->DetachCurrentThread(jvm);
        } else {
            puts("NATIVE: poll_input_x11 - Error on attaching current thread.\n");
            fflush(stdout);
        }
    }
}

JNIEXPORT void JNICALL Java_de_ksquared_system_mouse_MouseHook_registerHook(JNIEnv *env, jobject thisObj, jobject _globalMouseListenerObject) {
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
        processMouseButtonMethod = (*env)->GetMethodID(env, cls, "processButton", "(ILde/ksquared/system/mouse/GlobalMouseListener;)V");
        processMouseMoveMethod = (*env)->GetMethodID(env, cls, "processMove", "(IILde/ksquared/system/mouse/GlobalMouseListener;)V");
    }

    if(!disp) disp = XOpenDisplay(0);
    if (!disp) {
        puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Failed to open display '0'");
        return;
    }

    root = DefaultRootWindow(disp);

    (*env)->GetJavaVM(env, &jvm);

    listeners[listenerCount - 1] = ml;

    pthread_attr_t thread_config;
    pthread_attr_init(&thread_config);
    int *arg = malloc(sizeof(int));
    *arg = listenerCount - 1;
    // start thread with thread_config and the current listener index as the argument
    int err = pthread_create(&ml.pollingThread, &thread_config, poll_mouse_input_x11, (void*) arg);

    if (err) {
        puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Failed to launch new pthread.");
        delete_listener(env, listenerCount - 1);
        return;
    }

    puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Successfully initialized event polling!");
    fflush(stdout);
}

JNIEXPORT void JNICALL Java_de_ksquared_system_mouse_MouseHook_unregisterHook(JNIEnv *env, jobject object) {
    int index = index_of_listener(env, object);
    if (index < 0) {
        puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_unregisterHook - No matching listener registered!");
        return;
    }
    MouseListener *ml = &listeners[index];
    pthread_t thread = ml->pollingThread;
    // notify thread to terminate
    ml->shouldStop = 1;
    pthread_join(thread, NULL);
    delete_listener(env, index);
    if (listenerCount == 0) {
        XCloseDisplay(disp);
        disp = NULL;
    }

    puts("NATIVE: Java_de_ksquared_system_mouse_MouseHook_unregisterHook - Sucessfully unregistered hook.");
    pthread_exit(NULL);
}

// utility function implementations

int index_of_listener(JNIEnv *env, jobject mouseHookObject) {
    int i, index = -1;
    for (i = 0; i < listenerCount; i++) {
        MouseListener *next = &listeners[i];
        if ((*env)->IsSameObject(env, mouseHookObject, next->mouseHookObject)) {
            index = i;
            break;
        }
    }
    return index;
}

void delete_listener(JNIEnv *env, int index) {
    if (index < 0) return;
    MouseListener *ml = &listeners[index];
    // delete jni resources and detach thread
    (*env)->DeleteGlobalRef(env, ml->mouseHookObject);
    (*env)->DeleteGlobalRef(env, ml->globalMouseListenerObject);

    // remove from listener array
    MouseListener *lreduced = malloc(--listenerCount * sizeof(MouseListener));
    int offs0 = index * sizeof(MouseListener);
    int offs1 = offs0 + sizeof(MouseListener);
    memcpy(lreduced, listeners, index * sizeof(MouseListener));
    memcpy(lreduced + offs0, listeners + offs1, (listenerCount - index) * sizeof(MouseListener));
    free(listeners);
    listeners = lreduced;
}
