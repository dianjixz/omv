#!/usr/bin/env python3
import ctypes as cy
libimg = cy.cdll.LoadLibrary("./libimg.so") 

from PIL import Image
img = Image.open("/home/nihao/图片/nihao.png")

w = img.width
h = img.height
img_da = img.tobytes()

# typedef struct image {
#     int w;
#     int h;
#     int bpp;
#     union {
#         uint8_t *pixels;
#         uint8_t *data;
#     };
# 	uint8_t *pix_ai;	//for MAIX AI speed up
# } __attribute__((aligned(8)))image_t;


img_arr = cy.c_byte * len(img_da)								#uint8_t img_arr
img_data = img_arr.from_buffer_copy(img_da)						#img_arr = []		初始化数据





class image_t(cy.Structure):
	_fields_ = [("w", 	cy.c_int),\
				("h", 	cy.c_int),\
				("bpp",	cy.c_int),\
				("data",cy.POINTER(cy.c_uint8)),\
				("pix_ai",cy.POINTER(cy.c_uint8))]


arg_img = image_t()
arg_img.w = w
arg_img.h = h
arg_img.bpp = 2





PIC_UINT8_P = cy.POINTER(cy.c_uint8))

arg_img.data = PIC_UINT8_P()









# arg_img.data = cy.cast(cy.pointer(img_data),cy.c_ubyte)			
# arg_img.data = cy.pointer(img_data)
arg_img.data = cy.cast(cy.pointer(img_data),cy.POINTER(cy.c_ubyte))






#imlib_draw_line(&arg_img,x0,y0,x1,y1,c,thickness);