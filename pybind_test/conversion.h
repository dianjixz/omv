#ifndef __CONVERSION_H__
#define __CONVERSION_H__


int rgb565_to_rgb888(const void * psrc, int w, int h, void * pdst);
int rgb888_to_rgb565(const void * psrc, int w, int h, void * pdst);

unsigned short RGB888ToRGB565(unsigned int n888Color);
unsigned int RGB565ToRGB888(unsigned short n565Color);
// void rgb_to_lab(unsigned char R, unsigned char G, unsigned char B, float *L, float *a, float *b);
// void lab_to_rgb(float L, float a, float b, unsigned char *R, unsigned char *G, unsigned char *B);


#endif