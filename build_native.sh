#!/bin/sh

SRC="./src/main/native"
BIN="./bin"
LIB="./lib"
OBJ1="KeyboardHook_X11"
OBJ2="NativeKeyCodes_X11"
OBJ3="MouseHook_X11"
LIBKEYNAME=keyboardhook
LIBMOUSENAME=mousehook

clean_objects() {
  rm -f $BIN/*.o
}

# clean all output
clean_objects
rm -f $LIB/*.so src/main/java/*.lib

echo "Compiling lib$LIBKEYNAME x86"
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m32 -fPIC -o $BIN/$OBJ1.o $SRC/keyboard/$OBJ1.c
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m32 -fPIC -o $BIN/$OBJ2.o $SRC/keyboard/$OBJ2.c
gcc -shared -m32 -o $LIB/lib$LIBKEYNAME-linux-i386.so $BIN/*.o -pthread -lX11

clean_objects

echo "Compiling lib$LIBMOUSENAME x86"
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m32 -fPIC -o $BIN/$OBJ3.o $SRC/mouse/$OBJ3.c
gcc -shared -m32 -o $LIB/lib$LIBMOUSENAME-linux-i386.so $BIN/*.o -pthread -lX11


clean_objects

echo "Compiling libkeyboardhook x86_64"
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m64 -fPIC -o $BIN/$OBJ1.o $SRC/keyboard/$OBJ1.c
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m64 -fPIC -o $BIN/$OBJ2.o $SRC/keyboard/$OBJ2.c
gcc -shared -m64 -o $LIB/lib$LIBKEYNAME-linux-amd64.so $BIN/*.o -pthread -lX11

clean_objects

echo "Compiling lib$LIBMOUSENAME x86_64"
gcc -I"/usr/lib/jvm/java-7-openjdk-amd64/include" -I"/usr/lib/jvm/java-7-openjdk-amd64/include/linux" -c -m64 -fPIC -o $BIN/$OBJ3.o $SRC/mouse/$OBJ3.c
gcc -shared -m64 -o $LIB/lib$LIBMOUSENAME-linux-amd64.so $BIN/*.o -pthread -lX11


clean_objects

# copy native libraries to primary java source path
cp -f $LIB/libkeyboardhook-linux-i386.so ./src/main/java/keyboardhook-linux-i386.lib
cp -f $LIB/libkeyboardhook-linux-amd64.so ./src/main/java/keyboardhook-linux-amd64.lib
cp -f $LIB/libmousehook-linux-i386.so ./src/main/java/mousehook-linux-i386.lib
cp -f $LIB/libmousehook-linux-amd64.so ./src/main/java/mousehook-linux-amd64.lib

