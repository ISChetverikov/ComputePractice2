#include "../LW3/Matrix.h"
#include "../LW3/Vector.h"
#include "../LW3/Matrix.cpp"
#include "../LW3/Operators.cpp"
#include "../LW3/Functions.cpp"
#include "../LW3/IO.cpp"
#include "PCA.h"
#include <iostream>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");

    auto m = Matrix<double>::ReadFromFile("data.txt");
    auto res = PCA::DoNipalsRoutine(m, 12);
    double TRVC = PCA::GetTRVC(res, 12);

    return 0;
}