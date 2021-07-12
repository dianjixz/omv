#!/usr/bin/env python3

from PIL import Image, ImageFont, ImageDraw
from maix import display, camera
import numpy as np
import image


def find_blob():
	img = camera.capture()
	img_data = np.array(img)
	img_list = img_data.tolist()
	image.send_to_image(img_list)
	ma = image.find_blobs([(2, 39, 11, 63, 7, 36)],roi=[], x_stride=1, y_stride=1, invert=False, area_threshold=1, pixels_threshold=20, merge=True, margin=0)
	if ma:
		for i in ma:
			image.draw_rectangle(i["x"],i["y"],i["w"],i["h"])
	img_a = image.img_back_rgb888()
	image.close()
	img_ar = np.array(img_a)
	img_ar = img_ar.astype(np.uint8)
	imga = Image.fromarray(img_ar)
	imga.show()

if __name__ == "__main__" :
	while True:
		find_blob()









