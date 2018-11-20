#pragma once
#include <vector>
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

	void RandomFill();
	////////////////////// 
	  
protected:
	int m; 
	int n;
	vector<vector<T>> v;

public:

	// Operators.cpp
	///////////////////////////////////////
	Matrix operator * (const T r) const;
	Matrix operator + (const Matrix other);
	Matrix operator - (const Matrix other);  
	Matrix operator * (const Matrix other);
	Matrix operator & (const Matrix other);// Hadamar production
	///////////////////////////////////////

	// Functions.cpp
	//////////////////////////////////////
	T Trace();
	double Norm(); 
	//////////////////////////////////////

	// IO.cpp
	string toString() const;
	////////////////////////
};

// IO.cpp
/////////////////////////////////////////
template <class T>
ostream & operator << (ostream & o, const Matrix<T> & matrix); 
///////////////////////////////////////
