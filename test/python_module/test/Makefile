keywdarg.so : keywdarg.o
	gcc keywdarg.o -lpython3.8 -o keywdarg.so -shared -fPIC

keywdarg.o : keywdarg.c
	gcc -c keywdarg.c -I /usr/include/python3.8/ -fPIC

clean : 
	rm -rf *.o *.so