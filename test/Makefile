

# Obj = blob.o collections.o fb_alloc.o fmath.o xalloc.o lab_tab.o conversion.o draw.o qrcode.o yuv_tab.o

# CFAD = -lm -fPIC -shared

# target : libimg.so
# # /home/nihao/work/my_space/media/image/blob/src/img/rgb2rgb_tab.c
# # blob.so :  blob.o collections.o fb_alloc.o fmath.o xalloc.o lab_tab.o conversion.o draw.o qrcode.o
# # 	gcc blob.o collections.o fb_alloc.o fmath.o xalloc.o lab_tab.o conversion.o draw.o qrcode.o -lm -fPIC -shared -o blob.so

# libimg.so : ${Obj}
# 	gcc ${Obj} ${CFAD} -o libimg.so


# # imlib.o : ../src/img/imlib.c
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/img/imlib.c -fPIC


# blob.o : ../src/img/blob.c
# 	gcc -I ../src/img/include -I ../src/include -c ../src/img/blob.c -fPIC

# collections.o : ../src/img/collections.c
# 	gcc -I ../src/img/include -I ../src/include -c ../src/img/collections.c -fPIC

# fb_alloc.o : ../src/fb_alloc.c
# 	gcc -I ../src/img/include -I ../src/include -c ../src/fb_alloc.c -fPIC

# fmath.o : ../src/img/fmath.c
# 	gcc -I ../src/img/include -I ../src/include -c ../src/img/fmath.c -fPIC

# xalloc.o : ../src/xalloc.c
# 	gcc -I ../src/img/include -I ../src/include -c ../src/xalloc.c -fPIC


# lab_tab.o : ../src/img/lab_tab.c
# 	gcc -I ../src/img/include -I ../src/include -c ../src/img/lab_tab.c -fPIC

# conversion.o : conversion.c
# 	gcc -I ./ -c conversion.c -fPIC
# draw.o : ../src/img/draw.c
# 	gcc -I ../src/img/include -I ../src/include -c ../src/img/draw.c -fPIC

# qrcode.o : ../src/img/qrcode.c
# 	gcc -I ../src/img/include -I ../src/include -c ../src/img/qrcode.c -fPIC

# yuv_tab.o : ../src/img/yuv_tab.c
# 	gcc -I ../src/img/include -I ../src/include -c ../src/img/yuv_tab.c -fPIC



# clean : 
# 	rm -rf *.o *.so



# # rgb2rgb_tab.o : ../src/img/rgb2rgb_tab.c
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/img/rgb2rgb_tab.c -fPIC




# # target : nihao

# # nihao :  blob.o collections.o fb_alloc.o fmath.o xalloc.o test.o lab_tab.o
# # 	gcc blob.o collections.o fb_alloc.o fmath.o xalloc.o test.o lab_tab.o -lm -o nihao

# # blob.o : ../src/img/blob.c
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/img/blob.c 

# # collections.o : ../src/img/collections.c
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/img/collections.c

# # fb_alloc.o : ../src/fb_alloc.c
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/fb_alloc.c

# # fmath.o : ../src/img/fmath.c
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/img/fmath.c

# # xalloc.o : ../src/xalloc.c
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/xalloc.c 

# # test.o : test.c
# # 	gcc -I ../src/img/include -I ../src/include -c test.c

# # lab_tab.o : ../src/img/lab_tab.c
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/img/lab_tab.c





# # # gcc blob.o collections.o fb_alloc.o fmath.o xalloc.o -fPIC -shared -o blob.so

# # blob.so:
# # 	blob.o collections.o  fb_alloc.o  fmath.o  test.c  xalloc.o

# # blob.o:
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/img/blob.c -fPIC
# # collections.o:
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/img/collections.c -fPIC
# # fb_alloc.o:
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/fb_alloc.c -fPIC
# # fmath.o:
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/img/fmath.c -fPIC

# # xalloc.o:
# # 	gcc -I ../src/img/include -I ../src/include -c ../src/xalloc.c -fPIC





# # gcc -I ../src/img/include -I ../src/include -c ../src/img/blob.c -fPIC
# # gcc -I ../src/img/include -I ../src/include -c ../src/img/collections.c -fPIC
# # gcc -I ../src/img/include -I ../src/include -c ../src/fb_alloc.c -fPIC
# # gcc -I ../src/img/include -I ../src/include -c ../src/img/fmath.c -fPIC
# # gcc -I ../src/img/include -I ../src/include -c ../src/xalloc.c -fPIC
# # gcc blob.o collections.o fb_alloc.o fmath.o xalloc.o -fPIC -shared -o blob.so


# #gcc -I ../src/img/include -I ../src/include -c test.c

# # gcc test.o blob.so -o nihao -Wl,-rpath=./

# thirdparty_root := /usr/local/thirdparty
# facesdk_root := /usr/local/facesdk
# export PKG_CONFIG_PATH := ${thirdparty_root}/lib64/pkgconfig:${PKG_CONFIG_PATH}

# CC := gcc

# INCS += -I ../src/img/include
# INCS += -I ../src/include
# # INCS += `pkg-config --cflags opencv`
# # INCS += -I${facesdk_root}/include
# # INCS += -I${thirdparty_root}/include
# # INCS += -I${thirdparty_root}/include/apr-1

# LIBS += -lm
# # LIBS += `pkg-config --libs opencv`
# # LIBS +=	-L${thirdparty_root}/lib -lglog -lactivemq-cpp -lapr-1
# # LIBS +=	-L${facesdk_root}/lib -lrr_faceverify_t -lrr_facedetect_t

# AFLAGS := -Wall -c -fPIC -O2 $(INCS)
# LDFLAGS := -fPIC -shared

# # LDFLAGS += -Wl,-rpath,${thirdparty_root}/lib64:${thirdparty_root}/lib:${facesdk_root}/lib
# OBJS := imlib.c
# # OBJS := $(patsubst %.cpp,%.o,$(shell find . -name "*.cpp"))


# target : imlib.so

# ${target} : ${OBJS}





# FaceFilter: $(OBJS)
# 	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

# $(OBJS): %.o:%.cpp
# 	$(CC) $(AFLAGS) $^ -o $@

# debugOBJS:
# 	@echo ${OBJS}

# .PHONY: clean FaceFilter setenv

# clean:					
# 	rm -rf *.o FaceFilter baseutils/*.o factory/*.o message/*.o servicemodules/*.o



# #Source file
 
# SRC = imlib.c
#  #Object file
# OBJ = $(SRC:.c=.o)
 
#  #Output execution file
# PROGRAM = imlib.so
# #Compiler
# CC := gcc
# #Include
# INCLUDE =  -I ../src/img/include -I ../src/include
# #Linker Parameter
# # LINKPARAM = -lpthread -lncurses
# LINKPARAM += -lm
# LDFLAGS += -fPIC -shared
# CFLAGS = -fPIC -O -Wall
# #Options for development
# #CFLAGS = -ansi -g -Wall
# #Options for release



# all: $(PROGRAM)

# $(PROGRAM): $(OBJ)
# 	$(CC) -o $(PROGRAM) $(LINKPARAM) $(OBJ) $(LDFLAGS)

# # .SUFFIXES : .cpp
 
# .c.o:
# 	$(CC) $(INCLUDE) $(CFLAGS) -c $(../src/img/$<)

# clean:
# 	-rm *.o




CFLAGS=  
LIBS = -lm
# CC=gcc
CC=$(vgcc)
# OBJDIR=./build
project=./libimg.so
# C_SRC = $(wildcard *.c)  
C_SRC +=  ../src/img/imlib.c
C_SRC += ../src/img/blob.c
C_SRC += ../src/img/collections.c
C_SRC += ../src/fb_alloc.c
C_SRC += ../src/img/lab_tab.c
C_SRC += ../src/img/draw.c
C_SRC += ../src/img/fmath.c
C_SRC += ../src/xalloc.c
C_SRC += ./conversion.c
C_SRC += ../src/img/qrcode.c
C_SRC += ../src/img/yuv_tab.c
C_SRC += ../src/img/xyz_tab.c
C_SRC += ../src/img/rgb2rgb_tab.c
C_SRC += ../src/img/stats.c
C_SRC += ../src/img/sincos_tab.c
C_SRC += ../src/img/template.c
C_SRC += ../src/img/shadow_removal.c
C_SRC += ../src/img/selective_search.c
C_SRC += ../src/img/rectangle.c
C_SRC += ../src/img/rainbow_tab.c
C_SRC += ../src/img/qsort.c
C_SRC += ../src/img/pool.c
C_SRC += ../src/img/point.c
C_SRC += ../src/img/picojpeg.c
C_SRC += ../src/img/phasecorrelation.c
C_SRC += ../src/img/mathop.c
C_SRC += ../src/img/lsd.c
C_SRC += ../src/img/line.c
C_SRC += ../src/img/invariant_tab.c
C_SRC += ../src/img/integral.c
C_SRC += ../src/img/integral_mw.c
C_SRC += ../src/img/hough.c
C_SRC += ../src/img/hog.c
C_SRC += ../src/img/fsort.c
C_SRC += ../src/img/filter.c
C_SRC += ../src/img/eye.c
C_SRC += ../src/img/edge.c
C_SRC += ../src/img/dmtx.c
C_SRC += ../src/img/clahe.c
C_SRC += ../src/img/binary.c
C_SRC += ../src/img/apriltag.c
C_SRC += ../src/img/affine.c
C_SRC += ../src/array.c
C_SRC += ../src/umm_malloc.c
C_SRC += 
C_SRC +=
C_SRC +=
C_SRC +=
C_SRC += ../src/img/kmeans.c





INCLUDE =  -I ../src/img/include -I ../src/include -I ./

LDFLAGS += -fPIC -shared -L/opt/v831/usr/lib -L/opt/v831/lib -L/opt/v831/toolchain-sunxi-musl/toolchain/usr/lib -L/opt/v831/toolchain-sunxi-musl/toolchain/lib
CFLAGS += -fPIC -Wall




C_OBJ = $(patsubst %c, %o, $(C_SRC))  
# CPP_SRC = $(wildcard *.cpp)
CPP_SRC =  
# CPP_OBJ = $(patsubst %cpp, %o, $(CPP_SRC))  
CPP_OBJ =  

$(project): $(C_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(notdir $(C_OBJ)) $(LIBS) 
	make clean_o

%.o:%.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $<   
# %.o:%.cpp  
# 	$(CC)++ $(CFLAGS) -o $<  

clean_o:
	rm *.o
clean:  
	rm *~ *.o -f $(project) 
