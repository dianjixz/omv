
#define PY_SSIZE_T_CLEAN 
#include<Python.h>



typedef struct simple_color {
    uint8_t G;          // Gray
    union {
        int8_t L;       // LAB L
        uint8_t red;    // RGB888 Red
    };
    union {
        int8_t A;       // LAB A
        uint8_t green;  // RGB888 Green
    };
    union {
        int8_t B;       // LAB B
        uint8_t blue;   // RGB888 Blue
    };
} __attribute__((aligned(8))) simple_color_t;

void imlib_grayscale_to_rgb(simple_color_t *grayscale, simple_color_t *rgb)
{
    rgb->red   = grayscale->G;
    rgb->green = grayscale->G;
    rgb->blue  = grayscale->G;
}




#define mp_obj_t 					PyObject*
#define mp_obj_new_int(po)			PyLong_FromLong(po)


// mp_obj_t mp_obj_new_tuple(size_t n, const mp_obj_t *items) {
//     if (n == 0) {
//         return mp_const_empty_tuple;
//     }
//     mp_obj_tuple_t *o = m_new_obj_var(mp_obj_tuple_t, mp_obj_t, n);
//     o->base.type = &mp_type_tuple;
//     o->len = n;
//     if (items) {
//         for (size_t i = 0; i < n; i++) {
//             o->items[i] = items[i];
//         }
//     }
//     return MP_OBJ_FROM_PTR(o);
// }






PyObject* mp_obj_new_tuple(size_t n, const mp_obj_t *items)
{

	if (n == 0)
	{
		return PyTuple_New(0);
	}
printf("nihao:2\r\n");

	PyObject* o = PyTuple_New(n);
	if (items)
	{
		for (size_t i = 0; i < n; i++)
		{
			if(PyTuple_SetItem(o,i,items[i]) == -1)
			{
				printf("error!\r\n");
			}
			
		}
	}

	return o;
}



int mp_obj_get_int(mp_obj_t O)
{
	return PyLong_AsLong(O);
}



mp_obj_t py_image_grayscale_to_rgb(mp_obj_t not_tuple)
{
    simple_color_t grayscale_color, rgb_color;
    grayscale_color.G = mp_obj_get_int(not_tuple);
    imlib_grayscale_to_rgb(&grayscale_color, &rgb_color);


	printf("nihao:1\r\n");

	mp_obj_t o = mp_obj_new_tuple(3, (mp_obj_t[3])
            {mp_obj_new_int(rgb_color.red),
             mp_obj_new_int(rgb_color.green),
             mp_obj_new_int(rgb_color.blue)});

printf("nihao:4\r\n");
    return o;
}











// 没错，这就够了，什么stdio.h就都有了
static PyObject* 
hello(PyObject* self, PyObject* args) {

	PyObject* pyo;
	PyObject* pyt;



if (!PyArg_ParseTuple(args, "O", &pyo))
        return NULL;
	printf("starting!/r/n");


	pyt = py_image_grayscale_to_rgb(pyo);

	printf("endle!/r/n");
    return pyt;
}
// PyMethodDef 是一个结构体
static PyMethodDef my_methods[] = {
    { "hello", (PyCFunction)hello,METH_VARARGS , "Just show a greeting." },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,
    "test",
    NULL,
    -1,
    my_methods
};
PyMODINIT_FUNC PyInit_test(void) {
    return PyModule_Create(&mymodule);
}