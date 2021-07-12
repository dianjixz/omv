#include<stdio.h>

#include "collections.h"
#include "imdefs.h"
#include "imlib.h"
#include "imdefs.h"

//image.find_blobs(thresholds, roi=Auto, x_stride=2, y_stride=1, invert=False, area_threshold=10, pixels_threshold=10, merge=False, margin=0, threshold_cb=None, merge_cb=None)

uint8_t *nihao(void);
int main(int argc,char * argv[])
{
    uint8_t *img_da;
    image_t img1;
    image_t_py img2;

    
    img2.data = nihao();
    
    img1.data = (uint8_t *)malloc(sizeof(img_da)/sizeof(img_da[0]));

    rgb888_to_rgb565_img(&img2,&img1);
    


	



	return 0;
}

uint8_t *nihao(void)
{
    uint8_t *ma = (uint8_t *)malloc(sizeof(im)/sizeof(im[0]));
    memcpy(ma,im,sizeof(im)/sizeof(im[0]));

    return ma;
}

// void test()
// {
//     image_t arg_img;                                     //获得图片指针
// 	printf("nihao one\r\n");


//     list_t thresholds;                                                                              //定义一个LAB阈值列表

//     list_init(&thresholds, sizeof(color_thresholds_list_lnk_data_t));                               //列表初始化
// 	printf("nihao 2\r\n");

//     // py_helper_arg_to_thresholds(args[1], &thresholds);                                              //获得参数列表
    
// 	color_thresholds_list_lnk_data_t thr;
// 	// thr = malloc(sizeof(color_thresholds_list_lnk_data_t));
// 	thr.LMin = 0;
// 	thr.LMax = 80;
// 	thr.AMin = 0;
// 	thr.AMax = 20;
// 	thr.BMin = -10;
// 	thr.BMax = 10;

// 	printf("nihao 3\r\n");
// 	printf("size:%d\r\n",thresholds.size);
// 	list_push_back(&thresholds, &thr);

// 	printf("size:%d\r\n",thresholds.size);

//  //   if (!list_size(&thresholds)) return mp_obj_new_list(0, NULL);                                   //判断列表

//     bool invert = 0;//获取invert的值

//     rectangle_t roi;
// 	roi.x = 0;
// 	roi.y = 0;
// 	roi.w = 320;
// 	roi.h = 240;
// 	printf("nihao 4\r\n");

//     unsigned int x_stride = 1;


//     unsigned int y_stride = 1;


//     unsigned int area_threshold = 1;

//     unsigned int pixels_threshold = 1;

//     bool merge = 1;

//     int margin = 0;

//     list_t out;

//     fb_alloc_mark();

// 	printf("nihao 5\r\n");

// 	uint16_t *imm = malloc(sizeof(uint16_t)*320*240);
// 	//创建图片
	
	

// 	rgb888_to_rgb565(nihao,320,240,imm);

// 	printf("rgb:%04x\r\n",imm[1]);

// 	printf("nihao 6\r\n");

// 	arg_img.w = 320;
// 	arg_img.h = 240;
// 	arg_img.bpp = IMAGE_BPP_RGB565;
// 	arg_img.data = (uint8_t*)imm;



// 	printf("nihao 7\r\n");





//         //15个参数
// /****************************/

// // &out				                list_t out                              //输出列表
// // arg_img			                    image_t *arg_img                        //传入图像

// // &roi				                rectangle_t roi;                        //感兴趣区域
// // x_stride			                unsigned int x_stride                   //x的最小值 
// // y_stride			                unsigned int y_stride                   //y方向的最小值
// // &thresholds		                    list_t thresholds;                      //LAB颜色阈值    
// // invert				                bool invert                             //是否反转感兴趣颜色
// // area_threshold	                    unsigned int area_threshold             //最小面积阈值
// // pixels_threshold	                unsigned int pixels_threshold           //最小像素阈值
// // merge				                bool merge                              //是否合并
// // margin				                int margin                              //合并边界

// // py_image_find_blobs_threshold_cb	static bool py_image_find_blobs_threshold_cb(void *fun_obj, find_blobs_list_lnk_data_t *blob)
// // //找色块阈值回调       

// // threshold_cb		                mp_obj_t threshold_cb
// // //阈值回调参数       

// // py_image_find_blobs_merge_cb        static bool py_image_find_blobs_merge_cb(void *fun_obj, find_blobs_list_lnk_data_t *blob0, find_blobs_list_lnk_data_t *blob1)
// // //找色块合并回调

// // merge_cb                            mp_obj_t merge_cb
// // //合并回调参数

// /******************************/





//     imlib_find_blobs(&out, &arg_img, &roi, x_stride, y_stride, &thresholds, invert,
//             area_threshold, pixels_threshold, merge, margin);
// 	printf("nihao 8\r\n");
	
// 	find_blobs_list_lnk_data_t lnk_blob;
// 	printf("nihao 9\r\n");


// 	printf("nihao size:%d\r\n",out.size);




    
// 	list_pop_front(&out, &lnk_blob);
	



// 	printf("nihao 10\r\n");

// 	printf("find blobs x:%i,y:%i,w:%i,h:%i\r\n",lnk_blob.rect.x,lnk_blob.rect.y,lnk_blob.rect.w,lnk_blob.rect.h);


//     // fb_alloc_free_till_mark();

//     // list_free(&thresholds);

//     // mp_obj_list_t *objects_list = mp_obj_new_list(list_size(&out), NULL);

//     // for (size_t i = 0; list_size(&out); i++) {
//     //     find_blobs_list_lnk_data_t lnk_data;
//     //     list_pop_front(&out, &lnk_data);

//     //     py_blob_obj_t *o = m_new_obj(py_blob_obj_t);
//     //     o->base.type = &py_blob_type;
//     //     o->x = mp_obj_new_int(lnk_data.rect.x);
//     //     o->y = mp_obj_new_int(lnk_data.rect.y);
//     //     o->w = mp_obj_new_int(lnk_data.rect.w);
//     //     o->h = mp_obj_new_int(lnk_data.rect.h);
//     //     o->pixels = mp_obj_new_int(lnk_data.pixels);
//     //     o->cx = mp_obj_new_int(lnk_data.centroid.x);
//     //     o->cy = mp_obj_new_int(lnk_data.centroid.y);
//     //     o->rotation = mp_obj_new_float(lnk_data.rotation);
//     //     o->code = mp_obj_new_int(lnk_data.code);
//     //     o->count = mp_obj_new_int(lnk_data.count);

//     //     objects_list->items[i] = o;
//     // }

//     // return objects_list;
// }