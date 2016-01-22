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
 * Copyright 2011 Kristian Kraljic, Johannes Sch���th 2008. All rights reserved.
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
 * or implied, of Kristian Kraljic and Johannes Sch���th.
 */

package de.ksquared.system.keyboard;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

import de.ksquared.system.keyboard.KeyEvent.KeyCode;

class KeyboardHook {

    private boolean altPressed, shiftPressed, ctrlPressed, extendedKey;

    List<KeyEvent> buffer = Collections.synchronizedList(new LinkedList<KeyEvent>());
    private final EventProcedure procedure = new EventProcedure(this);

    public KeyboardHook() {
        if (Native.load()) {
            procedure.start();
        } else {
            throw new RuntimeException("failed to load native libraries.");
        }
    }

    void processKey(final boolean transitionState, final int nativeKeyCode, final GlobalKeyListener listener) {
        processControlKeys(transitionState, nativeKeyCode);
        buffer.add(new KeyEvent(this,
                                listener,
                                transitionState,
                                nativeKeyCode,
                                altPressed,
                                shiftPressed,
                                ctrlPressed,
                                extendedKey));
    }

    native void registerHook(GlobalKeyListener listener);

    native void unregisterHook();

    void processControlKeys(final boolean transitionState, final int nativeKeyCode) {
        final KeyCode keyCode = KeyCode.from(nativeKeyCode);
        switch (keyCode) {
        case VK_RMETA:
            extendedKey = transitionState;
            break;
        case VK_RMENU:
            extendedKey = transitionState;
        case VK_MENU:
        case VK_LMENU:
            altPressed = transitionState;
            break;
        case VK_RSHIFT:
            extendedKey = transitionState;
        case VK_SHIFT:
        case VK_LSHIFT:
            shiftPressed = transitionState;
            break;
        case VK_RCONTROL:
            extendedKey = transitionState;
        case VK_CONTROL:
        case VK_LCONTROL:
            ctrlPressed = transitionState;
            break;
        default:
        }
    }
}