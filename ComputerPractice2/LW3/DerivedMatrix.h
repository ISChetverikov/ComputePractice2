#pragma once
#include "Matrix.h"

template <class T>
class UpperTriangularMatrix : public Matrix<T> {
	using Matrix<T>::m;
	using Matrix<T>::n;
	using Matrix<T>::v;

public:
	// DerivedMatrix.cpp
	//////////////////////
	UpperTriangularMatrix(int n, bool isRandomFill); 
	UpperTriangularMatrix(int n, T * coefs);

	void RandomFill();
	//////////////////////
};

template <class T>
class LowerTriangularMatrix : public Matrix<T> { 
	using Matrix<T>::m;
	using Matrix<T>::n;
	using Matrix<T>::v;

public:
	// DerivedMatrix.cpp
	//////////////////////
	LowerTriangularMatrix(int n, bool isRandomFill);
	LowerTriangularMatrix(int n, T * coefs);

	void RandomFill();
	//////////////////////
};

template <class T>
class SymmetricMatrix : public Matrix<T> {
	using Matrix<T>::m;
	using Matrix<T>::n;
	using Matrix<T>::v;

public:
	// DerivedMatrix.cpp
	//////////////////////
	SymmetricMatrix(int n, bool isRandomFill);
	SymmetricMatrix(int n, T * coefs);

	void RandomFill();
	//////////////////////
};

template <class T>
class DiagonalMatrix : public Matrix<T> {
	using Matrix<T>::m;
	using Matrix<T>::n;
	using Matrix<T>::v;

public:
	// DerivedMatrix.cpp
	//////////////////////
	DiagonalMatrix(int n, bool isRandomFill);
	DiagonalMatrix(int n, T * coefs);

	void RandomFill();
	//////////////////////
};

template <class T>
class IdentityMatrix : public Matrix<T> {
	using Matrix<T>::m;
	using Matrix<T>::n;
	using Matrix<T>::v;

public:
	// DerivedMatrix.cpp
	//////////////////////
	IdentityMatrix(int n);
	////////////////////// 
};

template <class T>
class Column : public Matrix<T> {
	using Matrix<T>::m;
	using Matrix<T>::n;
	using Matrix<T>::v;

public:
	// DerivedMatrix.cpp
	//////////////////////
	Column(int m, bool isRandomFill);
	Column(int m, T * coefs);

	void RandomFill();
	//////////////////////
};

template <class T>
class Row : public Matrix<T> {
	using Matrix<T>::m;
	using Matrix<T>::n;
	using Matrix<T>::v;

public:
	// DerivedMatrix.cpp
	//////////////////////
	Row(int n, bool isRandomFill);
	Row(int n, T * coefs); 

	void RandomFill();
	//////////////////////
};