#pragma once
#include "Vector.h"
#include "DerivedMatrix.h"
#include <vector>
using namespace std;

template <class T>
Vector<T>::Vector(int n, bool isRandomFill) {
	this->n = n;
	v = vector<T>(n);

	if (isRandomFill)
		RandomFill();
}

template <class T>
Vector<T>::Vector(int n, T * coefs) {
	v = vector<T>(n);
	this->n = n;
	for (int i = 0; i < n; i++)
	{
		v[i] = coefs[i];
	}
}

template <class T>
void Vector<T>::RandomFill() {
	for (int i = 0; i < n; i++)
	{
		v[i] = (T)(rand() % 10000) / 100;
	}
}

template <class T>
Matrix<T> Vector<T>::ToMatrix(bool isRow) const{
	if (isRow)
		return Row<T>(*this);

	else {
		auto a = Column<T>(*this);
		return a;
	}
}

template <class T>
T& Vector<T>::operator [](int i) {
	return v[i];
}

template <class T>
const T& Vector<T>::operator [](int i) const{
	return v[i];
}

template <class T>
int Vector<T>::Size() const{
	return v.size();
}