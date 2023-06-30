#ifndef H_RANDOM_DATA
#define H_RANDOM_DATA


#include "matrix.h"


// —генерировать случайное вещественное число.
double RandomDouble(double min, double max);


// —генерировать случайное целое число.
int RandomInt(int min, int max);


//—генерировать случайную матрицу
Matrix GetRandomMatrix();


#endif // H_RANDOM_DATA