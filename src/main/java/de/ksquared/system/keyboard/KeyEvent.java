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
     * hold the same value as {@link #UNDEFINED}. The raw native key code of a
     * KeyEvent can always be accessed via KeyEvent.getNativeKeyCode().
     * 
     * @author Brian Groenke
     */
    public enum KeyCode {
        UNDEFINED(NativeKeyCodes.KC_UNDEFINED()),
        VK_LBUTTON(NativeKeyCodes.KC_LBUTTON()),
        VK_RBUTTON(NativeKeyCodes.KC_RBUTTON()),
        VK_CANCEL(NativeKeyCodes.KC_CANCEL()),
        VK_MBUTTON(NativeKeyCodes.KC_MBUTTON()),
        VK_XBUTTON1(NativeKeyCodes.KC_XBUTTON1()),
        VK_XBUTTON2(NativeKeyCodes.KC_XBUTTON2()),
        VK_BACK(NativeKeyCodes.KC_BACK()),
        VK_TAB(NativeKeyCodes.KC_TAB()),
        VK_CLEAR(NativeKeyCodes.KC_CLEAR()),
        VK_RETURN(NativeKeyCodes.KC_RETURN()),
        VK_SHIFT(NativeKeyCodes.KC_SHIFT()),
        VK_CONTROL(NativeKeyCodes.KC_CONTROL()),
        VK_MENU(NativeKeyCodes.KC_MENU()),
        VK_PAUSE(NativeKeyCodes.KC_PAUSE()),
        VK_CAPITAL(NativeKeyCodes.KC_CAPITAL()),
        VK_KANA(NativeKeyCodes.KC_KANA()),
        VK_HANGUEL(NativeKeyCodes.KC_HANGUEL()),
        VK_HANGUL(NativeKeyCodes.KC_HANGUL()),
        VK_JUNJA(NativeKeyCodes.KC_JUNJA()),
        VK_FINAL(NativeKeyCodes.KC_FINAL()),
        VK_HANJA(NativeKeyCodes.KC_HANJA()),
        VK_KANJI(NativeKeyCodes.KC_KANJI()),
        VK_ESCAPE(NativeKeyCodes.KC_ESCAPE()),
        VK_CONVERT(NativeKeyCodes.KC_CONVERT()),
        VK_NONCONVERT(NativeKeyCodes.KC_NONCONVERT()),
        VK_ACCEPT(NativeKeyCodes.KC_ACCEPT()),
        VK_MODECHANGE(NativeKeyCodes.KC_MODECHANGE()),
        VK_SPACE(NativeKeyCodes.KC_SPACE()),
        VK_PRIOR(NativeKeyCodes.KC_PRIOR()),
        VK_NEXT(NativeKeyCodes.KC_NEXT()),
        VK_END(NativeKeyCodes.KC_END()),
        VK_HOME(NativeKeyCodes.KC_HOME()),
        VK_LEFT(NativeKeyCodes.KC_LEFT()),
        VK_UP(NativeKeyCodes.KC_UP()),
        VK_RIGHT(NativeKeyCodes.KC_RIGHT()),
        VK_DOWN(NativeKeyCodes.KC_DOWN()),
        VK_SELECT(NativeKeyCodes.KC_SELECT()),
        VK_PRINT(NativeKeyCodes.KC_PRINT()),
        VK_EXECUTE(NativeKeyCodes.KC_EXECUTE()),
        VK_SNAPSHOT(NativeKeyCodes.KC_SNAPSHOT()),
        VK_INSERT(NativeKeyCodes.KC_INSERT()),
        VK_DELETE(NativeKeyCodes.KC_DELETE()),
        VK_HELP(NativeKeyCodes.KC_HELP()),
        VK_0(NativeKeyCodes.KC_0()),
        VK_1(NativeKeyCodes.KC_1()),
        VK_2(NativeKeyCodes.KC_2()),
        VK_3(NativeKeyCodes.KC_3()),
        VK_4(NativeKeyCodes.KC_4()),
        VK_5(NativeKeyCodes.KC_5()),
        VK_6(NativeKeyCodes.KC_6()),
        VK_7(NativeKeyCodes.KC_7()),
        VK_8(NativeKeyCodes.KC_8()),
        VK_9(NativeKeyCodes.KC_9()),
        VK_A(NativeKeyCodes.KC_A()),
        VK_B(NativeKeyCodes.KC_B()),
        VK_C(NativeKeyCodes.KC_C()),
        VK_D(NativeKeyCodes.KC_D()),
        VK_E(NativeKeyCodes.KC_E()),
        VK_F(NativeKeyCodes.KC_F()),
        VK_G(NativeKeyCodes.KC_G()),
        VK_H(NativeKeyCodes.KC_H()),
        VK_I(NativeKeyCodes.KC_I()),
        VK_J(NativeKeyCodes.KC_J()),
        VK_K(NativeKeyCodes.KC_K()),
        VK_L(NativeKeyCodes.KC_L()),
        VK_M(NativeKeyCodes.KC_M()),
        VK_N(NativeKeyCodes.KC_N()),
        VK_O(NativeKeyCodes.KC_O()),
        VK_P(NativeKeyCodes.KC_P()),
        VK_Q(NativeKeyCodes.KC_Q()),
        VK_R(NativeKeyCodes.KC_R()),
        VK_S(NativeKeyCodes.KC_S()),
        VK_T(NativeKeyCodes.KC_T()),
        VK_U(NativeKeyCodes.KC_U()),
        VK_V(NativeKeyCodes.KC_V()),
        VK_W(NativeKeyCodes.KC_W()),
        VK_X(NativeKeyCodes.KC_X()),
        VK_Y(NativeKeyCodes.KC_Y()),
        VK_Z(NativeKeyCodes.KC_Z()),
        VK_LMETA(NativeKeyCodes.KC_LMETA()),
        VK_RMETA(NativeKeyCodes.KC_RMETA()),
        VK_APPS(NativeKeyCodes.KC_APPS()),
        VK_SLEEP(NativeKeyCodes.KC_SLEEP()),
        VK_NUMPAD0(NativeKeyCodes.KC_NUMPAD0()),
        VK_NUMPAD1(NativeKeyCodes.KC_NUMPAD1()),
        VK_NUMPAD2(NativeKeyCodes.KC_NUMPAD2()),
        VK_NUMPAD3(NativeKeyCodes.KC_NUMPAD3()),
        VK_NUMPAD4(NativeKeyCodes.KC_NUMPAD4()),
        VK_NUMPAD5(NativeKeyCodes.KC_NUMPAD5()),
        VK_NUMPAD6(NativeKeyCodes.KC_NUMPAD6()),
        VK_NUMPAD7(NativeKeyCodes.KC_NUMPAD7()),
        VK_NUMPAD8(NativeKeyCodes.KC_NUMPAD8()),
        VK_NUMPAD9(NativeKeyCodes.KC_NUMPAD9()),
        VK_MULTIPLY(NativeKeyCodes.KC_MULTIPLY()),
        VK_ADD(NativeKeyCodes.KC_ADD()),
        VK_SEPARATOR(NativeKeyCodes.KC_SEPARATOR()),
        VK_SUBTRACT(NativeKeyCodes.KC_SUBTRACT()),
        VK_DECIMAL(NativeKeyCodes.KC_DECIMAL()),
        VK_DIVIDE(NativeKeyCodes.KC_DIVIDE()),
        VK_F1(NativeKeyCodes.KC_F1()),
        VK_F2(NativeKeyCodes.KC_F2()),
        VK_F3(NativeKeyCodes.KC_F3()),
        VK_F4(NativeKeyCodes.KC_F4()),
        VK_F5(NativeKeyCodes.KC_F5()),
        VK_F6(NativeKeyCodes.KC_F6()),
        VK_F7(NativeKeyCodes.KC_F7()),
        VK_F8(NativeKeyCodes.KC_F8()),
        VK_F9(NativeKeyCodes.KC_F9()),
        VK_F10(NativeKeyCodes.KC_F10()),
        VK_F11(NativeKeyCodes.KC_F11()),
        VK_F12(NativeKeyCodes.KC_F12()),
        VK_F13(NativeKeyCodes.KC_F13()),
        VK_F14(NativeKeyCodes.KC_F14()),
        VK_F15(NativeKeyCodes.KC_F15()),
        VK_F16(NativeKeyCodes.KC_F16()),
        VK_F17(NativeKeyCodes.KC_F17()),
        VK_F18(NativeKeyCodes.KC_F18()),
        VK_F19(NativeKeyCodes.KC_F19()),
        VK_F20(NativeKeyCodes.KC_F20()),
        VK_F21(NativeKeyCodes.KC_F21()),
        VK_F22(NativeKeyCodes.KC_F22()),
        VK_F23(NativeKeyCodes.KC_F23()),
        VK_F24(NativeKeyCodes.KC_F24()),
        VK_NUMLOCK(NativeKeyCodes.KC_NUMLOCK()),
        VK_SCROLL(NativeKeyCodes.KC_SCROLL()),
        VK_LSHIFT(NativeKeyCodes.KC_LSHIFT()),
        VK_RSHIFT(NativeKeyCodes.KC_RSHIFT()),
        VK_LCONTROL(NativeKeyCodes.KC_LCONTROL()),
        VK_RCONTROL(NativeKeyCodes.KC_RCONTROL()),
        VK_LMENU(NativeKeyCodes.KC_LMENU()),
        VK_RMENU(NativeKeyCodes.KC_RMENU()),
        VK_BROWSER_BACK(NativeKeyCodes.KC_BROWSER_BACK()),
        VK_BROWSER_FORWARD(NativeKeyCodes.KC_BROWSER_FORWARD()),
        VK_BROWSER_REFRESH(NativeKeyCodes.KC_BROWSER_REFRESH()),
        VK_BROWSER_STOP(NativeKeyCodes.KC_BROWSER_STOP()),
        VK_BROWSER_SEARCH(NativeKeyCodes.KC_BROWSER_SEARCH()),
        VK_BROWSER_FAVORITES(NativeKeyCodes.KC_BROWSER_FAVORITES()),
        VK_BROWSER_HOME(NativeKeyCodes.KC_BROWSER_HOME()),
        VK_VOLUME_MUTE(NativeKeyCodes.KC_VOLUME_MUTE()),
        VK_VOLUME_DOWN(NativeKeyCodes.KC_VOLUME_DOWN()),
        VK_VOLUME_UP(NativeKeyCodes.KC_VOLUME_UP()),
        VK_MEDIA_NEXT_TRACK(NativeKeyCodes.KC_MEDIA_NEXT_TRACK()),
        VK_MEDIA_PREV_TRACK(NativeKeyCodes.KC_MEDIA_PREV_TRACK()),
        VK_MEDIA_STOP(NativeKeyCodes.KC_MEDIA_STOP()),
        VK_MEDIA_PLAY_PAUSE(NativeKeyCodes.KC_MEDIA_PLAY_PAUSE()),
        VK_LAUNCH_MAIL(NativeKeyCodes.KC_LAUNCH_MAIL()),
        VK_LAUNCH_MEDIA_SELECT(NativeKeyCodes.KC_LAUNCH_MEDIA_SELECT()),
        VK_LAUNCH_APP1(NativeKeyCodes.KC_LAUNCH_APP1()),
        VK_LAUNCH_APP2(NativeKeyCodes.KC_LAUNCH_APP2()),
        VK_OEM_1(NativeKeyCodes.KC_OEM_1()),
        VK_OEM_PLUS(NativeKeyCodes.KC_OEM_PLUS()),
        VK_OEM_COMMA(NativeKeyCodes.KC_OEM_COMMA()),
        VK_OEM_MINUS(NativeKeyCodes.KC_OEM_MINUS()),
        VK_OEM_PERIOD(NativeKeyCodes.KC_OEM_PERIOD()),
        VK_OEM_2(NativeKeyCodes.KC_OEM_2()),
        VK_OEM_3(NativeKeyCodes.KC_OEM_3()),
        VK_OEM_4(NativeKeyCodes.KC_OEM_4()),
        VK_OEM_5(NativeKeyCodes.KC_OEM_5()),
        VK_OEM_6(NativeKeyCodes.KC_OEM_6()),
        VK_OEM_7(NativeKeyCodes.KC_OEM_7()),
        VK_OEM_8(NativeKeyCodes.KC_OEM_8()),
        VK_OEM_102(NativeKeyCodes.KC_OEM_102()),
        VK_PROCESSKEY(NativeKeyCodes.KC_PROCESSKEY()),
        VK_PACKET(NativeKeyCodes.KC_PACKET()),
        VK_ATTN(NativeKeyCodes.KC_ATTN()),
        VK_CRSEL(NativeKeyCodes.KC_CRSEL()),
        VK_EXSEL(NativeKeyCodes.KC_EXSEL()),
        VK_EREOF(NativeKeyCodes.KC_EREOF()),
        VK_PLAY(NativeKeyCodes.KC_PLAY()),
        VK_ZOOM(NativeKeyCodes.KC_ZOOM()),
        VK_NONAME(NativeKeyCodes.KC_NONAME()),
        VK_PA1(NativeKeyCodes.KC_PA1()),
        VK_OEM_CLEAR(NativeKeyCodes.KC_OEM_CLEAR());

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