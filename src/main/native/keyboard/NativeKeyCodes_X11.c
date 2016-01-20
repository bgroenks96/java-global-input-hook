/*
 * Copyright (c) 2016 Brian Groenke
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <X11/Xlib.h>
#include <X11/keysymdef.h>
#include "NativeKeyCodes.h"

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_UNDEFINED
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_UNDEFINED(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LBUTTON
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LBUTTON(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Pointer_Button1);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_RBUTTON
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1RBUTTON(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Pointer_Button2);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_CANCEL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1CANCEL(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Cancel);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_MBUTTON
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1MBUTTON(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Pointer_Button3);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_XBUTTON1
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1XBUTTON1(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Pointer_Button4);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_XBUTTON2
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1XBUTTON2(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Pointer_Button5);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_BACK
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1BACK(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_BackSpace);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_TAB
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1TAB(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Tab);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_CLEAR
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1CLEAR(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Clear);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_RETURN
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1RETURN(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Return);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_SHIFT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1SHIFT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Shift);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_CONTROL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1CONTROL(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Control_L);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_MENU
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1MENU(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Menu);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_PAUSE
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1PAUSE(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Pause);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_CAPITAL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1CAPITAL(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Caps_Lock);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_KANA
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1KANA(JNIEnv *, jclass) {
    return (jint) XKeysysToKeycode(XK_kana_switch);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_HANGUEL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1HANGUEL(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Hangul);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_HANGUL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1HANGUL(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Hangul);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_JUNJA
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1JUNJA(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_FINAL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1FINAL(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_HANJA
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1HANJA(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_KANJI
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1KANJI(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Kanji);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_ESCAPE
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1ESCAPE(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Escape);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_CONVERT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1CONVERT(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NONCONVERT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NONCONVERT(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_ACCEPT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1ACCEPT(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_MODECHANGE
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1MODECHANGE(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Mode_switch);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_SPACE
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1SPACE(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_space);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_PRIOR
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1PRIOR(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Prior);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NEXT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NEXT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Next);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_END
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1END(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_End);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_HOME
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1HOME(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Home);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LEFT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LEFT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Left);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_UP
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1UP(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Up);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_RIGHT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1RIGHT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Right);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_DOWN
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1DOWN(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Down);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_SELECT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1SELECT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Select);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_PRINT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1PRINT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Print);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_EXECUTE
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1EXECUTE(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Execute);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_SNAPSHOT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1SNAPSHOT(JNIEnv *, jclass) {
#ifdef XK_3270
    return (jint) XKeysymToKeycode(XK_3270_PrintScreen);
#else
    return (jint)UNDEF;
#endif
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_INSERT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1INSERT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Insert);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_DELETE
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1DELETE(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Delete);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_HELP
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1HELP(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Help);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_0
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_10(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_0);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_1
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_11(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_1);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_2
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_12(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_2);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_3
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_13(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_3);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_4
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_14(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_4);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_5
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_15(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_5);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_6
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_16(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_6);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_7
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_17(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_7);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_8
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_18(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_8);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_9
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_19(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_9);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_A
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1A(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_A);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_B
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1B(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_B);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_C
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1C(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_C);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_D
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1D(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_D);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_E
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1E(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_E);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_G
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1G(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_G);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_H
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1H(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_H);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_I
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1I(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_I);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_J
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1J(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_J);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_K
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1K(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_K);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_L
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1L(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_L);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_M
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1M(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_M);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_N
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1N(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(N);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_O
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1O(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_O);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_P
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1P(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_P);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_Q
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1Q(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Q);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_R
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1R(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_R);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_S
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1S(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_S);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_T
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1T(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_T);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_U
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1U(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_U);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_V
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1V(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_V);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_W
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1W(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_W);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_X
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1X(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_X);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_Y
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1Y(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Y);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_Z
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1Z(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Z);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LMETA
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LMETA(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Meta_L);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_RMETA
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1RMETA(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Meta_R);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_APPS
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1APPS(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_SLEEP
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1SLEEP(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD0
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD0(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_0);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD1
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD1(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_1);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD2
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD2(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_2);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD3
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD3(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_3);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD4
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD4(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_4);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD5
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD5(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_5);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD6
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD6(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_6);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD7
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD7(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_7);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD8
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD8(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_8);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMPAD9
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMPAD9(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_9);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_MULTIPLY
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1MULTIPLY(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_Multiply);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_ADD
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1ADD(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_Add);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_SEPARATOR
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1SEPARATOR(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_Separator);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_SUBTRACT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1SUBTRACT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_Subtract);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_DECIMAL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1DECIMAL(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_Decimal);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_DIVIDE
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1DIVIDE(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_KP_Divide);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F1
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F1(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F1);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F2
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F2(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F2);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F3
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F3(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F3);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F4
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F4(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F4);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F5
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F5(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F5);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F6
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F6(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F6);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F7
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F7(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F7);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F8
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F8(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F8);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F9
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F9(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F9);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F10
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F10(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F10);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F11
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F11(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F11);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F12
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F12(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F12);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F13
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F13(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F13);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F14
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F14(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F14);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F15
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F15(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F15);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F16
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F16(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F16);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F17
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F17(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F17);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F18
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F18(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F18);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F19
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F19(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F19);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F20
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F20(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F20);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F21
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F21(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F21);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F22
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F22(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F22);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F23
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F23(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F23);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_F24
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1F24(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_F24);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NUMLOCK
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NUMLOCK(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Num_Lock);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_SCROLL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1SCROLL(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Scroll_Lock);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LSHIFT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LSHIFT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Shift_L);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_RSHIFT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1RSHIFT(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Shift_R);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LCONTROL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LCONTROL(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Control_L);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_RCONTROL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1RCONTROL(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Control_R);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LMENU
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LMENU(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Alt_L);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_RMENU
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1RMENU(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_Alt_R);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_BROWSER_BACK
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1BROWSER_1BACK(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_BROWSER_FORWARD
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1BROWSER_1FORWARD(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_BROWSER_REFRESH
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1BROWSER_1REFRESH(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_BROWSER_STOP
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1BROWSER_1STOP(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_BROWSER_SEARCH
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1BROWSER_1SEARCH(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_BROWSER_FAVORITES
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1BROWSER_1FAVORITES(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_BROWSER_HOME
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1BROWSER_1HOME(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_VOLUME_MUTE
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1VOLUME_1MUTE(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_VOLUME_DOWN
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1VOLUME_1DOWN(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_VOLUME_UP
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1VOLUME_1UP(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_MEDIA_NEXT_TRACK
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1MEDIA_1NEXT_1TRACK(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_MEDIA_PREV_TRACK
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1MEDIA_1PREV_1TRACK(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_MEDIA_STOP
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1MEDIA_1STOP(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_MEDIA_PLAY_PAUSE
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1MEDIA_1PLAY_1PAUSE(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LAUNCH_MAIL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LAUNCH_1MAIL(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LAUNCH_MEDIA_SELECT
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LAUNCH_1MEDIA_1SELECT(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LAUNCH_APP1
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LAUNCH_1APP1(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_LAUNCH_APP2
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1LAUNCH_1APP2(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_1
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_11(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_semicolon);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_PLUS
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_1PLUS(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_plus);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_COMMA
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_1COMMA(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_comma);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_MINUS
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_1MINUS(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_minus);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_PERIOD
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_1PERIOD(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_period);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_2
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_12(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_slash);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_3
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_13(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_asciitilde);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_4
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_14(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_bracketleft);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_5
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_15(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_backslash);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_6
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_16(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_bracketright);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_7
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_17(JNIEnv *, jclass) {
    return (jint) XKeysymToKeycode(XK_apostrophe);
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_8
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_18(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_102
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_1102(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_PROCESSKEY
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1PROCESSKEY(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_PACKET
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1PACKET(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_ATTN
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1ATTN(JNIEnv *, jclass) {
#ifdef XK_3270
    return (jint) XKeysymToKeycode(XK_3270_Attn);
#else
    return (jint)UNDEF;
#endif
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_CRSEL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1CRSEL(JNIEnv *, jclass) {
#ifdef XK_3270
    return (jint) XKeysymToKeycode(XK_3270_CursorSelect);
#else
    return (jint)UNDEF;
#endif
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_EXSEL
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1EXSEL(JNIEnv *, jclass) {
#ifdef XK_3270
    return (jint) XKeysymToKeycode(XK_3270_ExSelect);
#else
    return (jint)UNDEF;
#endif
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_EREOF
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1EREOF(JNIEnv *, jclass) {
#ifdef XK_3270
    return (jint) XKeysymToKeycode(XK_3270_EraseEOF);
#else
    return (jint)UNDEF;
#endif
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_PLAY
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1PLAY(JNIEnv *, jclass) {
#ifdef XK_3270
    return (jint) XKeysymToKeycode(XK_3270_Play);
#else
    return (jint)UNDEF;
#endif
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_ZOOM
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1ZOOM(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_NONAME
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1NONAME(JNIEnv *, jclass) {
    return (jint)UNDEF;
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_PA1
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1PA1(JNIEnv *, jclass) {
#ifdef XK_3270
    return (jint) XKeysymToKeycode(XK_3270_PA1);
#else
    return (jint)UNDEF;
#endif
}

/*
 * Class:     de_ksquared_system_keyboard_NativeKeyCodes
 * Method:    KC_OEM_CLEAR
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_ksquared_system_keyboard_NativeKeyCodes_KC_1OEM_1CLEAR(JNIEnv *, jclass) {
#ifdef XK_3270
    return (jint) XKeysymToKeycode(XK_3270_Reset);
#else
    return (jint)UNDEF;
#endif
}
