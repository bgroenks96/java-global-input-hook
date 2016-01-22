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
#include "MouseHook.h"

#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x) do {} while (0)
#endif 

HINSTANCE hInst = NULL;

JavaVM * jvm = NULL;
DWORD hookThreadId = 0;

jobject mouseHookObject = NULL;
jobject globalMouseListenerObject = NULL;
jmethodID processMouseButtonMethod = NULL;
jmethodID processMouseMoveMethod = NULL;

LONG mouseLocationX=-1,mouseLocationY=-1;

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

LRESULT CALLBACK LowLevelMouseProc(int nCode,WPARAM wParam,LPARAM lParam) {
	JNIEnv* env;
	if(jvm->AttachCurrentThread((void **)&env, NULL)>=0) {
		if(nCode==HC_ACTION) {
			MOUSEHOOKSTRUCT* pStruct = (MOUSEHOOKSTRUCT*)lParam;
			switch(wParam) {
			case WM_LBUTTONDOWN: case WM_LBUTTONUP:
			case WM_RBUTTONDOWN: case WM_RBUTTONUP:
				env->CallVoidMethod(mouseHookObject,processMouseButtonMethod,(jint)wParam,globalMouseListenerObject);
				break;
			case WM_MOUSEMOVE:
				if(pStruct->pt.x!=mouseLocationX||pStruct->pt.y!=mouseLocationY) {
					env->CallVoidMethod(mouseHookObject,processMouseMoveMethod,(jint)pStruct->pt.x,(jint)pStruct->pt.y,globalMouseListenerObject);
					mouseLocationX = pStruct->pt.x;
					mouseLocationX = pStruct->pt.y;
				}
				break;
			default:
				break;
			}
		}
	} else DEBUG_PRINT(("NATIVE: LowLevelMouseProc - Error on the attach current thread.\n"));
	return CallNextHookEx(NULL,nCode,wParam,lParam);
}

JNIEXPORT void JNICALL Java_de_ksquared_system_mouse_MouseHook_registerHook(JNIEnv * env,jobject obj,jobject _globalMouseListenerObject) {
	DEBUG_PRINT(("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Hooking started!\n"));

	HHOOK hookHandle = SetWindowsHookEx(WH_MOUSE_LL,LowLevelMouseProc,hInst,0);
	globalMouseListenerObject = _globalMouseListenerObject;
	
	if(hookHandle==NULL) {
		DEBUG_PRINT(("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Hook failed!\n"));
		return;
	} else DEBUG_PRINT(("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Hook successful\n"));
	
	mouseHookObject = env->NewGlobalRef(obj);
	jclass cls = env->GetObjectClass(mouseHookObject);
	processMouseButtonMethod = env->GetMethodID(cls,"processButton","(ILde/ksquared/system/mouse/GlobalMouseListener;)V");
	processMouseMoveMethod = env->GetMethodID(cls,"processMove","(IILde/ksquared/system/mouse/GlobalMouseListener;)V");
	
	env->GetJavaVM(&jvm);
	hookThreadId = GetCurrentThreadId();

	MSG message;
	while(GetMessage(&message,NULL,0,0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	
	DEBUG_PRINT(((!UnhookWindowsHookEx(hookHandle))?("NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Unhook failed\n")
	                                                :"NATIVE: Java_de_ksquared_system_mouse_MouseHook_registerHook - Unhook successful\n"));
}

JNIEXPORT void JNICALL Java_de_ksquared_system_mouse_MouseHook_unregisterHook(JNIEnv *env,jobject object) {
	if(hookThreadId==0) return;	
	DEBUG_PRINT(("NATIVE: Java_de_ksquared_system_mouse_MouseHook_unregisterHook - call PostThreadMessage.\n"));
	PostThreadMessage(hookThreadId,WM_QUIT,0,0L);
}
