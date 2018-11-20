#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>  
#include <sstream>
#include "Matrix.h"
#include "DerivedMatrix.h"

#include "exception.h"

using namespace std;

template <class T>
T Matrix<T>::Trace() {
	int min = (m > n) ? n : m;
	T trace = 0;

	for (int i = 0; i < min; i++)
	{
		trace += v[i][i];
	}
	
	return trace;
}

template <class T>
double Matrix<T>::Norm() {
	double norm = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			norm += v[i][j] * v[i][j];
		}
	}

	return sqrt(norm);
}

template <class T>
double Matrix<T>::Determinant() {
	double d = 1;
	
	if (n != m)
		throw NotSquareMatrixException();

	Matrix<double> form = EchelonForm();
	for (int i = 0; i < n; i++)
	{
		d *= form[i][i];
	}
	return d;
}

template <class T>
int Matrix<T>::Rank(){
	int rank = 0;

	EchelonForm(rank);

	return rank;
}

template <class T>
Matrix<double> Matrix<T>::ReverseMatrix() {
	
	if (Determinant() == 0)
		throw ZeroDeterminantException();

	return ((*this) | IdentityMatrix<T>(n)).EchelonForm().SubMatrix(0,n,n,n);
}

template <class T>
Matrix<T> Matrix<T>::Transpose() {

	if (n != m)
		throw NotSquareMatrixException();

	Matrix<T> res = Matrix<T>(*this);
	T temp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
		{
			temp = res.v[i][j];
			res.v[i][j] = res.v[j][i];
			res.v[j][i] = temp;
		}
	}
	
	return res;
}

template <class T>
Matrix<double> Matrix<T>::EchelonForm() {
	int rank = 0;

	return EchelonForm(rank);
}

template <class T>
Matrix<double> Matrix<T>::EchelonForm(int & _rank) {
	Matrix<double> res = (Matrix<double>)(*this);
	vector<double> temp;
	double r = 0;
	
	int min = (n > m) ? m : n;
	int rank = 0;

	for (int k = 0; k < min; k++)
	{
		int notNullIndex = rank;

		for (; notNullIndex < m; notNullIndex++) {
			if (res[notNullIndex][k] != 0)
				break;
		}
			

		if (notNullIndex == m)
			continue;

		if (notNullIndex != rank) {
			temp = res[notNullIndex];
			res[notNullIndex] = res[rank];
			res[rank] = temp;
		}
			
		for (int i = rank + 1; i < m; i++) {
			if (res[i][k] == 0)
				continue;

			r = res[i][k] / res[rank][k];
			for (int j = k; j < n; j++){
				res[i][j] -= r * res[rank][j];
			}
		}
			
		rank++;
		_rank = rank;
	}

	return res;
}