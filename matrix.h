#ifndef H_MATRIX
#define H_MATRIX


struct Matrix {
	long double el[25];
};


// ��������� ������� ������� �� 1 �� 25
void FillMatrix(Matrix& matrix);


// ����������� �������
void PrintMatrix(const Matrix&);


#endif // H_MATRIX