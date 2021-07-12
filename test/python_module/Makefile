
# .PYTON : all

all : image.so image_new.so


image.so : image.o ../libimg.so
	gcc image.o -L../ -limg -lpython3.8 -o image.so -shared -fPIC -Wl,-rpath=../

image.o : image.c
	gcc -c image.c -I /usr/include/python3.8/ -I ../../src/img/include -I ../../src/include -I ../ -fPIC

image_new.so : image_new.o ../libimg.so
	gcc image_new.o ../libimg.so -lpython3.8 -o image_new.so -shared -fPIC -Wl,-rpath=../

image_new.o : image_new.c
	gcc -c image_new.c -I /usr/include/python3.8/ -I ../../src/img/include -I ../../src/include -I ../ -fPIC


clean : 
	rm -rf *.o image.so image_new.so

re :
	make clean
	make
py_test :
	python3 test.py










#/home/nihao/tool/v831_toolchain_linux_x86.tar/v831/usr/include/python3.8/