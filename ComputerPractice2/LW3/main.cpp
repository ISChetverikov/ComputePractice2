#include <iostream>
#include <string>
#include <array>
#include <time.h>

#include "Matrix.h"
#include "Matrix.cpp"
#include "IO.cpp"
#include "Operators.cpp"

using namespace std;

int main() {
	
	srand((int)time(0));

	Matrix<int> m = Matrix<int>(2, 3, true);
	Matrix<int> n = Matrix<int>(3, 4, true);
	
	cout << m << endl;
	cout << n << endl;
	cout << m * 6;
	
	return 0;
}