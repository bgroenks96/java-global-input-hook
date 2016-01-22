#!/bin/sh

SRC="./src/main/native"
BIN="./bin"
OBJ1="KeyboardHook_X11"
OBJ2="NativeKeyCodes_X11"
LIBNAME=keyboardhook

# clean
rm -f $BIN/*.so ./$BIN/*.o ./src/main/java/*.lib

echo "Compiling libkeyboardhook x86"
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m32 -fPIC -o $BIN/$OBJ1.o $SRC/keyboard/$OBJ1.c
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m32 -fPIC -o $BIN/$OBJ2.o $SRC/keyboard/$OBJ2.c
gcc -shared -m32 -o ./bin/lib$LIBNAME-linux-i386.so $BIN/*.o -pthread -lX11

rm -f $BIN/*.o

echo "Compiling libkeyboardhook x86_64"
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m64 -fPIC -o $BIN/$OBJ1.o $SRC/keyboard/$OBJ1.c
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m64 -fPIC -o $BIN/$OBJ2.o $SRC/keyboard/$OBJ2.c
gcc -shared -m64 -o ./bin/lib$LIBNAME-linux-amd64.so $BIN/*.o -pthread -lX11

rm -f $BIN/*.o

cp -f ./bin/libkeyboardhook-linux-i386.so ./src/main/java/keyboardhook-linux-i386.lib
cp -f ./bin/libkeyboardhook-linux-amd64.so ./src/main/java/keyboardhook-linux-amd64.lib

