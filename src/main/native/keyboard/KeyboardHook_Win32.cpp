/*
 * Copyright 2011 Kristian Kraljic, Johannes Schüth 2008. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list
 *       of conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY KRISTIAN KRALJIC AND JOHANNES SCHLUETH ''AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL KRISTIAN KRALJIC AND JOHANNES SCHLUETH OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of Kristian Kraljic and Johannes Schüth.
 */

#include <windows.h>
#include <jni.h>
#include "KeyboardHook.h"

#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x) do {} while (0)
#endif 

HINSTANCE hInst = NULL;

JavaVM * jvm = NULL;
DWORD hookThreadId = 0;

jobject keyboardHookObject = NULL;
jobject globalKeyListenerObject = NULL;
jmethodID processKeyMethod = NULL;

extern "C"
BOOL APIENTRY DllMain(HINSTANCE _hInst,DWORD reason,LPVOID reserved)  {
	switch(reason) {
		case DLL_PROCESS_ATTACH:
			DEBUG_PRINT(("NATIVE: DllMain - DLL_PROCESS_ATTACH.\n"));
			hInst = _hInst;
			break;
		default:
			break;
	}
	return TRUE;
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode,WPARAM wParam,LPARAM lParam)  {
	JNIEnv* env;
	KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT *)lParam;
	if(jvm->AttachCurrentThread((void **)&env, NULL)>=0) {
		jboolean transitionState = (jboolean)FALSE;
		switch(wParam)  {
			case WM_KEYDOWN: case WM_SYSKEYDOWN:
				transitionState = (jboolean)TRUE;
			case WM_KEYUP: case WM_SYSKEYUP:
				env->CallVoidMethod(keyboardHookObject,processKeyMethod,transitionState,p->vkCode,globalKeyListenerObject);
				break;
			default:
				break;
		}
	}	else DEBUG_PRINT(("NATIVE: LowLevelKeyboardProc - Error on the attach current thread.\n"));
	return CallNextHookEx(NULL,nCode,wParam,lParam);
}

JNIEXPORT void JNICALL Java_de_ksquared_system_keyboard_KeyboardHook_registerHook(JNIEnv * env,jobject obj,jobject _globalKeyListenerObject) {
	DEBUG_PRINT(("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Hooking started!\n"));
	
	HHOOK hookHandle = SetWindowsHookEx(WH_KEYBOARD_LL,LowLevelKeyboardProc,hInst,0);
	globalKeyListenerObject = _globalKeyListenerObject;
	
	if(hookHandle==NULL) {
		DEBUG_PRINT(("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Hook failed!\n"));
		return;
	} else DEBUG_PRINT(("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Hook successful\n"));
	
	keyboardHookObject = env->NewGlobalRef(obj);
	jclass cls = env->GetObjectClass(keyboardHookObject);
	processKeyMethod = env->GetMethodID(cls,"processKey","(ZILde/ksquared/system/keyboard/GlobalKeyListener;)V");
	
	env->GetJavaVM(&jvm);
	hookThreadId = GetCurrentThreadId();
	
	MSG message;
	while(GetMessage(&message,NULL,0,0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	
	DEBUG_PRINT(((!UnhookWindowsHookEx(hookHandle))?("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Unhook failed\n")
	                                                :"NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_registerHook - Unhook successful\n"));
}

JNIEXPORT void JNICALL Java_de_ksquared_system_keyboard_KeyboardHook_unregisterHook(JNIEnv *env,jobject object) {
	if(hookThreadId==0) return;	
	DEBUG_PRINT(("NATIVE: Java_de_ksquared_system_keyboard_KeyboardHook_unregisterHook - call PostThreadMessage.\n"));
	PostThreadMessage(hookThreadId,WM_QUIT,0,0L);
}
