#ifndef SMART_PTR_MING_H
#define SMART_PTR_MING_H

#include <iostream>

template <class T>
class Mysmart_ptr
{

public:
	Mysmart_ptr();
	Mysmart_ptr(T *ptr);

	//Copy constructor delete
	Mysmart_ptr(Mysmart_ptr &ptr) = delete;

	//move constructor
	Mysmart_ptr(Mysmart_ptr &&ptr);

	// Copy assignment delete
	Mysmart_ptr& operator=(Mysmart_ptr &ptr) = delete;

	//move assignment operator
	Mysmart_ptr& operator=(Mysmart_ptr &&ptr);

	Mysmart_ptr* operator->() const;
	Mysmart_ptr& operator*() const;
	~Mysmart_ptr();

private:
	T *m_ptr;
};


#endif
