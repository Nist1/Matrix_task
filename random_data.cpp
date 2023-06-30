#include <cstdlib>
#include <cmath>
#include "matrix.h"
#include "random_data.h"


//сгенерировать радномное целое число из заданного диапазона
int RandomInt(int min, int max) 
{
	int x;
	x = min + std::rand() / ((RAND_MAX + 1u) / (max - min));
	return x;
}


int LengthOfInt(int x) 
{
	int a = 1;
	while (x > 0) {
		x /= 10;
		a++;
	}
	return a;
}


double GetDouble(int m, int k) 
{
	double x = k;
	for (int i = -1; i >= m; i--)
	{
		x += RandomInt(0, 9) * pow(10, i);
	}
	return x;
}


double RandomDouble(double min, double max) // новое рандомное вещественное число XD
{
	int i;
	if (min != max) {
		i = RandomInt(min, max);
	}
	else {
		return min;
	}
	int LengthOfNumber = RandomInt(LengthOfInt(i), 8);
	int maxDegree = (-1) * (LengthOfNumber - LengthOfInt(i));
	if ((LengthOfNumber - LengthOfInt(i)) == 0) {
		return i;
	}
	else return GetDouble(maxDegree, i);
}


Matrix GetRandomMatrix() 
{
	Matrix matrix;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrix.el[i * 5 + j] = RandomDouble(-100, 100);
		}
	}
	return matrix;
}