#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>  
#include <sstream>
#include <cmath>
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