#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Matrix
{
public:
	// Matrix.cpp
	//////////////////////
	Matrix(int m, int n, bool isRandomFill);
	Matrix(int m, int n, T * coefs);
	Matrix(const Matrix & m);
	~Matrix();
	//////////////////////

protected:
	int m; 
	int n;
	vector<vector<T>> v;

protected:

public:

	// Operators.cpp
	///////////////////////////////////////
	Matrix operator *= (const T r) const;
	Matrix operator + (const Matrix other);
	Matrix operator - (const Matrix other);
	Matrix operator * (const Matrix other);
	Matrix operator ^ (const Matrix other);// Hadamar production
	///////////////////////////////////////

	// IO.cpp
	string toString() const;
	////////////////////////
};

// IO.cpp
/////////////////////////////////////////
template <class T>
ostream & operator << (ostream & o, const Matrix<T> & matrix);
///////////////////////////////////////

// Operators.cpp
////////////////////////////////////////
template <class T, class Y>
Matrix<T> operator * (const Y r, const Matrix<T>& matrix);
template <class T, class Y>
Matrix<T> operator * (const Matrix<T>& matrix, const Y r);
///////////////////////////////////////////


