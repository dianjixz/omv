CFLAGS=  
LIBS = -lm
CC=$(vgcc)
# CC = gcc
# OBJDIR=./build
project=./libzbar.so
# C_SRC = $(wildcard *.c)  
C_SRC += bch15_5.c 
C_SRC += binarize.c  
C_SRC += decoder.c  
C_SRC += error.c  
C_SRC += image.c  
C_SRC += img_scanner.c  
C_SRC += isaac.c  
C_SRC += qrdec.c  
C_SRC += qrdectxt.c   
C_SRC += rs.h       
C_SRC += symbol.c  
C_SRC += util.c  
C_SRC += qr_finder.c  
C_SRC += refcnt.c     
C_SRC += rs.c      
C_SRC += scanner.c

INCLUDE = -I ./

LDFLAGS += -fPIC -shared
CFLAGS += -fPIC -Wall


# -L/opt/v831/usr/lib -L/opt/v831/lib -L/opt/v831/toolchain-sunxi-musl/toolchain/usr/lib -L/opt/v831/toolchain-sunxi-musl/toolchain/lib

C_OBJ = $(patsubst %c, %o, $(C_SRC))  
# CPP_SRC = $(wildcard *.cpp)
CPP_SRC =  
# CPP_OBJ = $(patsubst %cpp, %o, $(CPP_SRC))  
CPP_OBJ =  

$(project): $(C_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(notdir $(C_OBJ)) $(LIBS) -shared 
	make clean_o

%.o:%.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $<   
# %.o:%.cpp  
# 	$(CC)++ $(CFLAGS) -o $<  

clean_o:
	rm *.o
clean:  
	rm *~ *.o -f $(project) 






