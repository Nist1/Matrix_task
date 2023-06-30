#include <iostream>
#include "matrix.h"
#include <iomanip>


void FillMatrix(Matrix& matrix) 
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrix.el[i * 5 + j] = i * 5 + j + 1;
		}
	}
}


void PrintMatrix(const Matrix& matrix)
{
	int counter = 0;
	for (int i = 0; i < 25; i++) {
		std::cout << std::setw(8) << matrix.el[i] << " ";
		counter++;
		if (counter % 5 == 0) {
			std::cout << "\n";
		}
	}
}