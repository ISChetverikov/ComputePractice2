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

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = rand() % 100 - 50;
		}
	}
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> & other) {
	v = vector<vector<T>>(other.m);

	for (int i = 0; i < other.m; i++)
	{
		v[i] = vector<T>(other.v[i]);
	}

	this->m = other.m;
	this->n = other.n;
}

template <class T>
Matrix<T>::Matrix(int n, int m, T * coefs) {
	v = vector<vector<T>>(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = vector<T>(m);
		for (int j = 0; j < m; j++)
		{
			v[i][j] = coefs[i*n + j];
		}
	}
}

template <class T>
Matrix<T>::~Matrix() {

}