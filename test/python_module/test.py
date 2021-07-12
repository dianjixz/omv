#!/usr/bin/env python3


# from PIL import Image
# import numpy as np
# # while True:
# img = Image.open("/home/nihao/work/v831_lin/lin/UDISK/temp.jpg")
# print(img.size)
# img.show()
# img_bytes = img.tobytes()
# print("changdu1:",len(img_bytes))
# import image

# image.send_to_image(img_bytes,w=img.width,h=img.height)



# # img_ary = np.array(img)
# # img_list = img_ary.tolist()


# # print("python:1")
# # image.send_to_image(img_list)
# # print("python:2")
# ma = image.find_blobs([(2, 39, 11, 63, 7, 36)],roi=[], x_stride=1, y_stride=1, invert=False, area_threshold=1, pixels_threshold=1, merge=True, margin=0)
# # print(ma)


# for i in ma:
# 	image.draw_rectangle(i["x"],i["y"],i["w"],i["h"])


# # for i in ma:
# # 	print(i)
# # {"x":0, "y":0, "w":101, "h":89, "pixels":7880, "cx":46, "cy":40, "rotation":2.749179, "code":1, "count":1}
# # 	image.draw_rectangle(i["x"],i["y"],i["w"],i["h"],fill=False)

# img_a = image.img_back_rgb888()
# # print(img_a)
# # print(img_a[0],img_a[1],img_a[2])


# print("changdu2:",len(img_a))
# image.close()
# img_ar = Image.frombytes(mode="RGB",size=(img.width,img.height),data=img_a,decoder_name="raw")
# img_ar.show()

# # for i in range(200):
# # 	img_ar[i][100] = [0,0,255]



# # h = len(img_ar)
# # w = len(img_ar[0])

# # print("picw:",w,"pich:",h)




# # for i in ma:
# # 	x = i["x"]
# # 	y = i["y"]
# # 	w = i["w"]
# # 	h = i["h"]
	
# # 	for m in range(h+1):
# # 		for n in range(w+1):	
# # 			print("x:",x,"y:",y,"w:",w,"h:",h,end="----------")
# # 			print("x:",x,"y:",y,"m:",m,"n:",n)
# # 			img_ar[x+m][y+n] = [0,0,255]

# # img_ar = img_ar.astype(np.uint8)

# # imga = Image.fromarray(img_ar)
# # imga.show()

import image_new
exit()


