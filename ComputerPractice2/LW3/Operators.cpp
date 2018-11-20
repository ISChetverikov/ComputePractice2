#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>  
#include <sstream>
#include "Matrix.h"

#include "exception.h"

using namespace std;

template<class T>
Matrix<T> Matrix<T>::operator * (const T r) const {
	Matrix<T> res = Matrix<T>(*this);

	for (int i = 0; i < this->m; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			res.v[i][j] *= r;
		}
	}

	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator + (const Matrix<T> other) {
	if (m != other.m || n != other.n) {
		throw AdditionMatricesException();
	}
	
	Matrix<T> res = Matrix<T>(*this);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res.v[i][j] += other.v[i][j];
		}
	}

	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator - (const Matrix<T> other) {
	if (m != other.m || n != other.n) {
		throw AdditionMatricesException();
	}

	Matrix<T> res = Matrix<T>(*this);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res.v[i][j] -= other.v[i][j];
		}
	}

	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator * (const Matrix<T> & other) {
	if (this->n != other.m) {
		throw MultiplicationMatricesException();
	}
	
	// (m, n) * (n, l)
	int l = other.n;

	Matrix<T> res = Matrix<T>(m, l, false);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < l; j++)
		{
			res.v[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				res.v[i][j] += this->v[i][k] * other.v[k][j];
			}
			
		}
	}

	return res;
}

template<class T>
Matrix<T> Matrix<T>::operator & (const Matrix<T> other) {
	if (m != other.m || n != other.n) {
		throw HadamarMatricesException();
	}
	Matrix<T> res = Matrix<T>(*this);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res.v[i][j] *= other.v[i][j];
		}
	}

	return res;
}

template <class T>
Matrix<T> Matrix<T>::operator | (const Matrix & other) {
	if (m != other.m)
		throw ConcatinationMatrixException();

	Matrix<T> res = Matrix<T>(m, n + other.n, false);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res[i][j] = v[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = n; j < n + other.n; j++)
		{
			res[i][j] = other.v[i][j-n];
		}
	}

	return res;
}

template <class T, class Y>
Matrix<double> operator * (const Matrix<T> & left, const Matrix<Y> & right) {
	
	return (Matrix<double>)left * (Matrix<double>)right;
}