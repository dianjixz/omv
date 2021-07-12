
// // #include <pybind11/pybind11.h>
// // #include <iostream>
// // #include <string>

// // namespace py = pybind11;


// // //结构体定义
// // struct my {

// //    string name;
// //    int age;
// //    int high;
// // };



// // PYBIND11_MODULE(my_test, m) {//这几行代码只使用了一个m，说明这几个函数都是绑在一起
// //         m.doc() = "my struct test!";
	
// // 	py::class_<my>(m, "my");
        
// // }




// //文件名：func_wrapper.cpp
// #include <pybind11/pybind11.h>  
// #include "conversion.h"
// #include "imlib.h"

  




// namespace py = pybind11;  

// // class tmp
// // {
// // private:
// //     /* data */
// // public:
// //     tmp(/* args */);
// //     ~tmp();
// // };

// // tmp::tmp(/* args */)
// // {
// // }

// // tmp::~tmp()
// // {
// // }

// // void init(image_t & tmp) {
// //     tmp.ts.data = (uint8_t *)0xf0f0f0f0;
// //     printf("init %p\r\n", tmp.ts.data);
// // }

// // void calc(image_t & tmp) {
// //     printf("calc %p\r\n", tmp.ts.pixels);
// // }
//         // .def("test_init", &test);
//         // .def("test_copy", &test);
//         // .def("imlib_lbp_desc", &imlib_lbp_desc);
// // }

// // void test_fm(image *i)
// // {
// //     imlib_lbp_desc(this->ts);
// // }

// PYBIND11_MODULE(my_test, m){  

//     py::class_<image>(m,"image_t")
//         .def_readwrite("w",&image::w)
//         .def_readwrite("h",&image::h)
//         .def_readwrite("bpp",&image::bpp)
//         .def_readwrite("pixels",&image::pixels)
//         .def_readwrite("data",&image::data)
//         .def_readwrite("pix_ai",&image::pix_ai);
//     m.doc() = "conversion func"; 



//     // m.doc() = "conversion func";  
//     // py::class_<tmp>(m,"image_t")
//     //     .def("test", &test);
//         // .def_readwrite("w",&image::w)
//         // .def_readwrite("h",&image::h)
//         // .def_readwrite("bpp",&image::bpp)
//         // .def_readwrite("ts",&image::ts);

//     // m.def("calc", &calc);
//     // m.def("init", &init);
  
//     // py::class_<student>(m, "student")  
//     //     .def(py::init<string>())  
//     //     .def("setName", &student::setName)  
//     //     .def_readonly("name", &student::name)  
//     //     .def_readwrite("Chinese", &student::Chinese)  
//     //     .def_readwrite("Mathematics", &student::Mathematics)  
//     //     .def_readwrite("English", &student::English)  
//     //     .def_readwrite("total", &student::total);  
//     // m.def("calc", &calc);  
// }






#include <pybind11/pybind11.h>
 
namespace py = pybind11;
 
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
 
    m.def("swap", [](py::buffer a, py::buffer b) {\
        py::buffer_info a_info = a.request();
        py::buffer_info b_info = b.request();
        swap(static_cast<int*>(a_info.ptr), static_cast<int*>(b_info.ptr));
    });

}
