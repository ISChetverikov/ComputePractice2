#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>  
#include <sstream>

#include "Matrix.h"
#include "Vector.h"

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

template <class T>
std::istream& operator >> (std::istream& in, Matrix<T> & matrix) {
    T temp;
    char str[1024];
    int m = 0;
    int n = 0;
    std::vector<std::vector<T>> v;

    while (in.getline(str, 1024)) {
        istringstream iss(str);
        std::vector<T> row;

        int current_n = 0;
        while (iss >> temp) {
            current_n++;
            row.push_back(temp);
        }
            
        if (current_n == 0)
            continue;

        if (n!=0 && current_n != n)
            throw DifferentRawsOfInputMatrixException();
        n = current_n;

        v.push_back(row);
        m++;
    }

    matrix = Matrix<T>(v);
    return in;
}


template <class T>
ostream & operator << (ostream & o, const Vector<T> & vector) {
	o << vector.ToMatrix(true);

	return o;
}