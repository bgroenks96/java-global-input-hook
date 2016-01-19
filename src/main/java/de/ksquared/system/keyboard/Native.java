/*
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

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class Native {

    private static Boolean loaded = null;

    static boolean load() {
        if (loaded != null) return loaded == Boolean.TRUE;

        final String libpath = System.getProperty("de.ksquared.system.keyboard.lib.path");
        String libname = System.getProperty("de.ksquared.system.keyboard.lib.name");
        if (libname == null) {
            libname = System.mapLibraryName("keyboardhook");
        }
        try {
            if (libpath == null) {
                System.loadLibrary("keyboardhook");
            } else {
                System.load(new File(libpath, libname).getAbsolutePath());
            }
            return loaded = Boolean.TRUE;
        } catch (final UnsatisfiedLinkError e) { /* do nothing, try next */ }

        String osname = System.getProperty("os.name").toLowerCase(), osarch = System.getProperty("os.arch");
        if (osname.startsWith("mac os")) {
            osname = "mac";
            osarch = "universal";
        } else if (osname.startsWith("windows")) {
            osname = "win";
        } else if (osname.startsWith("sunos")) {
            osname = "solaris";
        }
        if (osarch.startsWith("i") && osarch.endsWith("86")) {
            osarch = "x86";
        }
        libname = "keyboardhook-" + osname + '-' + osarch + ".lib";
        try {
            final InputStream input = Native.class.getClassLoader().getResourceAsStream(libname);
            if (input == null) throw new Exception("libname: " + libname + " not found");
            final File temp = File.createTempFile("keyboardhook-", ".lib");
            temp.deleteOnExit();
            final OutputStream out = new FileOutputStream(temp);
            final byte[] buffer = new byte[1024];
            int read;
            while ((read = input.read(buffer)) != -1) {
                out.write(buffer, 0, read);
            }
            input.close();
            out.close();
            System.load(temp.getAbsolutePath());
            return loaded = Boolean.TRUE;
        } catch (final Exception e) { /* do nothing, go on */ }
        return loaded = Boolean.FALSE;
    }
}