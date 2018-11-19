#pragma once
#include <exception>

using namespace std;

class MultiplicationMatricesException : public exception {
	const char * what() const throw ()
	{
		return "These matrices are not suitable for multiplication";
	}
};

class AdditionMatricesException : public exception {
	const char * what() const throw ()
	{
		return "These matrices are not suitable for addition";
	}
};

class HadamarMatricesException : public exception {
	const char * what() const throw ()
	{
		return "These matrices are not suitable for Hadamar mutliplication";
	}
};