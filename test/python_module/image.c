#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "collections.h"
#include "imdefs.h"
#include "imlib.h"

#include "conversion.h"


// #define pyNULL Py_INCREF(Py_None), Py_None


// image_t arg_img;                                     //获得图片指针
// list_t thresholds;                                                                              //定义一个LAB阈值列表
// color_thresholds_list_lnk_data_t thr;
// void init()
// {
// 	list_init(&thresholds, sizeof(color_thresholds_list_lnk_data_t));                               //列表初始化
// 	fb_alloc_mark();
// }



// PyTypeObject PyLong_Type nihao;








// static PyObject *
// keywdarg_parrot(PyObject *self, PyObject *args, PyObject *keywds)
// {
//     int voltage;
//     const char *state = "a stiff";
//     const char *action = "voom";
//     const char *type = "Norwegian Blue";

//     static char *kwlist[] = {"voltage", "state", "action", "type", NULL};

//     if (!PyArg_ParseTupleAndKeywords(args, keywds, "i|sss", kwlist,
//                                      &voltage, &state, &action, &type))
//         return NULL;

//     printf("-- This parrot wouldn't %s if you put %i Volts through it.\n",
//            action, voltage);
//     printf("-- Lovely plumage, the %s -- It's %s!\n", type, state);

    // Py_RETURN_NONE;
// }
image_t arg_img;                               //获得图片指针

static PyObject *
python_send_to_c_image(PyObject *self, PyObject *args, PyObject* keywds)
{

	PyObject *img_bytes;
	int w,h;
	static char *kwlist[] = {"img_bytes","w","h", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "Oii", kwlist,
                              &img_bytes,&w,&h)) return NULL;
	
	if(!PyBytes_Check(img_bytes)) return NULL;
	uint8_t *bys;
	bys = PyBytes_AsString(img_bytes);
	arg_img.data = (uint8_t *)malloc(w * h * 2);
	rgb888_to_rgb565(bys,w,h,arg_img.data);

	uint8_t cha;
	unsigned short *nihao;
	nihao = (unsigned short *)arg_img.data;
	for (int i = 0;i<w*h;i++)
	{
		cha = nihao[i];
		nihao[i] = nihao[i] >> 8;
		nihao[i] |= cha << 8;
	}
	arg_img.h = h;
	arg_img.w = w;
	arg_img.bpp = IMAGE_BPP_RGB565;
	return PyLong_FromLong(0);
}

static PyObject *
py_img_close(PyObject *self, PyObject *args)
{
	free(arg_img.data);
	return PyLong_FromLong(0);
}




static PyObject *
py_img_back_rgb888(PyObject *self, PyObject *args)
{
	PyObject *data1;
	uint8_t *_888_data ;
	_888_data = (uint8_t *)malloc(arg_img.w * arg_img.h * 3);
	uint8_t cha;
	unsigned short *nihao;
	nihao = (unsigned short *)arg_img.data;
	for (int i = 0;i<arg_img.w*arg_img.h;i++)
	{
		cha = nihao[i];
		nihao[i] = nihao[i] >> 8;
		nihao[i] |= cha << 8;
	}
	rgb565_to_rgb888(arg_img.data,arg_img.w,arg_img.h,_888_data);

	data1 = PyBytes_FromStringAndSize(_888_data,arg_img.w * arg_img.h * 3);
	free(_888_data);
	// Py_INCREF(data1);
	return data1;

}

// static PyObject *
// py_image_to_grayscale(PyObject *self, PyObject *args, PyObject* keywds)
// {
//     image_t *arg_img = py_helper_arg_to_image_mutable(args[0]);
//     bool copy = py_helper_keyword_int(n_args, args, 1, kw_args, MP_OBJ_NEW_QSTR(MP_QSTR_copy), false);




	

//     MSGLOG("nihao ,can you see me four?\r\n");
//     image_t out;
//     out.w = arg_img->w;
//     out.h = arg_img->h;
//     out.bpp = IMAGE_BPP_GRAYSCALE;
//     out.data = copy ? xalloc(image_size(&out)) : arg_img->data;
//     out.pix_ai = copy ? xalloc(out.w*out.h*3) : arg_img->pix_ai;

//     switch(arg_img->bpp) {
//         case IMAGE_BPP_BINARY: {
//             PY_ASSERT_TRUE_MSG((out.w == 1) || copy,
//                                "Can't convert to grayscale in place!");
//             for (int y = 0, yy = out.h; y < yy; y++) {
//                 uint32_t *row_ptr = IMAGE_COMPUTE_BINARY_PIXEL_ROW_PTR(arg_img, y);
//                 uint8_t *out_row_ptr = IMAGE_COMPUTE_GRAYSCALE_PIXEL_ROW_PTR(&out, y);
//                 for (int x = 0, xx = out.w; x < xx; x++) {
//                     IMAGE_PUT_GRAYSCALE_PIXEL_FAST(out_row_ptr, x,
//                         COLOR_BINARY_TO_GRAYSCALE(IMAGE_GET_BINARY_PIXEL_FAST(row_ptr, x)));
//                 }
//             }
//             break;
//         }
//         case IMAGE_BPP_GRAYSCALE: {
//             if (copy) memcpy(out.data, arg_img->data, image_size(&out));
//             break;
//         }
//         case IMAGE_BPP_RGB565: {
//             for (int y = 0, yy = out.h; y < yy; y++) {
//                 uint16_t *row_ptr = IMAGE_COMPUTE_RGB565_PIXEL_ROW_PTR(arg_img, y);
//                 uint8_t *out_row_ptr = IMAGE_COMPUTE_GRAYSCALE_PIXEL_ROW_PTR(&out, y);
//                 for (int x = 0, xx = out.w; x < xx; x++) {
//                     IMAGE_PUT_GRAYSCALE_PIXEL_FAST(out_row_ptr, x,
//                         COLOR_RGB565_TO_GRAYSCALE(IMAGE_GET_RGB565_PIXEL_FAST(row_ptr, x)));
//                 }
//             }
//             break;
//         }
//         default: {
//             break;
//         }
//     }

//     if (!copy)
//     {
//         arg_img->bpp = out.bpp;
//         if(is_img_data_in_main_fb(out.data))
//         {
//             MAIN_FB()->bpp = out.bpp;
//         }
//     }

//     return py_image_from_struct(&out);
// }

































static PyObject *
py_draw_line(PyObject *self, PyObject *args, PyObject* keywds)
{
	int x0;
	int y0;
	int x1;
	int y1;
	int c = 0xffffff;
	int thickness = 1;
	
	static char *kwlist[] = {"x0","y0","x1","y1","c","thickness", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "iiii|ii", kwlist,
                              &x0,&y0,&x1,&y1,&c,&thickness)) return NULL;
	printf("thickness:%d\r\n",thickness);
	imlib_draw_line(&arg_img,x0,y0,x1,y1,c,thickness);
	return PyLong_FromLong(0);
}


// void imlib_draw_rectangle(image_t *img, int rx, int ry, int rw, int rh, int c, int thickness, bool fill)

static PyObject *
py_draw_rectangle(PyObject *self, PyObject *args, PyObject* keywds)
{
	PyObject *fil;
	int rx;
	int ry;
	int rw ;
	int rh;
	int c = 0xffffff;
	int thickness = 1;
	bool fill;
	static char *kwlist[] = {"rx","ry","rw","rh","c","thickness","fill", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "iiii|iiO", kwlist,
                              &rx,&ry,&rw,&rh,&c,&thickness,&fil)) return NULL;

	if(fil == Py_True) fill = 1;else fill = 0;


	imlib_draw_rectangle(&arg_img, rx, ry, rw, rh, c, thickness, fill);

	return PyLong_FromLong(0);
}













/*
import image
image.send_to_image([])
image.find_blobs([(0,   80,  -70,   -10,   -0,   30)],roi=[], x_stride=2, y_stride=1, invert=False, area_threshold=10, pixels_threshold=10, merge=False, margin=0)
*/
static PyObject *
py_find_blobs(PyObject *self, PyObject *args, PyObject* keywds)
{
	struct RECE_STA
	{
		PyObject *thresholds;
		PyObject *roi;
		int x_stride ;
		int y_stride ;
		PyObject *invert;
		int area_threshold ;
		int pixels_threshold ;
		PyObject *merge;
		int margin ;
	} rece_sta;
	PyObject *thr;
	PyObject *thr2;
	PyObject *thr3;


// list_t *out, image_t *ptr, rectangle_t *roi, unsigned int x_stride, unsigned int y_stride,
//                      list_t *thresholds, bool invert, unsigned int area_threshold, unsigned int pixels_threshold,
//                      bool merge, int margin


	list_t out;					//定义输出列表
	list_t thresholds;   //定义一个LAB阈值列表
	list_init(&thresholds, sizeof(color_thresholds_list_lnk_data_t)); //列表初始化
	color_thresholds_list_lnk_data_t thrm;								
	rectangle_t roi;		//定义感兴趣区域
	bool invert;			//反相标志
	bool merge;				//合并标志

	find_blobs_list_lnk_data_t lnk_blob;

	static char *kwlist[] = {"thresholds", "roi", "x_stride", "y_stride","invert","area_threshold","pixels_threshold","merge","margin", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|OiiOiiOi", kwlist,
                              &rece_sta.thresholds,   &rece_sta.roi,  &rece_sta.x_stride,  &rece_sta.y_stride,  &rece_sta.invert, &rece_sta.area_threshold, &rece_sta.pixels_threshold,  &rece_sta.merge, &rece_sta.margin)) return NULL;

	if(!PyList_Check(rece_sta.thresholds)) return NULL;
	if(!PyList_Check(rece_sta.roi)) return NULL;
	if(!PyBool_Check(rece_sta.invert)) return NULL;
	if(!PyBool_Check(rece_sta.merge)) return NULL;

	fb_alloc_mark();						//未知函数,暂时先调用
	int thr_len;
	int thrs;
	thr_len = PyList_Size(rece_sta.thresholds);
	if(thr_len == 0) return PyList_New(0);		//检查传递阈值
	for(int i=0;i<thr_len;i++)
	{
		thr = PyList_GetItem(rece_sta.thresholds,i);
		if(!PyTuple_Check(thr)) return NULL;
		thrs = PyTuple_Size(thr);
		if(thrs != 6) return NULL;
		thr2 = PyTuple_GetItem(thr,0);thrm.LMin = PyLong_AsLong(thr2);
		thr2 = PyTuple_GetItem(thr,1);thrm.LMax = PyLong_AsLong(thr2);
		thr2 = PyTuple_GetItem(thr,2);thrm.AMin = PyLong_AsLong(thr2);
		thr2 = PyTuple_GetItem(thr,3);thrm.AMax = PyLong_AsLong(thr2);
		thr2 = PyTuple_GetItem(thr,4);thrm.BMin = PyLong_AsLong(thr2);
		thr2 = PyTuple_GetItem(thr,5);thrm.BMax = PyLong_AsLong(thr2);
		// printf("lmin:%d,lmax:%d,amin:%d,amax:%d,bmin:%d,bmax:%d\r\n",thrm.LMin,thrm.LMax,thrm.AMin,thrm.AMax,thrm.BMin,thrm.BMax);
		list_push_back(&thresholds, &thrm);
	}
	thr_len = PyList_Size(rece_sta.roi);
	if(thr_len == 0)
	{
		roi.x = 0;
		roi.y = 0;
		roi.w = arg_img.w;
		roi.h = arg_img.h;
	}
	else if(thr_len == 4)
	{
		thr = PyList_GetItem(rece_sta.roi,0);roi.x = PyLong_AsLong(thr);
		thr = PyList_GetItem(rece_sta.roi,1);roi.y = PyLong_AsLong(thr);
		thr = PyList_GetItem(rece_sta.roi,2);roi.w = PyLong_AsLong(thr);
		thr = PyList_GetItem(rece_sta.roi,3);roi.h = PyLong_AsLong(thr);
	}
	else
	{
		return NULL;
	}

	if(rece_sta.invert == Py_True) invert = 1;else invert = 0;

	if(rece_sta.merge == Py_True) merge = 1;else merge = 0;


	imlib_find_blobs(&out, &arg_img, &roi, rece_sta.x_stride, rece_sta.y_stride, &thresholds, invert,
            rece_sta.area_threshold, rece_sta.pixels_threshold, merge, rece_sta.margin);
	


	thr = PyList_New(0);
	Py_INCREF(thr);
	
	while (out.size > 0)
	{
		list_pop_front(&out, &lnk_blob);

		thr2 = PyDict_New();
		Py_INCREF(thr2);
		//目前并不清楚这里需不需要加上引用,后期可以选择在这里优化一下
		thr3 = PyLong_FromLong(lnk_blob.rect.x);Py_INCREF(thr3);PyDict_SetItemString(thr2,"x",thr3);
		thr3 = PyLong_FromLong(lnk_blob.rect.y);Py_INCREF(thr3);PyDict_SetItemString(thr2,"y",thr3);
		thr3 = PyLong_FromLong(lnk_blob.rect.w);Py_INCREF(thr3);PyDict_SetItemString(thr2,"w",thr3);
		thr3 = PyLong_FromLong(lnk_blob.rect.h);Py_INCREF(thr3);PyDict_SetItemString(thr2,"h",thr3);

		thr3 = PyLong_FromLong(lnk_blob.pixels);Py_INCREF(thr3);PyDict_SetItemString(thr2,"pixels",thr3);
		thr3 = PyLong_FromLong(lnk_blob.centroid.x);Py_INCREF(thr3);PyDict_SetItemString(thr2,"cx",thr3);
		thr3 = PyLong_FromLong(lnk_blob.centroid.y);Py_INCREF(thr3);PyDict_SetItemString(thr2,"cy",thr3);
		thr3 = PyFloat_FromDouble(lnk_blob.rotation);Py_INCREF(thr3);PyDict_SetItemString(thr2,"rotation",thr3);
		thr3 = PyLong_FromLong(lnk_blob.code);Py_INCREF(thr3);PyDict_SetItemString(thr2,"code",thr3);
		thr3 = PyLong_FromLong(lnk_blob.count);Py_INCREF(thr3);PyDict_SetItemString(thr2,"count",thr3);
		PyList_Append(thr,thr2);
	}
	return thr;
}

char* _mf_qr_scan_pic(uint8_t *pic, uint16_t w, uint16_t h);





static PyObject *
python_find_qr(PyObject *self, PyObject *args, PyObject* keywds)
{
		
	image_t qr_img; 
	PyObject *img_bytes;
	int w,h;
	static char *kwlist[] = {"img_bytes","w","h", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "Oii", kwlist,
                              &img_bytes,&w,&h)) return NULL;
	
	if(!PyBytes_Check(img_bytes)) return NULL;
	uint8_t *bys;
	
	bys = PyBytes_AsString(img_bytes);
	qr_img.data = (uint8_t *)malloc(w * h);
	
	memcpy(qr_img.data,bys,w * h);



	// rgb888_to_rgb565(bys,w,h,qr_img.data);
	// uint8_t cha;
	// unsigned short *nihao;
	// nihao = (unsigned short *)qr_img.data;
	// for (int i = 0;i<w*h;i++)
	// {
	// 	cha = nihao[i];
	// 	nihao[i] = nihao[i] >> 8;
	// 	nihao[i] |= cha << 8;
	// }
	arg_img.h = h;
	arg_img.w = w;
	arg_img.bpp = IMAGE_BPP_RGB565;

	char *datas;
	datas = _mf_qr_scan_pic(qr_img.data,w,h);


	if(datas!=NULL)
	{
		PyObject *ret = PyBytes_FromStringAndSize(datas,strlen(datas));
		free(datas);
		free(qr_img.data);
		return ret;
	}
	else
	{
		free(qr_img.data);
		return PyBytes_FromFormat("no qr");
	}
}

















// py_img_back


static PyMethodDef imageMethods[] = {
    {"send_to_image",  python_send_to_c_image, METH_VARARGS | METH_KEYWORDS, "python to c module image!"},
	{"close",py_img_close, METH_VARARGS, "close image!"},
	{"find_blobs",  (PyCFunction)py_find_blobs, METH_VARARGS | METH_KEYWORDS, "find blob !"},
	{"img_back_rgb888",  (PyCFunction)py_img_back_rgb888, METH_VARARGS, "back an rgb888 img !"},
	{"draw_line",  (PyCFunction)py_draw_line, METH_VARARGS | METH_KEYWORDS, "img draw line"},
	{"draw_rectangle",  (PyCFunction)py_draw_rectangle, METH_VARARGS | METH_KEYWORDS, "img draw rectangle"},
	{"find_qr",  (PyCFunction)python_find_qr, METH_VARARGS | METH_KEYWORDS, "img draw rectangle"},





    {NULL, NULL, 0, NULL}        /* Sentinel */
};


static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "image",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    imageMethods
};

PyMODINIT_FUNC
PyInit_image(void)
{
    return PyModule_Create(&spammodule);
}






#include "zbar.h"







char* _mf_qr_scan_pic(uint8_t *pic, uint16_t w, uint16_t h )
{
    /* 先申请内存，如果失败则直接返回 */
    // uint8_t *gray = malloc(w * h);
    // if (!gray)
    // {
    //     printk("malloc failed %s:%d\r\n", __func__, __LINE__);
    //     return 0;
    // }

    /* 转换图像的字节序 */
    // if(convert) qrcode_convert_order(pic,w,h);
    // /* 将图像转换为灰度 */
    // qrcode_convert_to_gray(pic, w, h, gray);

    /* 开始调用Zbar进行扫码 */
    /* create a reader */
    zbar_image_scanner_t *scanner = zbar_image_scanner_create();
    /* configure the reader */
    zbar_image_scanner_set_config(scanner, 0, ZBAR_CFG_ENABLE, 1);
    /* wrap image data */
    zbar_image_t *image = zbar_image_create();
    zbar_image_set_format(image, *(int *)"Y800");
    zbar_image_set_size(image, w, h);
    zbar_image_set_data(image, pic, w * h, NULL); //zbar_image_free_data
    /* scan the image for barcodes */
    int qrcode_num = zbar_scan_image(scanner, image);
    /* extract results */
    const zbar_symbol_t *symbol = zbar_image_first_symbol(image);
	char *dats;
	char *datk;
	size_t dalin = 0;


    /* 如果有多个二维码，会把最后一个结果返回 */
    for (; symbol; symbol = zbar_symbol_next(symbol))
    {
        /* do something useful with results */
        zbar_symbol_type_t typ = zbar_symbol_get_type(symbol);
        const char *data = zbar_symbol_get_data(symbol);
        size_t len = strlen(data);
        printf("\r\ndecoded symbol: %s, content: \"%s\", len = %ld\r\n", zbar_get_symbol_name(typ), data, len);
		dats = data;
		dalin = len;
        // /* 拷贝到结果 */
        // if (len < 8896)
        // {
        //     memcpy(qrcode, data, len);
        //     qrcode[len] = 0;
        // }
        // else
        // {
        //     /* 这里溢出了,就不进行拷贝 */
        //     qrcode_num = 0;
        // }
    }
	if(dalin == 0)
	{
		zbar_image_destroy(image);
    	zbar_image_scanner_destroy(scanner);
		return NULL;
	}

	printf("da len:%d\r\n",dalin);
	datk = (char*)malloc(dalin + 1);
	memcpy(datk,dats,dalin);
	datk[dalin] = '\0';

    /* clean up */
    zbar_image_destroy(image);
    zbar_image_scanner_destroy(scanner);
    // if(convert) qrcode_convert_order(pic,w,h);
	

    return datk;
}






















// #define Py_RETURN_NONE return Py_INCREF(Py_None), Py_None




// static PyObject* pymod_func(PyObject* self, PyObject* args, PyObject* kwargs) {
//   static char* keywords[] = {"k1", "k2", "k3", "k4", NULL};

//   PyObject *arg1, *arg2, *k1, *k4
//   PyObject *arr1, *arr2, *karr1;
//   double *k3;
//   int *k2;
//   PyArg_ParseTupleAndKeywords(args, kwargs, "O!|O!OidO", keywords, &arg1, &PyArray_Type, &arg2, &PyArray_Type, &k1, &PyArray_Type, &k2, &k3, &k4);

//   arr1 = PyArray_FROM_OTF(arg1, NPY_FLOAT64, NPY_ARRAY_INOUT_ARRAY);
//   if (arr1 == NULL) return NULL;

//   arr2 = PyArray_FROM_OTF(arg1, NPY_FLOAT64, NPY_ARRAY_INOUT_ARRAY);
//   // no null check, because optional

//   karr1 = PyArray_FROM_OTF(k1, NPY_FLOAT64, NPY_ARRAY_INOUT_ARRAY);
//   // again, no null check, because this is optional

//   // do things with k3, k2, and k4 also

//   return NULL;
// }













	// color_thresholds_list_lnk_data_t test;
	// while (thresholds.size >0)
	// {
	// 	list_pop_front(&thresholds,&test);
	// 	printf("lmin:%d,lmax:%d,amin:%d,amax:%d,bmin:%d,bmax:%d\r\n",test.LMin,test.LMax,test.AMin,test.AMax,test.BMin,test.BMax);
	// }
	// printf("x_stride:%d,y_stride:%d,area_threshold:%d,pixels_threshold:%d,margin:%d\r\n",rece_sta.x_stride,rece_sta.y_stride,rece_sta.area_threshold,rece_sta.pixels_threshold,rece_sta.margin);
	// if(invert) printf("invert is 1\r\n"); else printf("invert is 0\r\n");
	// if(merge) printf("merge is 1\r\n"); else printf("merge is 0\r\n");
	// printf("roi_x:%d,roi_y:%d\r\n",roi.x,roi.y);


// static PyObject * 
// py_image_resize(PyObject *self, PyObject *args, PyObject* keywds)
// {


// 	image_t* img = &arg_img;
// 	int w ;
// 	int h ;
// 	int w0 = img->w;
// 	int h0 = img->h;

// 	static char *kwlist[] = {"w","h", NULL};
//     if (!PyArg_ParseTupleAndKeywords(args, keywds, "ii", kwlist,
//                               &w,&h)) return NULL;

// 	switch (img->bpp)
// 	{
// 	case IMAGE_BPP_GRAYSCALE:
// 	{
// 		uint8_t* out = xalloc(w*h);
// 		uint8_t* in = img->pixels;
// 		float sx=(float)(img->w)/w;
// 		float sy=(float)(img->h)/h;
// 		int x,y, x0,y0,x1,y1,val_x1,val_y1;
// 		float xf,yf;
// 		mp_obj_t image = py_image(w, h, img->bpp, out);
// 		if(w >= w0 || h >= h0)
// 		{
// 			for(y=0;y<h;y++)
// 			{
// 				yf = (y+0.5)*sy-0.5;
// 				y0 = (int)yf;
// 				y1 = y0 + 1;
// 				val_y1 = y0<h0-1 ? y1 : y0;
// 				for(x=0;x<w;x++)
// 				{
// 					xf = (x+0.5)*sx-0.5;
// 					x0 = (int)xf;
// 					x1 = x0 + 1;
// 					val_x1 = x0<w0-1 ? x1 : x0;
// 					out[y*w+x] = (uint8_t)(in[y0*w0+x0]*(x1-xf)*(y1-yf)+\
// 								in[y0*w0+val_x1]*(xf-x0)*(y1-yf)+\
// 								in[val_y1*w0+x0]*(x1-xf)*(yf-y0)+\
// 								in[val_y1*w0+val_x1]*(xf-x0)*(yf-y0));
// 				}
// 			}
// 		}
// 		else
// 		{
// 			for(y=0;y<h;y++)
// 			{
// 				y0 = y*sy;
// 				y1 = (y+1)*sy;
// 				for(x=0;x<w;x++)
// 				{
// 					x0 = x*sy;
// 					x1 = (x+1)*sy;
// 					int sum,xx,yy;
// 					sum=0;
// 					for(yy=y0; yy<=y1; yy++)
// 					{
// 						for(xx=x0; xx<=x1; xx++)
// 						{
// 							sum+=in[yy*w0+xx];
// 						}
// 					}
// 					out[y*w+x]=sum/((y1-y0+1)*(x1-x0+1)); 	//avg to get better picture
// 				}
// 			}
// 		}
// 		return image;
// 		break;
// 	}
// 	case IMAGE_BPP_RGB565: 
// 	{
// 		uint16_t* out = xalloc(w*h*2);
// 		uint16_t* in = (uint16_t*)img->pixels;
// 		float sx=(float)(w0)/w;
// 		float sy=(float)(h0)/h;
// 		int x,y, x0,y0;
// 		uint16_t x1, x2, y1, y2;

// 		mp_obj_t image = py_image(w, h, img->bpp, out); //TODO: zepan says here maybe have bug ... ?
//         if(w0 == w && h0 == h)
//         {
//             for(y=0, y0=0; y<h; y++,y0++)
//             {
//                 for(x=0, x0=0; x<w; x++,x0++)
//                 {
//                     out[y*w+x] = in[y0*w0+x0];
//                 }
//             }
//         }
//         else if(w0 >= w || h0 > h)
//         {
//             for(y=0;y<h;y++)
//             {
//                 y0 = y*sy;
//                 for(x=0;x<w;x++)
//                 {
//                     x0 = x*sx;
//                     out[y*w+x] = in[y0*w0+x0];
//                 }
//             }
//         }
//         else
//         {
//             float x_src, y_src;
//             float temp1, temp2;
//             uint8_t temp_r, temp_g, temp_b;
//             for(y=0;y<h;y++)
//             {
//                 for(x=0;x<w;x++)
//                 {
//                     x_src = (x + 0.5f) * sx - 0.5f;
//                     y_src = (y + 0.5f) * sy - 0.5f;
//                     x1 = (uint16_t)x_src;
//                     x2 = x1 + 1;
//                     y1 = (uint16_t)y_src;
//                     y2 = y1 + 1;
//                     if (x2 >= w0 || y2 >= h0)
//                     {
//                         out[ x + y * w] = in[x1 + y1 * w0];
//                         continue;
//                     }
//                     // if( (x2 - x_src) > (x_src - x1) )
//                     // {
//                     //     x_src = x1;
//                     // }
//                     // else
//                     // {
//                     //     x_src = x2;
//                     // }
//                     // if( (y2 - y_src) > (y_src - y2) )
//                     // {
//                     //     y_src = y2;
//                     // }
//                     // else
//                     // {
//                     //     y_src = y1;
//                     // }
//                     // out[x + y * w] = in[(uint16_t)x_src + (uint16_t)y_src*w0];

//                     temp1 = (x2 - x_src) * COLOR_RGB565_TO_R5(in[ x1 + y1 * w0]) + (x_src - x1) * COLOR_RGB565_TO_R5(in[x2 + y1 * w0]);
//                     temp2 = (x2 - x_src) * COLOR_RGB565_TO_R5(in[ x1 + y2 * w0]) + (x_src - x1) * COLOR_RGB565_TO_R5(in[x2 + y2 * w0]);
//                     temp_r = (uint8_t)((y2 - y_src) * temp1 + (y_src - y1) * temp2);
//                     temp1 = (x2 - x_src) * COLOR_RGB565_TO_G6(in[ x1 + y1 * w0]) + (x_src - x1) * COLOR_RGB565_TO_G6(in[x2 + y1 * w0]);
//                     temp2 = (x2 - x_src) * COLOR_RGB565_TO_G6(in[ x1 + y2 * w0]) + (x_src - x1) * COLOR_RGB565_TO_G6(in[x2 + y2 * w0]);
//                     temp_g = (uint8_t)((y2 - y_src) * temp1 + (y_src - y1) * temp2);
//                     temp1 = (x2 - x_src) * COLOR_RGB565_TO_B5(in[ x1 + y1 * w0]) + (x_src - x1) * COLOR_RGB565_TO_B5(in[x2 + y1 * w0]);
//                     temp2 = (x2 - x_src) * COLOR_RGB565_TO_B5(in[ x1 + y2 * w0]) + (x_src - x1) * COLOR_RGB565_TO_B5(in[x2 + y2 * w0]);
//                     temp_b = (uint8_t)((y2 - y_src) * temp1 + (y_src - y1) * temp2);
//                     out[x + y * w] = COLOR_R5_G6_B5_TO_RGB565(temp_r, temp_g, temp_b);
//                 }
//             }
//         }
// 		return image;
// 		break;
// 	}
// 	default:
// 		MSGLOG("only support grayscale, 565 zoom out now\r\n");
// 		return mp_const_none;
// 		break;
// 	}
// }
// typedef struct _py_image_obj_t {
//     mp_obj_base_t base;
//     image_t _cobj;
// } py_image_obj_t MICROPY_OBJ_BASE_ALIGNMENT;


// mp_obj_t py_image(int w, int h, int bpp, void *pixels)
// {
//     py_image_obj_t *o = m_new_obj(py_image_obj_t);
//     o->base.type = &py_image_type;
//     o->_cobj.w = w;
//     o->_cobj.h = h;
//     o->_cobj.bpp = bpp;
//     o->_cobj.pixels = pixels;
//     o->_cobj.pix_ai = NULL;
//     return o;
// }