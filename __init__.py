from PIL.PngImagePlugin import PngImageFile as img_type
import numpy as np



class ImageError(Exception):   #继承自基类Exception
    def __init__(self,ErrorInfo):
        self.errorinfo=ErrorInfo
    def __str__(self):
        return self.errorinfo


class Blob:
    Auto = 0
    __img_data = None

    def __init__(self,img):
        if type(img) != img_type:
            raise ImageError("type err,please check img!")
        img_data = np.array(img)
        self.__img_data = img_data.tolist()
        del img_data

        

    def find_blobs(self,thresholds, roi=0, x_stride=2, y_stride=2, invert=False, area_threshold=4, pixels_threshold=4, merge=False, margin=0):
        
        print("nihao")












    def __del__(self):
        del self.__img_data



