#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

#include "Vector.h"
#include "exception.h"


using namespace std;

template <class T>
double Vector<T>::Norm2() {
	double norm = 0;

	for (int i = 0; i < n; i++)
	{
		norm += v[i] * v[i];
	}

	return sqrt(norm);
}

template <class T>
T Vector<T>::NormMax() {
	double norm = 0;

	for (int i = 0; i < n; i++)
	{
		T abs = (v[i] >= 0) ? v[i] : -v[i];
		if (abs > norm)
			norm = abs;
	}

	return norm;
}

template <class T>
double Vector<T>::Angle(Vector<T> & left, Vector<T> & right) {
	return acos((double)(left * right) / left.Norm2() / right.Norm2()) * 180 / M_PI;
}