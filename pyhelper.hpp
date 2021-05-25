#ifndef PYHELPER_HPP
#define PYHELPER_HPP


#include "Python.h"

class PyInstance_C {
public:
	PyInstance_C() {
		Py_Initialize();
	}
	~PyInstance_C() {
		Py_Finalize();
	}
};


class PyObject_C {
	PyObject* pobj;
public:
	PyObject_C() : pobj(nullptr) {
	}

	PyObject_C(PyObject* _pobj) : pobj(_pobj) {
	}

	~PyObject_C() {
		clean();
	}

	PyObject* getPythonObject() const {
		return this->pobj;
	}

	void setPythonObject(PyObject* _pobj) {
		this->pobj = _pobj;
	}

	PyObject* add_reference() {
		if (pobj) {
			Py_INCREF(pobj);
		}
		return pobj;
	}


	void clean() {
		if (pobj) {
			Py_DECREF(pobj);
		}
		pobj = nullptr;
	}


	PyObject* operator ->() {
		return pobj;
	}

	bool exists() const {
		return pobj ? true : false;
	}

	operator PyObject* () {
		return pobj;
	}

	PyObject* operator = (PyObject* p) {
		pobj = p;
		return pobj;
	}

	operator bool() {
		return pobj ? true : false;
	}
};
#endif