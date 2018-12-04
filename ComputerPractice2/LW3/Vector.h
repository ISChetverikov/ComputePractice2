#pragma once
#include <vector>

#include "Matrix.h"
using namespace std;

template <class T>
class Vector {

protected:
	int n;
	vector<T> v;

public:
	Vector(int n, bool isRandomFill);
	Vector(int n, T * coefs);
	void RandomFill();

	Matrix<T> ToMatrix(bool isRaw) const;
	double Norm2();
	T NormMax();

	T& operator [](int i);
	const T& operator [](int i) const;
	int Size() const;
	static double Angle(Vector & left, Vector & right); 

	Vector operator * (const T r) ; 
	Vector operator + (const Vector & other);
	Vector operator - (const Vector & other); 

	T operator * (const Vector & other); // Scalar
	Vector operator & (const Vector & other); // Hadamar
	Matrix<T> operator ^ (const Vector & other); // External

};

template <class T>
ostream & operator << (ostream & o, const Vector<T> & vector);   

//template <class T>
//Matrix<T> operator * (const Matrix<T> & matrix, const Vector<T> & vector);
//template <class T>
//Matrix<T> operator * (const Vector<T> & vector, const Matrix<T> & matrix);