#include <iostream>
#include <string>
#include <array>
#include <time.h>

#include "Matrix.h"
#include "DerivedMatrix.h"

#include "Matrix.cpp"
#include "IO.cpp"
#include "Operators.cpp"
#include "DerivedMatrix.cpp"

using namespace std;

int main() {
	
	//srand((int)time(0));

	//Matrix<int> m = Matrix<int>(2, 3, true);
	//Matrix<int> n = Matrix<int>(3, 4, true);
	SymmetricMatrix<double> u = SymmetricMatrix<double>(3, true);
	SymmetricMatrix<double> v = SymmetricMatrix<double>(u);
	DiagonalMatrix<double> d = DiagonalMatrix<double>(3, true);
	IdentityMatrix<double> e = IdentityMatrix<double>(3);
	Column<double> c = Column<double>(3, true);
	Row<double> r = Row<double>(3, true);

	cout << u << endl;
	cout << d << endl;
	cout << e << endl;
	cout << c << endl;
	cout << r << endl;
	cout << r * c << endl;
	
	return 0;
}

// ?????????????????????????
// Использование с шаблонами
// Специализация функций из шаблонного класса