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
	int A[3][3] ={	{1,0,1},
						{1,1,0},
						{0,1,0} };
	int B[3][4] = { {0,0,1,1},
					{1,0,0,3},
					{0,1,0,6} };
	Matrix<int> m = Matrix<int>(3, 3, (int *)A);
	Matrix<int> n = Matrix<int>(3, 4, (int *)B);

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
	cout << m.ReverseMatrix() * (Matrix<double>)m << endl;
	/*cout << (Matrix<double>)m << endl;
	cout << m.Rank() << endl;*/
	
	/*try {
		cout << n * c << endl;
	}
	catch (exception & e) {
		cout << e.what() << endl;
	}
	*/
	int a[3] = { -1,0,0 };
	int b[3] = { 1,0,0 };

	Vector<int> v = Vector<int>(3, a);
	Vector<int> u = Vector<int>(3, b);
	//cout << u << endl;
	//cout << Vector<int>::Angle(v, u) << endl;
	return 0;
}

// ?????????????????????????
// ������������� � ���������
// ������������� ������� �� ���������� ������