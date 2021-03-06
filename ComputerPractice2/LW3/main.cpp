#include <iostream>
#include <string>
#include <array>
#include <time.h>
#include <fstream>
#include <stdio.h>

#include "Matrix.h"
#include "DerivedMatrix.h"
#include "Vector.h"

#include "Matrix.cpp"
#include "IO.cpp"
#include "Operators.cpp"
#include "DerivedMatrix.cpp"
#include "Functions.cpp"
#include "Vector.cpp"
#include "VectorOperations.cpp"
#include "VectorFunctions.cpp"

using namespace std;

int main() {
	
	//srand((int)time(0));
	//int A[2][2] ={	{'a','b'},
	//					{'c','d'} };
	
	/*int A1[3][3] = {{0,2,1},
					{3,4,5},
					{4,1,1}};

	int A[3][3] = { {0,1,0},
					{-1,0,1},
					{1,0,0}};

	int B[3][4] = { {0,0,1,1},
					{1,0,0,3},
					{0,1,0,6}};

	Matrix<int> m = Matrix<int>(3, 3, (int *)A);
	Matrix<int> m1 = Matrix<int>(3, 3, (int *)A1);
	Matrix<int> n = Matrix<int>(3, 4, (int *)B);*/
	//Matrix<char> c = Matrix<char>(3,2, true);

	//SymmetricMatrix<double> u = SymmetricMatrix<double>(3, true);
	//SymmetricMatrix<double> v = SymmetricMatrix<double>(u);
	//DiagonalMatrix<double> d = DiagonalMatrix<double>(3, true);
	//IdentityMatrix<double> e = IdentityMatrix<double>(3);
	//Column<double> c = Column<double>(3, true);
	//Row<double> r = Row<double>(3, true);

	//cout << u << endl;
	//cout << d << endl;
	//cout << e << endl;
	//cout << c << endl;
	//cout << r << endl;
	//cout << m  << endl;
	/*cout << (Matrix<double>)m << endl;
	cout << m.Rank() << endl;*/
	
	/*try {
		cout << n * c << endl;
	}
	catch (exception & e) {
		cout << e.what() << endl;
	}
	*/
	/*int a[3] = { -1,0,0 };
	int b[3] = { 1,2,3 };

	Vector<int> v = Vector<int>(3, a);
	Vector<int> u = Vector<int>(3, b);*/
	//cout << u << endl;
	//cout << Vector<int>::Angle(v, u) << endl;
	//cout << m1.Norm() << endl;
	//cout << n.SpecificEchelonForm() << endl;
	//cout << n << endl;
	//try {
	//	auto m2 = (Matrix<double>)m1 * m1.ReverseMatrix();
	//	cout << m1.Rank() << endl;
	//	cout << m2 << endl;
	//	//cout << m * v.ToMatrix(false) << endl;
	//}
	//catch (exception e) {
	//	cout << e.what() << endl;
	//}

	//cout << (m1 % m1) << endl;

    auto filename = "test1.txt";
    auto filename2 = "test.bin";
    ////////////////////////////////////////////////////////////////
    auto m = Matrix<double>(3, 4, true);
    std::cout << m << std::endl;

    Matrix<double>::WriteToFile(filename2, m, true);
    std::cout << Matrix<double>::ReadFromFile(filename2, true) << std::endl;

    ////////////////////////////////////////
    auto v = Vector<double>(4, true);
    std::cout << v << std::endl;

    Vector<double>::WriteToFile(filename, v);
    std::cout << Vector<double>::ReadFromFile(filename) << std::endl;
}