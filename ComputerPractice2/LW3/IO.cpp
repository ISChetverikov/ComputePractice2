#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>  
#include <sstream>
#include <fstream>

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
Matrix<T> Matrix<T>::ReadFromFileBinary(std::string filename) {
    Matrix<T> matrix;
    int m = 0;
    int n = 0;
    T temp;

    std::ifstream in;
    in.open(filename, std::fstream::in | std::fstream::binary);
    if (in.is_open()) {
        in.read((char *)&m, sizeof(int));
        in.read((char *)&n, sizeof(int));

        matrix = Matrix<T>(m, n, false);

        for (int i = 0; i < matrix.m; i++)
            for (int j = 0; j < matrix.n; j++) {
                in.read((char *)&temp, sizeof(T));
                matrix[i][j] = temp;
            }

    }
    else
        throw CanNotOpenFileException(filename);
    in.close();

    return matrix;
}

template <class T>
Matrix<T> Matrix<T>::ReadFromFileText(std::string filename) {
    Matrix<T> matrix;
    std::ifstream in;

    in.open(filename);
    if (in.is_open()) {
        in >> matrix;
    }
    else
        throw CanNotOpenFileException(filename);
    in.close();

    return matrix;
}

template <class T>
Matrix<T> Matrix<T>::ReadFromFile(std::string filename, bool isBinaryMode) {
    if (isBinaryMode)
        return ReadFromFileBinary(filename);
    else
        return ReadFromFileText(filename);
}

template <class T>
void Matrix<T>::WriteToFileBinary(std::string filename, const Matrix<T> & matrix) {

    std::ofstream out;
    out.open(filename, std::fstream::out | std::fstream::binary | std::fstream::trunc);
    if (out.is_open()) {
        out.write((char *)&matrix.m, sizeof(int));
        out.write((char *)&matrix.n, sizeof(int));

        for (int i = 0; i < matrix.m; i++)
            for (int j = 0; j < matrix.n; j++)
                out.write((char *)&matrix[i][j], sizeof(T));
    }
    else
        throw CanNotOpenFileException(filename);

    out.close();
}

template <class T>
void Matrix<T>::WriteToFileText(std::string filename, const Matrix<T> & matrix) {

    std::ofstream out;
    out.open(filename);
    if (out.is_open())
    {
        out << matrix;
    }
    else
        throw CanNotOpenFileException(filename);
    out.close();
}

template <class T>
void Matrix<T>::WriteToFile(std::string filename, const Matrix<T> & matrix, bool isBinaryMode) {
    
    if (isBinaryMode)
        WriteToFileBinary(filename, matrix);
    else
        WriteToFileText(filename, matrix);
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

		iss.imbue(locale("Russian"));

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

// Vector IO

template <class T>
Vector<T> Vector<T>::ReadFromFileBinary(std::string filename) {
    Vector<double> vector;
    int n = 0;
    T temp;

    std::ifstream in;
    in.open(filename, std::fstream::in | std::fstream::binary);
    if (in.is_open()) {
        in.read((char *)&n, sizeof(int));

        vector = Vector<T>(n, false);

        for (int i = 0; i < vector.n; i++) {
            in.read((char *)&temp, sizeof(T));
            vector[i] = temp;
        }
    }
    else
        throw CanNotOpenFileException(filename);
    in.close();

    return vector;
}

template <class T>
Vector<T> Vector<T>::ReadFromFileText(std::string filename) {
    Vector<T> vector;
    std::ifstream in;

    in.open(filename);
    if (in.is_open()) {
        in >> vector;
    }
    else
        throw CanNotOpenFileException(filename);
    in.close();

    return vector;
}

template <class T>
Vector<T> Vector<T>::ReadFromFile(std::string filename, bool isBinaryMode) {
    if (isBinaryMode)
        return ReadFromFileBinary(filename);
    else
        return ReadFromFileText(filename);
}

template <class T>
void Vector<T>::WriteToFileBinary(std::string filename, const Vector<T> & vector) {
    std::ofstream out;
    out.open(filename, std::fstream::out | std::fstream::binary | std::fstream::trunc);
    if (out.is_open()) {
        out.write((char *)&vector.n, sizeof(int));

        for (int i = 0; i < vector.n; i++)
            out.write((char *)&vector[i], sizeof(T));
    }
    else
        throw CanNotOpenFileException(filename);

    out.close();
}

template <class T>
void Vector<T>::WriteToFileText(std::string filename, const Vector<T> & vector) {

    std::ofstream out;
    out.open(filename);
    if (out.is_open())
    {
        out << vector;
    }
    else
        throw CanNotOpenFileException(filename);
    out.close();
}

template <class T>
void Vector<T>::WriteToFile(std::string filename, const Vector<T> & vector, bool isBinaryMode) {

    if (isBinaryMode)
        WriteToFileBinary(filename, vector);
    else
        WriteToFileText(filename, vector);
}

template <class T>
ostream & operator << (ostream & o, const Vector<T> & vector) {
	o << vector.ToMatrix(true);

	return o;
}

template <class T>
std::istream& operator >> (std::istream& in, Vector<T> & vector) {
    T temp;
    int n = 0;
    std::vector<T> v;

    while (in >> temp) {
        v.push_back(temp);
    }

    vector = Vector<T>(v);
    return in;
}