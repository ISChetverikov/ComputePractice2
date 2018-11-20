#pragma once
#include <exception>

using namespace std;

class MultiplicationMatricesException : public exception {
public:
	const char * what() const throw ()
	{
		return "These matrices are not suitable for multiplication";
	}
};

class AdditionMatricesException : public exception {
public:
	const char * what() const throw ()
	{
		return "These matrices are not suitable for addition";
	}
};

class HadamarMatricesException : public exception {
public:
	const char * what() const throw ()
	{
		return "These matrices are not suitable for Hadamar mutliplication";
	}
};

class VectorsDiffDimensionException : public exception {
public:
	const char * what() const throw ()
	{
		return "These vectors have different sizes";
	}
};

class NotSquareMatrixException : public exception {
public:
	const char * what() const throw ()
	{
		return "Matrix is not a square";
	}
};
