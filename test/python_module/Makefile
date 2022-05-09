
# .PYTON : all

CC = /opt/v831/toolchain-sunxi-musl/toolchain/bin/arm-openwrt-linux-muslgnueabi-gcc
# CC = gcc



all : image.so

# -I/opt/v831/usr/include -I/opt/v831/toolchain-sunxi-musl/toolchain/usr/include -I/opt/v831/toolchain-sunxi-musl/toolchain/include -I/opt/v831/toolchain-sunxi-musl/toolchain/include/fortify -I/opt/v831/toolchain-sunxi-musl/toolchain/usr/include/python3.8

image.so : image.o ../libimg.so
	$(CC) image.o -lzbar -limg -lpython3.8 -o image.so -shared -fPIC -L/opt/v831/usr/lib -L/opt/v831/lib -L/opt/v831/toolchain-sunxi-musl/toolchain/usr/lib -L/opt/v831/toolchain-sunxi-musl/toolchain/lib -L./ -Wl,-rpath=/usr/lib/python3.8/site-packages/maix

image.o : image.c
	$(CC) -c image.c -I ../../src/img/include -I ../../src/include -I ../ -I../../zbar  -fPIC -I/opt/v831/usr/include -I/opt/v831/toolchain-sunxi-musl/toolchain/usr/include -I/opt/v831/toolchain-sunxi-musl/toolchain/include -I/opt/v831/toolchain-sunxi-musl/toolchain/include/fortify -I/opt/v831/usr/include/python3.8

# image_new.so : image_new.o ../libimg.so
# 	gcc image_new.o ../libimg.so -lpython3.8 -o image_new.so -shared -fPIC -Wl,-rpath=../

# image_new.o : image_new.c
# 	gcc -c image_new.c -I /usr/include/python3.8/ -I ../../src/img/include -I ../../src/include -I ../ -fPIC


clean : 
	rm -rf *.o image.so

re :
	make clean
	make
py_test :
	python3 test.py










#/home/nihao/tool/v831_toolchain_linux_x86.tar/v831/usr/include/python3.8/