#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>  
#include <sstream>
#include "Vector.h"
#include "Matrix.h"

#include "exception.h"

using namespace std;

template <class T>
Vector<T> Vector<T>::operator * (const T r) {
	Vector<T> res = Vector<T>(*this);

	for (int i = 0; i < n; i++)
	{
		res[i] = res[i] * r;
	}

	return res;
}

template <class T>
Vector<T> Vector<T>::operator + (const Vector & other) {
	if (this->n != other.n) {
		throw VectorsDiffDimensionException();
	}

	Vector<T> res = Vector<T>(*this);

	for (int i = 0; i < n; i++)
	{
		res[i] += other[i];
	}

	return res;
}

template <class T>
Vector<T> Vector<T>::operator - (const Vector & other) {

	if (this->n != other.n) {
		throw VectorsDiffDimensionException();
	}

	Vector<T> res = Vector<T>(*this);

	for (int i = 0; i < n; i++)
	{
		res[i] -= other[i];
	}

	return res;
}

template <class T>
T Vector<T>::operator * (const Vector<T> & other) {
	if (this->n != other.n) {
		throw VectorsDiffDimensionException();
	}

	T res = 0;

	for (int i = 0; i < n; i++)
	{
		res += v[i] * other[i];
	}

	return res;
}

template <class T>
Vector<T> Vector<T>::operator & (const Vector<T> & other) {
	if (this->n != other.n) {
		throw VectorsDiffDimensionException();
	}

	Vector<T> res = Vector<T>(*this);

	for (int i = 0; i < n; i++)
	{
		res[i] *= other[i];
	}

	return res;
}

template <class T>
Matrix<T> Vector<T>::operator ^ (const Vector<T> & other) {
	if (this->n != other.n) {
		throw VectorsDiffDimensionException();
	}
	auto a = this->ToMatrix(false);
	auto b = other.ToMatrix(true);

	return a * b;
}