#ifndef H_MATRIX
#define H_MATRIX


struct Matrix {
	long double el[25];
};


// Заполнить матрицу числами от 1 до 25
void FillMatrix(Matrix& matrix);


// Распечатать матрицу
void PrintMatrix(const Matrix&);


#endif // H_MATRIX