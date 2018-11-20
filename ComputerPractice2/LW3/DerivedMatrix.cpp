#include <vector>
#include "Matrix.h"
#include "Vector.h"
#include "DerivedMatrix.h"

#include "exception.h"

using namespace std;

#pragma region UpperTriangularMatrix
template <class T>
UpperTriangularMatrix<T>::UpperTriangularMatrix(int n, bool isRandomFill) : Matrix<T> (n, n, false){
	if (isRandomFill)
		RandomFill();
}

template <class T>
UpperTriangularMatrix<T>::UpperTriangularMatrix(int n, T * coefs) {
	v = vector<vector<T>>(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = vector<T>(n);
		for (int j = i; j < n; j++)
		{
			v[i][j] = coefs[i*n + j];
		}
	}
}

template <class T>
void UpperTriangularMatrix<T>::RandomFill() {
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			v[i][j] = (T)(rand() % 10000) / 100;
		}
	}
}
#pragma endregion 

#pragma region LowerTriangularMatrix
template <class T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(int n, bool isRandomFill) : Matrix<T>(n, n, false) {
	if (isRandomFill)
		RandomFill();
}

template <class T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(int n, T * coefs) {
	v = vector<vector<T>>(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = vector<T>(n);
		for (int j = 0; j <= i; j++)
		{
			v[i][j] = coefs[i*n + j];
		}
	}
}

template <class T>
void LowerTriangularMatrix<T>::RandomFill() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			v[i][j] = (T)(rand() % 10000) / 100;
		}
	}
}
#pragma endregion 

#pragma region SymmetricMatrix
template <class T>
SymmetricMatrix<T>::SymmetricMatrix(int n, bool isRandomFill) : Matrix<T>(n, n, false) {
	if (isRandomFill)
		RandomFill();
}


template <class T>
SymmetricMatrix<T>::SymmetricMatrix(int n, T * coefs) {
	v = vector<vector<T>>(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = vector<T>(n);
		for (int j = 0; j <= i; j++)
		{
			v[i][j] = coefs[i*n + j];
		}
	}
}

template <class T>
void SymmetricMatrix<T>::RandomFill() {
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			v[j][i] = v[i][j] = (T)(rand() % 10000) / 100;
		}
	}
}
#pragma endregion 

#pragma region DiagonalMatrix
template <class T>
DiagonalMatrix<T>::DiagonalMatrix(int n, bool isRandomFill) : Matrix<T>(n, n, false) {
	if (isRandomFill)
		RandomFill();
}


template <class T>
DiagonalMatrix<T>::DiagonalMatrix(int n, T * coefs) {
	v = vector<vector<T>>(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = vector<T>(n);
		v[i][i] = coefs[i];
	}
}

template <class T>
void DiagonalMatrix<T>::RandomFill() {
	for (int i = 0; i < n; i++)
	{
		v[i][i] = (T)(rand() % 10000) / 100;
	}
}
#pragma endregion 

#pragma region IdentityMatrix
template <class T>
IdentityMatrix<T>::IdentityMatrix(int n) : Matrix<T>(n, n, false) {
	for (int i = 0; i < n; i++)
	{
		v[i][i] = (T)1;
	}
}

#pragma endregion 

#pragma region Column
template <class T>
Column<T>::Column(int m, bool isRandomFill) : Matrix<T>(m, 1, false) {
	if (isRandomFill)
		RandomFill();
}

template <class T>
Column<T>::Column(int m, T * coefs) {
	v = vector<vector<T>>(m);
	for (int i = 0; i < m; i++)
	{
		v[i] = vector<T>(1);
		v[i][0] = coefs[i];
	}
}

template <class T>
Column<T>::Column(const Vector<T> & _vector) : Matrix<T>(_vector.Size(), 1, false){
	for (int i = 0; i < m; i++)
	{
		v[i][0] = _vector[i];
	}
}

template <class T>
void Column<T>::RandomFill() {
	for (int i = 0; i < m; i++)
	{
		v[i][0] = (T)(rand() % 10000) / 100;
	}
}
#pragma endregion

#pragma region Row
template <class T>
Row<T>::Row(int n, bool isRandomFill) : Matrix<T>(1, n, false) {
	if (isRandomFill)
		RandomFill();
}

template <class T>
Row<T>::Row(int n, T * coefs) {
	v = vector<vector<T>>(1);
	v[0] = vector<T>(n);
	for (int i = 0; i < n; i++)
	{
		v[0][n] = coefs[i];
	}
}

template <class T>
Row<T>::Row(const Vector<T> & _vector) : Matrix<T>(1, _vector.Size(), false){
	for (int i = 0; i < n; i++)
	{
		v[0][i] = _vector[i];
	}
}

template <class T>
void Row<T>::RandomFill() {
	for (int i = 0; i < n; i++)
	{
		v[0][i] = (T)(rand() % 10000) / 100;
	}
}
#pragma endregion 