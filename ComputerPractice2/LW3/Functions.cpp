#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>  
#include <sstream>
#include "Matrix.h"

#include "exception.h"

using namespace std;

template <class T>
T Matrix<T>::Trace() {
	int min = (m > n) ? n : m;
	T trace = 0;

	for (int i = 0; i < min; i++)
	{
		trace += v[i][i];
	}
	
	return trace;
}

template <class T>
double Matrix<T>::Norm() {
	double norm = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			norm += v[i][j] * v[i][j];
		}
	}

	return sqrt(norm);
}