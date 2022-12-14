#pragma once
#include "Element.h"

template<class T>
inline Element<T>::Element():adr(nullptr)
{
}

template<class T>
inline Element<T>::Element(const Element<T>& obj)
{
	this->adr = obj.adr;
	this->val = obj.val;
}

template<class T>
T& Element<T>::getVal() {
	return val;
}

template<class T>
Element<T>* Element<T>::getAdr() {
	return adr;
}

template<class T>
void Element<T>::setVal(T val) {
	this->val = val;
}
template<class T>
void Element<T>::setAdr(Element<T>* adr) {
	this->adr = adr;
}