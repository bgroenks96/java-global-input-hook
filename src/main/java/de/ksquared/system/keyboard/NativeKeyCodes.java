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

package de.ksquared.system.keyboard;

class NativeKeyCodes {
  
    static {
    	Native.load();
        init();
    }
  
    private static native int init();

    static native int KC_UNDEFINED();

    static native int KC_LBUTTON();

    static native int KC_RBUTTON();

    static native int KC_CANCEL();

    static native int KC_MBUTTON();

    static native int KC_XBUTTON1();

    static native int KC_XBUTTON2();

    static native int KC_BACK();

    static native int KC_TAB();

    static native int KC_CLEAR();

    static native int KC_RETURN();

    static native int KC_SHIFT();

    static native int KC_CONTROL();

    static native int KC_MENU();

    static native int KC_PAUSE();

    static native int KC_CAPITAL();

    static native int KC_KANA();

    static native int KC_HANGUEL();

    static native int KC_HANGUL();

    static native int KC_JUNJA();

    static native int KC_FINAL();

    static native int KC_HANJA();

    static native int KC_KANJI();

    static native int KC_ESCAPE();

    static native int KC_CONVERT();

    static native int KC_NONCONVERT();

    static native int KC_ACCEPT();

    static native int KC_MODECHANGE();

    static native int KC_SPACE();

    static native int KC_PRIOR();

    static native int KC_NEXT();

    static native int KC_END();

    static native int KC_HOME();

    static native int KC_LEFT();

    static native int KC_UP();

    static native int KC_RIGHT();

    static native int KC_DOWN();

    static native int KC_SELECT();

    static native int KC_PRINT();

    static native int KC_EXECUTE();

    static native int KC_SNAPSHOT();

    static native int KC_INSERT();

    static native int KC_DELETE();

    static native int KC_HELP();

    static native int KC_0();

    static native int KC_1();

    static native int KC_2();

    static native int KC_3();

    static native int KC_4();

    static native int KC_5();

    static native int KC_6();

    static native int KC_7();

    static native int KC_8();

    static native int KC_9();

    static native int KC_A();

    static native int KC_B();

    static native int KC_C();

    static native int KC_D();

    static native int KC_E();

    static native int KC_F();

    static native int KC_G();

    static native int KC_H();

    static native int KC_I();

    static native int KC_J();

    static native int KC_K();

    static native int KC_L();

    static native int KC_M();

    static native int KC_N();

    static native int KC_O();

    static native int KC_P();

    static native int KC_Q();

    static native int KC_R();

    static native int KC_S();

    static native int KC_T();

    static native int KC_U();

    static native int KC_V();

    static native int KC_W();

    static native int KC_X();

    static native int KC_Y();

    static native int KC_Z();

    static native int KC_LMETA();

    static native int KC_RMETA();

    static native int KC_APPS();

    static native int KC_SLEEP();

    static native int KC_NUMPAD0();

    static native int KC_NUMPAD1();

    static native int KC_NUMPAD2();

    static native int KC_NUMPAD3();

    static native int KC_NUMPAD4();

    static native int KC_NUMPAD5();

    static native int KC_NUMPAD6();

    static native int KC_NUMPAD7();

    static native int KC_NUMPAD8();

    static native int KC_NUMPAD9();
    
    static native int KC_NUMPAD_ENTER();

    static native int KC_MULTIPLY();

    static native int KC_ADD();

    static native int KC_SEPARATOR();

    static native int KC_SUBTRACT();

    static native int KC_DECIMAL();

    static native int KC_DIVIDE();

    static native int KC_F1();

    static native int KC_F2();

    static native int KC_F3();

    static native int KC_F4();

    static native int KC_F5();

    static native int KC_F6();

    static native int KC_F7();

    static native int KC_F8();

    static native int KC_F9();

    static native int KC_F10();

    static native int KC_F11();

    static native int KC_F12();

    static native int KC_F13();

    static native int KC_F14();

    static native int KC_F15();

    static native int KC_F16();

    static native int KC_F17();

    static native int KC_F18();

    static native int KC_F19();

    static native int KC_F20();

    static native int KC_F21();

    static native int KC_F22();

    static native int KC_F23();

    static native int KC_F24();

    static native int KC_NUMLOCK();

    static native int KC_SCROLL();

    static native int KC_LSHIFT();

    static native int KC_RSHIFT();

    static native int KC_LCONTROL();

    static native int KC_RCONTROL();

    static native int KC_LMENU();

    static native int KC_RMENU();

    static native int KC_BROWSER_BACK();

    static native int KC_BROWSER_FORWARD();

    static native int KC_BROWSER_REFRESH();

    static native int KC_BROWSER_STOP();

    static native int KC_BROWSER_SEARCH();

    static native int KC_BROWSER_FAVORITES();

    static native int KC_BROWSER_HOME();

    static native int KC_VOLUME_MUTE();

    static native int KC_VOLUME_DOWN();

    static native int KC_VOLUME_UP();

    static native int KC_MEDIA_NEXT_TRACK();

    static native int KC_MEDIA_PREV_TRACK();

    static native int KC_MEDIA_STOP();

    static native int KC_MEDIA_PLAY_PAUSE();

    static native int KC_LAUNCH_MAIL();

    static native int KC_LAUNCH_MEDIA_SELECT();

    static native int KC_LAUNCH_APP1();

    static native int KC_LAUNCH_APP2();

    static native int KC_OEM_1();

    static native int KC_OEM_PLUS();

    static native int KC_OEM_COMMA();

    static native int KC_OEM_MINUS();

    static native int KC_OEM_PERIOD();

    static native int KC_OEM_2();

    static native int KC_OEM_3();

    static native int KC_OEM_4();

    static native int KC_OEM_5();

    static native int KC_OEM_6();

    static native int KC_OEM_7();

    static native int KC_OEM_8();

    static native int KC_OEM_102();

    static native int KC_PROCESSKEY();

    static native int KC_PACKET();

    static native int KC_ATTN();

    static native int KC_CRSEL();

    static native int KC_EXSEL();

    static native int KC_EREOF();

    static native int KC_PLAY();

    static native int KC_ZOOM();

    static native int KC_NONAME();

    static native int KC_PA1();

    static native int KC_OEM_CLEAR();
}
