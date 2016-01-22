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
 * ----------------------------------------------------------------------------------------------------------------------------
 * Copyright 2011 Kristian Kraljic, Johannes Sch�th 2008. All rights reserved.
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
 * or implied, of Kristian Kraljic and Johannes Sch�th.
 */

package de.ksquared.system.keyboard;

import java.util.EventObject;
import java.util.HashMap;
import java.util.Map;

public class KeyEvent extends EventObject {

    private static final long serialVersionUID = -8194688548489965445L;

    /**
     * Provides native key code bindings based on the Win32 virtual key
     * specification. Note that some non-standard bindings may be platform
     * specific. Key codes unrecognized by the underlying system will always
     * hold the same value as {@link #UNDEFINED}. Some virtual codes may also
     * be recognized differently depending on the platform; e.g. For Linux/X11
     * systems, {@link #KC_RETURN} and {@link #KC_NUMPAD_ENTER} will return
     * distinct key code values, while on Windows they will be identical.
     * The raw native key code of a KeyEvent can always be accessed via KeyEvent.getNativeKeyCode();
     * 
     * @author Brian Groenke
     */
    public enum KeyCode {
        UNDEFINED(NativeKeyCodes.KC_UNDEFINED()),
        KC_LBUTTON(NativeKeyCodes.KC_LBUTTON()),
        KC_RBUTTON(NativeKeyCodes.KC_RBUTTON()),
        KC_CANCEL(NativeKeyCodes.KC_CANCEL()),
        KC_MBUTTON(NativeKeyCodes.KC_MBUTTON()),
        KC_XBUTTON1(NativeKeyCodes.KC_XBUTTON1()),
        KC_XBUTTON2(NativeKeyCodes.KC_XBUTTON2()),
        KC_BACK(NativeKeyCodes.KC_BACK()),
        KC_TAB(NativeKeyCodes.KC_TAB()),
        KC_CLEAR(NativeKeyCodes.KC_CLEAR()),
        KC_RETURN(NativeKeyCodes.KC_RETURN()),
        KC_SHIFT(NativeKeyCodes.KC_SHIFT()),
        KC_CONTROL(NativeKeyCodes.KC_CONTROL()),
        KC_MENU(NativeKeyCodes.KC_MENU()),
        KC_PAUSE(NativeKeyCodes.KC_PAUSE()),
        KC_CAPITAL(NativeKeyCodes.KC_CAPITAL()),
        KC_KANA(NativeKeyCodes.KC_KANA()),
        KC_HANGUEL(NativeKeyCodes.KC_HANGUEL()),
        KC_HANGUL(NativeKeyCodes.KC_HANGUL()),
        KC_JUNJA(NativeKeyCodes.KC_JUNJA()),
        KC_FINAL(NativeKeyCodes.KC_FINAL()),
        KC_HANJA(NativeKeyCodes.KC_HANJA()),
        KC_KANJI(NativeKeyCodes.KC_KANJI()),
        KC_ESCAPE(NativeKeyCodes.KC_ESCAPE()),
        KC_CONVERT(NativeKeyCodes.KC_CONVERT()),
        KC_NONCONVERT(NativeKeyCodes.KC_NONCONVERT()),
        KC_ACCEPT(NativeKeyCodes.KC_ACCEPT()),
        KC_MODECHANGE(NativeKeyCodes.KC_MODECHANGE()),
        KC_SPACE(NativeKeyCodes.KC_SPACE()),
        KC_PRIOR(NativeKeyCodes.KC_PRIOR()),
        KC_NEXT(NativeKeyCodes.KC_NEXT()),
        KC_END(NativeKeyCodes.KC_END()),
        KC_HOME(NativeKeyCodes.KC_HOME()),
        KC_LEFT(NativeKeyCodes.KC_LEFT()),
        KC_UP(NativeKeyCodes.KC_UP()),
        KC_RIGHT(NativeKeyCodes.KC_RIGHT()),
        KC_DOWN(NativeKeyCodes.KC_DOWN()),
        KC_SELECT(NativeKeyCodes.KC_SELECT()),
        KC_PRINT(NativeKeyCodes.KC_PRINT()),
        KC_EXECUTE(NativeKeyCodes.KC_EXECUTE()),
        KC_SNAPSHOT(NativeKeyCodes.KC_SNAPSHOT()),
        KC_INSERT(NativeKeyCodes.KC_INSERT()),
        KC_DELETE(NativeKeyCodes.KC_DELETE()),
        KC_HELP(NativeKeyCodes.KC_HELP()),
        KC_0(NativeKeyCodes.KC_0()),
        KC_1(NativeKeyCodes.KC_1()),
        KC_2(NativeKeyCodes.KC_2()),
        KC_3(NativeKeyCodes.KC_3()),
        KC_4(NativeKeyCodes.KC_4()),
        KC_5(NativeKeyCodes.KC_5()),
        KC_6(NativeKeyCodes.KC_6()),
        KC_7(NativeKeyCodes.KC_7()),
        KC_8(NativeKeyCodes.KC_8()),
        KC_9(NativeKeyCodes.KC_9()),
        KC_A(NativeKeyCodes.KC_A()),
        KC_B(NativeKeyCodes.KC_B()),
        KC_C(NativeKeyCodes.KC_C()),
        KC_D(NativeKeyCodes.KC_D()),
        KC_E(NativeKeyCodes.KC_E()),
        KC_F(NativeKeyCodes.KC_F()),
        KC_G(NativeKeyCodes.KC_G()),
        KC_H(NativeKeyCodes.KC_H()),
        KC_I(NativeKeyCodes.KC_I()),
        KC_J(NativeKeyCodes.KC_J()),
        KC_K(NativeKeyCodes.KC_K()),
        KC_L(NativeKeyCodes.KC_L()),
        KC_M(NativeKeyCodes.KC_M()),
        KC_N(NativeKeyCodes.KC_N()),
        KC_O(NativeKeyCodes.KC_O()),
        KC_P(NativeKeyCodes.KC_P()),
        KC_Q(NativeKeyCodes.KC_Q()),
        KC_R(NativeKeyCodes.KC_R()),
        KC_S(NativeKeyCodes.KC_S()),
        KC_T(NativeKeyCodes.KC_T()),
        KC_U(NativeKeyCodes.KC_U()),
        KC_V(NativeKeyCodes.KC_V()),
        KC_W(NativeKeyCodes.KC_W()),
        KC_X(NativeKeyCodes.KC_X()),
        KC_Y(NativeKeyCodes.KC_Y()),
        KC_Z(NativeKeyCodes.KC_Z()),
        KC_LMETA(NativeKeyCodes.KC_LMETA()),
        KC_RMETA(NativeKeyCodes.KC_RMETA()),
        KC_APPS(NativeKeyCodes.KC_APPS()),
        KC_SLEEP(NativeKeyCodes.KC_SLEEP()),
        KC_NUMPAD0(NativeKeyCodes.KC_NUMPAD0()),
        KC_NUMPAD1(NativeKeyCodes.KC_NUMPAD1()),
        KC_NUMPAD2(NativeKeyCodes.KC_NUMPAD2()),
        KC_NUMPAD3(NativeKeyCodes.KC_NUMPAD3()),
        KC_NUMPAD4(NativeKeyCodes.KC_NUMPAD4()),
        KC_NUMPAD5(NativeKeyCodes.KC_NUMPAD5()),
        KC_NUMPAD6(NativeKeyCodes.KC_NUMPAD6()),
        KC_NUMPAD7(NativeKeyCodes.KC_NUMPAD7()),
        KC_NUMPAD8(NativeKeyCodes.KC_NUMPAD8()),
        KC_NUMPAD9(NativeKeyCodes.KC_NUMPAD9()),
        KC_NUMPAD_ENTER(NativeKeyCodes.KC_NUMPAD_ENTER()),
        KC_MULTIPLY(NativeKeyCodes.KC_MULTIPLY()),
        KC_ADD(NativeKeyCodes.KC_ADD()),
        KC_SEPARATOR(NativeKeyCodes.KC_SEPARATOR()),
        KC_SUBTRACT(NativeKeyCodes.KC_SUBTRACT()),
        KC_DECIMAL(NativeKeyCodes.KC_DECIMAL()),
        KC_DIVIDE(NativeKeyCodes.KC_DIVIDE()),
        KC_F1(NativeKeyCodes.KC_F1()),
        KC_F2(NativeKeyCodes.KC_F2()),
        KC_F3(NativeKeyCodes.KC_F3()),
        KC_F4(NativeKeyCodes.KC_F4()),
        KC_F5(NativeKeyCodes.KC_F5()),
        KC_F6(NativeKeyCodes.KC_F6()),
        KC_F7(NativeKeyCodes.KC_F7()),
        KC_F8(NativeKeyCodes.KC_F8()),
        KC_F9(NativeKeyCodes.KC_F9()),
        KC_F10(NativeKeyCodes.KC_F10()),
        KC_F11(NativeKeyCodes.KC_F11()),
        KC_F12(NativeKeyCodes.KC_F12()),
        KC_F13(NativeKeyCodes.KC_F13()),
        KC_F14(NativeKeyCodes.KC_F14()),
        KC_F15(NativeKeyCodes.KC_F15()),
        KC_F16(NativeKeyCodes.KC_F16()),
        KC_F17(NativeKeyCodes.KC_F17()),
        KC_F18(NativeKeyCodes.KC_F18()),
        KC_F19(NativeKeyCodes.KC_F19()),
        KC_F20(NativeKeyCodes.KC_F20()),
        KC_F21(NativeKeyCodes.KC_F21()),
        KC_F22(NativeKeyCodes.KC_F22()),
        KC_F23(NativeKeyCodes.KC_F23()),
        KC_F24(NativeKeyCodes.KC_F24()),
        KC_NUMLOCK(NativeKeyCodes.KC_NUMLOCK()),
        KC_SCROLL(NativeKeyCodes.KC_SCROLL()),
        KC_LSHIFT(NativeKeyCodes.KC_LSHIFT()),
        KC_RSHIFT(NativeKeyCodes.KC_RSHIFT()),
        KC_LCONTROL(NativeKeyCodes.KC_LCONTROL()),
        KC_RCONTROL(NativeKeyCodes.KC_RCONTROL()),
        KC_LMENU(NativeKeyCodes.KC_LMENU()),
        KC_RMENU(NativeKeyCodes.KC_RMENU()),
        KC_BROWSER_BACK(NativeKeyCodes.KC_BROWSER_BACK()),
        KC_BROWSER_FORWARD(NativeKeyCodes.KC_BROWSER_FORWARD()),
        KC_BROWSER_REFRESH(NativeKeyCodes.KC_BROWSER_REFRESH()),
        KC_BROWSER_STOP(NativeKeyCodes.KC_BROWSER_STOP()),
        KC_BROWSER_SEARCH(NativeKeyCodes.KC_BROWSER_SEARCH()),
        KC_BROWSER_FAVORITES(NativeKeyCodes.KC_BROWSER_FAVORITES()),
        KC_BROWSER_HOME(NativeKeyCodes.KC_BROWSER_HOME()),
        KC_VOLUME_MUTE(NativeKeyCodes.KC_VOLUME_MUTE()),
        KC_VOLUME_DOWN(NativeKeyCodes.KC_VOLUME_DOWN()),
        KC_VOLUME_UP(NativeKeyCodes.KC_VOLUME_UP()),
        KC_MEDIA_NEXT_TRACK(NativeKeyCodes.KC_MEDIA_NEXT_TRACK()),
        KC_MEDIA_PREV_TRACK(NativeKeyCodes.KC_MEDIA_PREV_TRACK()),
        KC_MEDIA_STOP(NativeKeyCodes.KC_MEDIA_STOP()),
        KC_MEDIA_PLAY_PAUSE(NativeKeyCodes.KC_MEDIA_PLAY_PAUSE()),
        KC_LAUNCH_MAIL(NativeKeyCodes.KC_LAUNCH_MAIL()),
        KC_LAUNCH_MEDIA_SELECT(NativeKeyCodes.KC_LAUNCH_MEDIA_SELECT()),
        KC_LAUNCH_APP1(NativeKeyCodes.KC_LAUNCH_APP1()),
        KC_LAUNCH_APP2(NativeKeyCodes.KC_LAUNCH_APP2()),
        KC_OEM_1(NativeKeyCodes.KC_OEM_1()),
        KC_OEM_PLUS(NativeKeyCodes.KC_OEM_PLUS()),
        KC_OEM_COMMA(NativeKeyCodes.KC_OEM_COMMA()),
        KC_OEM_MINUS(NativeKeyCodes.KC_OEM_MINUS()),
        KC_OEM_PERIOD(NativeKeyCodes.KC_OEM_PERIOD()),
        KC_OEM_2(NativeKeyCodes.KC_OEM_2()),
        KC_OEM_3(NativeKeyCodes.KC_OEM_3()),
        KC_OEM_4(NativeKeyCodes.KC_OEM_4()),
        KC_OEM_5(NativeKeyCodes.KC_OEM_5()),
        KC_OEM_6(NativeKeyCodes.KC_OEM_6()),
        KC_OEM_7(NativeKeyCodes.KC_OEM_7()),
        KC_OEM_8(NativeKeyCodes.KC_OEM_8()),
        KC_OEM_102(NativeKeyCodes.KC_OEM_102()),
        KC_PROCESSKEY(NativeKeyCodes.KC_PROCESSKEY()),
        KC_PACKET(NativeKeyCodes.KC_PACKET()),
        KC_ATTN(NativeKeyCodes.KC_ATTN()),
        KC_CRSEL(NativeKeyCodes.KC_CRSEL()),
        KC_EXSEL(NativeKeyCodes.KC_EXSEL()),
        KC_EREOF(NativeKeyCodes.KC_EREOF()),
        KC_PLAY(NativeKeyCodes.KC_PLAY()),
        KC_ZOOM(NativeKeyCodes.KC_ZOOM()),
        KC_NONAME(NativeKeyCodes.KC_NONAME()),
        KC_PA1(NativeKeyCodes.KC_PA1()),
        KC_OEM_CLEAR(NativeKeyCodes.KC_OEM_CLEAR());

        private final int nativeKeyCode;

        KeyCode(final int nativeKeyCode) {
            this.nativeKeyCode = nativeKeyCode;
        }

        public int getNativeKeyCode() {
            return nativeKeyCode;
        }

        @Override
        public String toString() {
            return name() + "(" + nativeKeyCode + ")";
        }

        private static final Map<Integer, KeyCode> nativeKeyCodeMap = new HashMap<Integer, KeyCode>();

        static {
            for (final KeyCode keyCode : values()) {
                nativeKeyCodeMap.put(keyCode.nativeKeyCode, keyCode);
            }
        }

        public static KeyCode from(final int nativeKeyCode) {
            return nativeKeyCodeMap.containsKey(nativeKeyCode) ? nativeKeyCodeMap.get(nativeKeyCode) : UNDEFINED;
        }
    }

    protected GlobalKeyListener listener;
    protected boolean transitionState, altPressed, shiftPressed, ctrlPressed, extendedKey;
    protected int nativeKeyCode;

    public KeyEvent(final Object source,
                    final GlobalKeyListener listener,
                    final boolean transitionState,
                    final int nativeKeyCode,
                    final boolean altPressed,
                    final boolean shiftPressed,
                    final boolean ctrlPressed,
                    final boolean extendedKey) {
        super(source);
        this.listener = listener;
        this.transitionState = transitionState;
        this.nativeKeyCode = nativeKeyCode;
        this.altPressed = altPressed;
        this.shiftPressed = shiftPressed;
        this.ctrlPressed = ctrlPressed;
        this.extendedKey = extendedKey;
    }

    public boolean getTransitionState() {
        return transitionState;
    }

    /**
     * @return the native key code reported by the underlying system. In most
     *         cases, the value returned will map to an entry in the KeyCode
     *         enum. However, this may not occur for key events reported by the
     *         system that are OEM specific.
     */
    public int getNativeKeyCode() {
        return nativeKeyCode;
    }

    public boolean isAltPressed() {
        return altPressed;
    }

    public boolean isShiftPressed() {
        return shiftPressed;
    }

    public boolean isCtrlPressed() {
        return ctrlPressed;
    }

    public boolean isExtendedKey() {
        return extendedKey;
    }

    public boolean equals(final KeyEvent event) {
        return event.getNativeKeyCode() == nativeKeyCode && event.isExtendedKey() == extendedKey
                        && event.isAltPressed() == altPressed;
    }

    @Override
    public String toString() {
        final KeyCode keyCode = KeyCode.from(nativeKeyCode);
        final StringBuilder string = new StringBuilder().append(keyCode.toString())
                                                        .append(" [")
                                                        .append(transitionState ? "down" : "up");
        if (altPressed) {
            string.append(",alt");
        }
        if (shiftPressed) {
            string.append(",shift");
        }
        if (ctrlPressed) {
            string.append(",ctrl");
        }
        if (extendedKey) {
            string.append(",extended");
        }
        return string.append(']').toString();
    }
}