#!/bin/sh

SRC=./src/main/native

# clean
rm -f ./bin/*.so ./src/main/java/*.so

# libkeyboardhook x86
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -m32 -shared -pthread -lX11 -fPIC -o ./bin/libkeyboardhook-linux-i386.so $SRC/keyboard/KeyboardHook_X11.c $SRC/keyboard/NativeKeyCodes_X11.c

# libkeyboardhook x86_64
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -m64 -shared -pthread -lX11 -fPIC -o ./bin/libkeyboardhook-linux-amd64.so $SRC/keyboard/KeyboardHook_X11.c $SRC/keyboard/NativeKeyCodes_X11.c

