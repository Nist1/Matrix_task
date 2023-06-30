#include <ctime>
#include <cstdlib>
#include "tests.h"
#include "matrix.h"
#include "random_data.h"


int main()
{
	std::srand(std::time(nullptr));
	//RunAllTests();
	Matrix matrix = GetRandomMatrix();
	PrintMatrix(matrix);
}