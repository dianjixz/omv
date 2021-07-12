#文件名：setup.py
from setuptools import setup, Extension  
  
functions_module = Extension(  
    name = 'example',  
    sources = ['func.cpp','image.cpp'],  
    include_dirs = [r'/home/nihao/.local/lib/python3.8/site-packages/pybind11/include',
                    r'/home/nihao/work/my_space/media/image/blob/src/img/include',
                    r'/home/nihao/work/my_space/media/image/blob/src/include']  
)  
  
setup(ext_modules = [functions_module])
