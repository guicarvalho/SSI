#include <Python.h>
#include "caesar.h"
#include "otp.h"
#include "hill.h"

static PyObject*
Py_caesar_crypt(PyObject* self, PyObject* args)
{	
	char* msg;
	int shift;
	
	if (!PyArg_ParseTuple(args, "si", &msg, &shift))
		return NULL;

	return Py_BuildValue("s", caesar_crypt(msg, shift));
}

static PyObject*
Py_caesar_decrypt(PyObject* self, PyObject* args)
{
	char* msg;
	int shift;

	if (!PyArg_ParseTuple(args, "si", &msg, &shift))
		return NULL;

	return Py_BuildValue("s", caesar_decrypt(msg, shift));
}

static PyObject*
Py_otp_crypt(PyObject* self, PyObject* args)
{	
	char* msg;
	int shift;
	
	if (!PyArg_ParseTuple(args, "si", &msg, &shift))
		return NULL;

	return Py_BuildValue("s", otp_crypt(msg, shift));
}

static PyObject*
Py_otp_decrypt(PyObject* self, PyObject* args)
{
	char* msg;
	int shift;

	if (!PyArg_ParseTuple(args, "si", &msg, &shift))
		return NULL;

	return Py_BuildValue("s", otp_decrypt(msg, shift));
}

static PyObject*
Py_hill_crypt(PyObject *self, PyObject* args)
{
	char* msg;
	char* alphabet;
	int matrix_key[2][2];
	PyObject* list, *sub_list;
	
	if (!PyArg_ParseTuple(args, "ssO", &msg, &alphabet, &list) || 
		!PyList_Check(list) ||
		PyList_Size(list) != 2)
		return NULL;

	sub_list = PyList_GetItem(list, 0);
	matrix_key[0][0] = PyInt_AsLong(PyList_GetItem(sub_list, 0));
	matrix_key[0][1] = PyInt_AsLong(PyList_GetItem(sub_list, 1));
	
	sub_list = PyList_GetItem(list, 1);
	matrix_key[1][0] = PyInt_AsLong(PyList_GetItem(sub_list, 0));
	matrix_key[1][1] = PyInt_AsLong(PyList_GetItem(sub_list, 1));
	
	return Py_BuildValue("s", hill_crypt(msg, alphabet, matrix_key));
}

static PyMethodDef algo_crypt_methods[] =
{
	{"caesar_crypt", Py_caesar_crypt, METH_VARARGS, NULL},
	{"caesar_decrypt", Py_caesar_decrypt, METH_VARARGS, NULL},
	{"otp_crypt", Py_otp_crypt, METH_VARARGS, NULL},
	{"otp_decrypt", Py_otp_decrypt, METH_VARARGS, NULL},
	{"hill_crypt", Py_hill_crypt, METH_VARARGS, NULL},
	{NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initalgo_crypt(void) {
	(void) Py_InitModule("algo_crypt", algo_crypt_methods);
}
