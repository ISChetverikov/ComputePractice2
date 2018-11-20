#include <iostream>
#include <string>
#include <array>
#include <time.h>

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

	//Matrix<int> m = Matrix<int>(2, 3, true);
	Matrix<double> n = Matrix<double>(3, 4, true);
	//SymmetricMatrix<double> u = SymmetricMatrix<double>(3, true);
	//SymmetricMatrix<double> v = SymmetricMatrix<double>(u);
	DiagonalMatrix<double> d = DiagonalMatrix<double>(3, true);
	IdentityMatrix<double> e = IdentityMatrix<double>(3);
	Column<double> c = Column<double>(3, true);
	Row<double> r = Row<double>(3, true);

	//cout << u << endl;
	//cout << d << endl;
	//cout << e << endl;
	//cout << c << endl;
	//cout << r << endl;
	//cout << (u & d);
	/*try {
		cout << n * c << endl;
	}
	catch (exception & e) {
		cout << e.what() << endl;
	}
	*/
	int a[3] = { 1,2,3 };
	int b[3] = { 2,3,4 };

	Vector<int> v = Vector<int>(3, a);
	Vector<int> u = Vector<int>(3, b);
	cout << u << endl;
	cout << (u.ToMatrix(true).Norm()) << endl;
	return 0;
}

// ?????????????????????????
// Использование с шаблонами
// Специализация функций из шаблонного класса