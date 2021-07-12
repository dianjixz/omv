#!/bin/bash
source /home/nihao/tool/v831_toolchain_linux_x86.tar/v831/envsetup.sh
cd ..
gcc -I ../src/img/include -I ../src/include -c ../src/img/blob.c -fPIC
gcc -I ../src/img/include -I ../src/include -c ../src/img/collections.c -fPIC
gcc -I ../src/img/include -I ../src/include -c ../src/fb_alloc.c -fPIC
gcc -I ../src/img/include -I ../src/include -c ../src/img/fmath.c -fPIC
gcc -I ../src/img/include -I ../src/include -c ../src/xalloc.c -fPIC
gcc -I ../src/img/include -I ../src/include -c ../src/img/lab_tab.c -fPIC
gcc -I ./ -c conversion.c -fPIC
gcc -I ../src/img/include -I ../src/include -c ../src/img/draw.c -fPIC
gcc blob.o collections.o fb_alloc.o fmath.o xalloc.o lab_tab.o conversion.o draw.o -lm -fPIC -shared -o blob.so



cd -
cp ../blob.so .

gcc -c image.c -I /home/nihao/tool/v831_toolchain_linux_x86.tar/v831/usr/include/python3.8/ -I ../../src/img/include -I ../../src/include -I ../ -fPIC
gcc image.o ./blob.so -lpython3.8 -o image.so -shared -fPIC -Wl,-rpath=./

exit 0




