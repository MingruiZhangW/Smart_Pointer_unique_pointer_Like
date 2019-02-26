#ifndef SMART_PTR_MING_H
#define SMART_PTR_MING_H

#include <iostream>

template <class T>
class Mysmart_ptr
{

public:

	Mysmart_ptr() : m_ptr(nullptr) {}
	Mysmart_ptr(T *ptr) : m_ptr(ptr) {}

	//Copy constructor delete
	Mysmart_ptr(Mysmart_ptr &ptr) = delete;

	//move constructor
	Mysmart_ptr(Mysmart_ptr &&ptr) : m_ptr(ptr.m_ptr) {

		ptr.m_ptr = nullptr;

	}

	// Copy assignment delete
	Mysmart_ptr& operator=(Mysmart_ptr &ptr) = delete;

	//move assignment operator
	Mysmart_ptr& operator=(Mysmart_ptr &&ptr) {

		if (&ptr == this) { return *this; }

		delete m_ptr;

		m_ptr = ptr;
		ptr = nullptr;

		return *this;

	}

	Mysmart_ptr* operator->() const {

		return m_ptr;

	}
	Mysmart_ptr& operator*() const {

		return *m_ptr;

	}
	~Mysmart_ptr() {

		//if you delete a pointer that is neither NULL nor allocated with `new`, the behaviour is undefined
		delete m_ptr;

	}

private:
	T *m_ptr;
};


#endif
