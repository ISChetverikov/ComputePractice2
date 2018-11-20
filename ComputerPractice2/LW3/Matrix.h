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
	  
	operator Matrix<double>() const;
	vector<T>& operator [](int i);
	const vector<T>& operator [](int i) const;
	void RandomFill();
	Matrix<T> SubMatrix(int m_start, int n_start, int m_count, int n_count);
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
	Matrix operator * (const Matrix & other);  
	Matrix operator & (const Matrix other);// Hadamar production
	Matrix operator | (const Matrix & other);
	///////////////////////////////////////

	// Functions.cpp
	//////////////////////////////////////
	T Trace();
	double Norm();
	double Determinant();
	Matrix Transpose();
	int Rank();
	Matrix<double> ReverseMatrix();
	Matrix<double> EchelonForm();
	Matrix<double> EchelonForm(int & rank);
	//////////////////////////////////////

	// IO.cpp
	string toString() const;
	////////////////////////
};

template <class T, class Y>
Matrix<double> operator * (const Matrix<T> & left, const Matrix<Y> & right);

// IO.cpp
/////////////////////////////////////////  
template <class T> 
ostream & operator << (ostream & o, const Matrix<T> & matrix); 
///////////////////////////////////////
