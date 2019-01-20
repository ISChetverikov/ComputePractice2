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

class ConcatinationMatrixException : public exception {
public:
	const char * what() const throw ()
	{
		return "Matrices are not suitable for concatination";
	}
};

class ZeroDeterminantException : public exception {
public:
	const char * what() const throw ()
	{
		return "Determinant of Matrix is zero";
	}
};

class DifferentRawsOfInputMatrixException : public exception {
public:
    const char * what() const throw ()
    {
        return "Input Matrix has different elements count of raws";
    }
};

class CanNotOpenFileException : public exception {
private:
    std::string _filename;

public:
    CanNotOpenFileException(std::string filename) {
        _filename = filename;
    }

    const char * what() const throw ()
    {
        return ("Cannot open file " + _filename).c_str();
    }
};