#include <Python.h>

static PyObject *hello_world(PyObject *self) {
	printf("Olá mundo.");
	Py_RETURN_NONE;
}

static PyMethodDef algo_crypt_methods[] = {
	{"hello_world", (PyCFunction)hello_world, METH_NOARGS, NULL},
	{NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initalgo_crypt() {
	Py_InitModule("algo_crypt", algo_crypt_methods);
}
