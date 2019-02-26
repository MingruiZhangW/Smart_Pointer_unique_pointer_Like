#include "Smart_ptr_Ming.h"

template <typename T>
Mysmart_ptr<T>::Mysmart_ptr() : m_ptr(nullptr){}

template <typename T>
Mysmart_ptr<T>::Mysmart_ptr(T *ptr) : m_ptr(ptr) {}

template <typename T>
Mysmart_ptr<T>::Mysmart_ptr(Mysmart_ptr<T> &&ptr) : m_ptr(ptr.m_ptr) {

	ptr.m_ptr = nullptr;

}

template <typename T>
Mysmart_ptr<T>& Mysmart_ptr<T>::operator=(Mysmart_ptr<T> &&ptr) {

	if (&ptr == this) { return *this;  }

	delete m_ptr;

	m_ptr = ptr;
	ptr = nullptr;

}

template <typename T>
Mysmart_ptr<T>* Mysmart_ptr<T>::operator->() const {

	return m_ptr;

}

template <typename T>
Mysmart_ptr<T>& Mysmart_ptr<T>::operator*() const {

	return *m_ptr;

}

template <typename T>
Mysmart_ptr<T>::~Mysmart_ptr() {

	//if you delete a pointer that is neither NULL nor allocated with `new`, the behaviour is undefined
	delete m_ptr;

}