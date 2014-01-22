#include <Python.h>

#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sstream>

#include "libskeleton.cc"


#define Skeleton_Check(v) ((v)->ob_type == &Skeleton_Type)
//#define Skeleton_skeleton(v) (((Skeleton *)(v))->_skeleton)


extern "C" {

  typedef struct {
    PyObject_HEAD
    // TODO: add custom C++ types here
  } Skeleton;


  const char*
  Skeleton_do_something_doc = \
  "Do something.\n"
  "\n"
  "Accepts the following positional arguments:\n"
  "\n"
  "  :param sz: The amount of bytes (as an int) to allocate.\n"
  "  :rtype: :class:`None`.\n"
  "\n";


  static PyObject*
  Skeleton_do_something(PyObject *self, PyObject *args) {
    PyObject *results = NULL;
    PyObject *_sz = NULL;
    void *memory = NULL;
    long sz = 0;

    if (!PyArg_ParseTuple(args, "O", &_sz)) {
      results = Py_None;
      Py_INCREF(results);
      return results;
    }

    if (PyInt_Check(_sz)) {
      sz = PyInt_AsLong(_sz);
    }
    else {
      PyErr_SetString(PyExc_TypeError, "`sz` must be a Python integer!");
      return NULL;
    }

    memory = do_something(sz);
    memset(memory, 0, sz);
    //free(memory);

    results = Py_None;
    Py_INCREF(results);
    return results;
  }


  static PyMethodDef Skeleton_methods[] = {
    {"do_something", Skeleton_do_something, METH_VARARGS, Skeleton_do_something_doc},
    {NULL, NULL, 0, NULL},
  };


  /**
   *
   * Skeleton Type
   *
   */
  void
  Skeleton_dealloc(PyObject *self) {
    self->ob_type->tp_free((PyObject *) self);
  }

  static PyObject*
  Skeleton_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    Skeleton *self;
    self = (Skeleton *) type->tp_alloc(type, 0);
    if (self != NULL) {
      return (PyObject *)self;
    }
    return NULL;
  }

  static int
  Skeleton_init(Skeleton *self, PyObject *args, PyObject *kwargs) {
    return 0;
  }

  static PyObject*
  Skeleton_GetAttr(PyObject *self, char *attrname) {
    return Py_FindMethod(Skeleton_methods, self, attrname);
  }

  static PyObject*
  Skeleton_Repr(PyObject *self) {
    char buf[64];
    sprintf(buf, "Skeleton()");
    return PyString_FromString(buf);
  }


  const char*
  Skeleton_Type_doc = \
  "Skeleton extension object.";

  static PyTypeObject Skeleton_Type = {
      PyObject_HEAD_INIT(&PyType_Type)
      0,                         /*ob_size*/
      "Skeleton",                /*tp_name*/
      sizeof(Skeleton),          /*tp_basicsize*/
      0,                         /*tp_itemsize*/
      (destructor) Skeleton_dealloc, /*tp_dealloc*/
      0,                         /*tp_print*/
      (getattrfunc) Skeleton_GetAttr, /*tp_getattr*/
      0,                         /*tp_setattr*/
      0,                         /*tp_compare*/
      (reprfunc) Skeleton_Repr,  /*tp_repr*/
      0,                         /*tp_as_number*/
      0,                         /*tp_as_sequence*/
      0,                         /*tp_as_mapping*/
      0,                         /*tp_hash */
      0,                         /*tp_call*/
      0,                         /*tp_str*/
      0,                         /*tp_getattro*/
      0,                         /*tp_setattro*/
      0,                         /*tp_as_buffer*/
      Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
      Skeleton_Type_doc,         /* tp_doc */
      0,                         /* tp_traverse */
      0,                         /* tp_clear */
      0,                         /* tp_richcompare */
      0,                         /* tp_weaklistoffset */
      0,                         /* tp_iter */
      0,                         /* tp_iternext */
      Skeleton_methods,          /* tp_methods */
      0,                         /* tp_members */
      0,                         /* tp_getset */
      0,                         /* tp_base */
      0,                         /* tp_dict */
      0,                         /* tp_descr_get */
      0,                         /* tp_descr_set */
      0,                         /* tp_dictoffset */
      (initproc) Skeleton_init,  /* tp_init */
      0,                         /* tp_alloc */
      Skeleton_new,              /* tp_new */
  };


  /**
   *
   * Module functions
   *
   **/
  static PyMethodDef methods[] = {
    {NULL},
  };

  void
  initlibskeleton(){
    PyObject *m;
    if (PyType_Ready(&Skeleton_Type) < 0)
      return;
    m = Py_InitModule3("libskeleton", methods, "Python bindings for libskeleton.");
    if (m == NULL)
      return;
    Py_INCREF(&Skeleton_Type);
    PyModule_AddObject(m, "Skeleton", (PyObject*) &Skeleton_Type);
  }

} /* extern "C" */
