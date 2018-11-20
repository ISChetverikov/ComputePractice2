#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>  
#include <sstream>
#include "Matrix.h"

#include "exception.h"

using namespace std;

template <class T>
Matrix<T>::Matrix(int m, int n, bool isRandomFill) {
	v = vector<vector<T>>(m);
	for (int i = 0; i < m; i++)
	{
		v[i] = vector<T>(n);
	}

	this->m = m;
	this->n = n;

	if (!isRandomFill)
		return;

	RandomFill();
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> & other) {
	v = vector<vector<T>>(other.m);

	for (int i = 0; i < other.m; i++)
	{
		v[i] = other.v[i];
	}

	this->m = other.m;
	this->n = other.n;
}

template <class T>
Matrix<T>::Matrix(int m, int n, T * coefs) {
	v = vector<vector<T>>(m);
	this->m = m;
	this->n = n;
	for (int i = 0; i < m; i++)
	{
		v[i] = vector<T>(n);
		for (int j = 0; j < n; j++)
		{
			v[i][j] = coefs[i*m + j];
		}
	}
}

template <class T>
Matrix<T>::~Matrix() {

}

template <class T>
Matrix<T>::operator Matrix<double>() const {
	Matrix<double> res = Matrix<double>(m, n, false);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res[i][j] = (double)v[i][j];
		}
	}

	return res;
}

template <class T>
vector<T>& Matrix<T>::operator [](int i) {
	return v[i];
}
template <class T>
const vector<T>& Matrix<T>::operator [](int i) const {
	return v[i];
}

template <class T>
void Matrix<T>::RandomFill() {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = (T)(rand() % 1000) / 100;
		}
	}
}