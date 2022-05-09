// #include "mf_qr.h"
// #include "printf.h"
// #include "mf_lib.h"
// #include "zbar.h"
#include <stdio.h>
#include "zbar.h"
#include <stdint.h>
#include <stdlib.h>

/* Limits on the maximum size of QR-codes and their content. */
#define QUIRC_MAX_BITMAP    3917
#define QUIRC_MAX_PAYLOAD   8896

#define printk(ma,...)
#if 1
#define DEBUG_LINE()
#else
#define DEBUG_LINE() do{ printk("[mf_flow_vis2vis] L%d\r\n", __LINE__); } while(0)
#endif

/*****************************************************************************/
// Driver 底层驱动
/*****************************************************************************/

// static void qrcode_convert_order(uint8_t* data, uint16_t w, uint16_t h)
// {
//     uint16_t t[2], *ptr = (uint16_t *)(data);

//     for (uint32_t i = 0; i < (w * h); i += 2)
//     {
//         t[0] = *(ptr + 1);
//         t[1] = *(ptr);
//         *(ptr) = SWAP_16(t[0]);
//         *(ptr + 1) = SWAP_16(t[1]);
//         ptr += 2;
//     }
//     return;
// }

// static void qrcode_convert_to_gray(uint8_t* data, uint16_t w, uint16_t h, uint8_t *gray)
// {
//     for (int y = 0, yy = h; y < yy; y++)
//     {
//         uint16_t *row_ptr = ((uint16_t *)data) + (w * y);
//         for (int x = 0, xx = w; x < xx; x++)
//         {
//             *(gray++) = IMAGE_GET_RGB565_PIXEL_FAST(row_ptr, w - x) & 0xff;
//             // *(grayscale_image++) = COLOR_RGB565_TO_GRAYSCALE(IMAGE_GET_RGB565_PIXEL_FAST(row_ptr, w - x));
//         }
//     }
//     return;
// }

/*****************************************************************************/
// Private Func 局部函数
/*****************************************************************************/
static uint8_t _mf_qr_scan_pic(uint8_t *pic, uint16_t w, uint16_t h, uint8_t* qrcode, uint8_t convert)
{
    /* 先申请内存，如果失败则直接返回 */
    uint8_t *gray = malloc(w * h);
    if (!gray)
    {
        printk("malloc failed %s:%d\r\n", __func__, __LINE__);
        return 0;
    }

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
    zbar_image_set_data(image, gray, w * h, NULL); //zbar_image_free_data
    /* scan the image for barcodes */
    int qrcode_num = zbar_scan_image(scanner, image);
    /* extract results */
    const zbar_symbol_t *symbol = zbar_image_first_symbol(image);

    /* 如果有多个二维码，会把最后一个结果返回 */
    for (; symbol; symbol = zbar_symbol_next(symbol))
    {
        /* do something useful with results */
        zbar_symbol_type_t typ = zbar_symbol_get_type(symbol);
        const char *data = zbar_symbol_get_data(symbol);
        size_t len = strlen(data);

        printf("\r\ndecoded symbol: %s, content: \"%s\", len = %ld\r\n", zbar_get_symbol_name(typ), data, len);

        /* 拷贝到结果 */
        if (len < 8896)
        {
            memcpy(qrcode, data, len);
            qrcode[len] = 0;
        }
        else
        {
            /* 这里溢出了,就不进行拷贝 */
            qrcode_num = 0;
        }
    }

    /* clean up */
    zbar_image_destroy(image);
    zbar_image_scanner_destroy(scanner);
    if(convert) qrcode_convert_order(pic,w,h);

    if (gray)
        free(gray);

    return qrcode_num;
}

// void _mf_qr_scan_start(uint32_t timeout_s)
// {
// 	mf_qr.time_start_s = sysctl_get_time_us()/1000/1000;
// 	if(mf_qr.time_start_s == 0) mf_qr.time_start_s = 1;
// 	mf_qr.timeout_s = timeout_s;
// 	mf_qr.qrnum = 0;
//     mf_qr.run_flag = 1;
// 	return;
// }


// qr_res_t _mf_qr_scan_loop(void)
// {DEBUG_LINE();
// 	qr_res_t ret;
// 	//确认扫码类型
// 	if(mf_qr.run_type == QR_RUN_SELF) return QR_ERR_TYPE;
// 	DEBUG_LINE();
// 	//确认扫码超时情况
// 	if(mf_qr.time_start_s == 0) return QR_ERR_START;
// 	DEBUG_LINE();
// 	uint32_t dt = sysctl_get_time_us()/1000/1000 - mf_qr.time_start_s;
//     if (dt > (mf_qr.timeout_s))
// 	{	DEBUG_LINE();
// 		ret = QR_TIMEOUT;
// 		mf_qr.time_start_s = 0;  //扫描超时，清零起始时间
//         mf_qr.run_flag = 0;
// 		if(mf_qr.qr_cb) mf_qr.qr_cb(ret);
//         return ret;
//     }
// 	DEBUG_LINE();
// 	//锁定buf
// 	if(mf_qr.run_type == QR_RUN_UI) {
// 		mf_cam.lock_kpu();
// 		mf_cam.lock_rgb();
// 	}
// 	//执行扫码
// 	DEBUG_LINE();
// 	mf_qr.qrnum = _mf_qr_scan_pic(mf_cam.rgb_image[mf_cam.rgb_buf_index],\
// 		MF_CAM_W, MF_CAM_H, mf_qr.qrcode, 1);
// 	DEBUG_LINE();
//     if (mf_qr.qrnum != 0) {
//         ret = QR_SUCC;
// 		mf_qr.time_start_s = 0;  //扫描成功，清零起始时间
//         mf_qr.run_flag = 0;
// 		//执行回调
// 		if(mf_qr.qr_cb) mf_qr.qr_cb(ret);DEBUG_LINE();
//     } else {
//         ret = QR_NONE;
//     }

// 	//解锁buf
// 	if(mf_qr.run_type == QR_RUN_UI) {
// 		mf_cam.unlock_kpu();
// 		mf_cam.unlock_rgb();
// 	}
// 	DEBUG_LINE();
// 	return ret;
// }

// static void qr_loop_in_flow(void)
// {
//     _mf_qr_scan_loop();
// }

// mf_err_t _mf_qr_init(qr_run_t run_type, qr_cb_t qr_cb)
// {
// 	mf_err_t err = 0;
// 	switch(run_type) {
// 	case QR_RUN_SELF:		//普通扫描模式, 无需初始化
// 		break;
// 	case QR_RUN_UI:			//依赖于mf_ui, 自行lock buf, 无需注册回调
// 		mf_qr.run_type = QR_RUN_UI;
// 		mf_qr.qr_cb = qr_cb;
// 		break;
// 	case QR_RUN_FLOW:		//依赖于mf_flow,需注册flow的回调
// 		mf_qr.run_type = QR_RUN_FLOW;
// 		err = mf_flow.reg_rgbbuf_cb0(qr_loop_in_flow);
// 		if(err != 0) {
// 			printk("rgbbuf_cb0  register failed!\r\n");
// 			return MF_ERR_QR_CB;
// 		}
// 		mf_qr.qr_cb = qr_cb;
// 		break;
// 	default:
// 		return MF_ERR_QR_TYPE;
// 		break;
// 	}
    
// 	mf_qr.time_start_s = 0;
//     mf_qr.init_flag = 1;

// 	return 0;	
// }

