#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>  
#include <sstream>
#include "Matrix.h"

#include "exception.h"

using namespace std;

template<class T>
string Matrix<T>::toString() const {
	stringstream ss;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ss << setw(15) << setprecision(4) << fixed << v[i][j];
		}

		ss << "\n";
	}

	return ss.str();
}

template <class T>
ostream & operator << (ostream & o, const Matrix<T> & matrix) {
	o << matrix.toString();

	return o;
}
