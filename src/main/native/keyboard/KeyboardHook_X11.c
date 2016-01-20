#include <X11/Xlib.h>
#include <pthread.h>
#include <stdio.h>
#include "KeyboardHook.h"

Window root;
Display *disp;
JavaVM *jvm = NULL;
jobject keyboardHookObject = NULL;
jobject globalKeyListenerObject = NULL;
jmethodID processKeyMethod = NULL;
pthread pollingThread;
int running = 0;

void *poll_input_x11(void *threadId) {
    struct timespec t1, t2;
    t1.tv_sec = 0;
    t1.tv_nsec = 10000000L; // 10ms sleep timer on polling loop
    XEvent event;
    while (nanosleep(&t1, &t2) == 0) {
        XNextEvent(disp, &event);
        if (event.type)
            if ((*jvm)->AttachCurrentThread(jvm, (void **) &env, NULL) >= 0) {
                jboolean transitionState = (jboolean) FALSE;
                switch (event.type) {
                case KeyPress:
                    transitionState = (jboolean) TRUE;
                case KeyRelease:
                    (*env)->CallVoidMethod(env, keyboardHookObject, processKeyMethod, transitionState,
                                           event.xkey.keycode, globalKeyListenerObject);
                    break;
                default:
                    break;
                }
            } else {
                puts("NATIVE: poll_input_x11 - Error on attaching current thread.\n");
            }
    }
}

JNIEXPORT void JNICALL Java_de_ksquared_system_keyboard_KeyboardHook_registerHook(JNIEnv * env,jobject obj,jobject _globalKeyListenerObject) {
    puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Hooking started!\n");

    globalKeyListenerObject = _globalKeyListenerObject;
    keyboardHookObject = (*env)->NewGlobalRef(env, obj);
    jclass cls = (*env)->GetObjectClass(env, keyboardHookObject);
    processKeyMethod = (*env)->GetMethodID(env, cls, "processKey", "(ZILde/ksquared/system/keyboard/GlobalKeyListener;)V");

    disp = XOpenDisplay(0);
    if (!disp) {
        puts("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Failed to open display '0'");
        return;
    }

    root = DefaultRootWindow(disp);

    (*env)->GetJavaVM(env, &jvm);

    int chk = pthread_create(&pollingThread, NULL, poll_input_x11, (void*) 0);
    running = 1;
}

JNIEXPORT void JNICALL Java_de_ksquared_system_keyboard_KeyboardHook_unregisterHook(JNIEnv *env,jobject object) {
    if (!running) return;
    pthread_cancel(pollingThread);
    pthread_exit(NULL);
}
