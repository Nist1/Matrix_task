#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <math.h>
#include <iomanip>
#include <sstream>
using namespace std;

int RandomInt(int, int);

struct Matrix {
    long double el[2][2];
};

int RandomInt(int min, int max) {
    int x;
    x = min + rand() / ((RAND_MAX + 1u) / (max - min));
    return x;
}


/*double Range(double min,double max, double aDouble, int point,int length) {
    string len9(point + 1,'9');

}*/


/*double GetDouble(double min,double max,int length)
{
    for (int i = 0; i < length; i++) {
        if (i == 0) {
        a += to_string(RandomInt(-9, 10));
        } else {
            a += to_string(RandomInt(0, 9));
        }
        if (i == point) {
        a += ".";
        }
        cout << a << "\n";
    }
    double aDouble = atof(a.c_str());
    return aDouble;
    Range(min, max, aDouble, point, length);
}*/

//void FillZero(double* mas, int len)  // функция заполняет массив нулями
//{
//    for (int i = 0; i < len; i++) {
//        mas[i] = 0;
//    }
//}

//void Print(double* mas, int len) //функция распечатывает массив вещественных чисел
//{
//    for (int i = 0; i < len; i++) {
//        cout << "Number " << i << " = " << mas[i] << "\n";
//    }
//}

//void CountSum(double* mas, int len, int& sum) //функция считает сумму всех элементов вещественного массива
//{
//    for (int i = 0; i < len; i++) {
//        sum += mas[i];
//    }
//}

//long long TestInt(long long length) 
//{
//    string a = "";
//    for (int i = 0; i < length; i++) {
//        int alfa = (RandomInt(-9, 10));
//        if ((i == 0) && (alfa != 0)) {
//            a += to_string(alfa);
//        }
//        else a += to_string(RandomInt(0, 9));
//    }
//    return atof(a.c_str());
//}

//long double TestDouble(int length) 
//{
//    string a = "";
//    int point = GeneratePointPosition(length);
//    for (int i = 0; i < length; i++) {
//        int alfa = (RandomInt(-9, 10));
//        if ((i == 0) && (alfa != 0)) {
//            a += to_string(alfa);
//        }
//        else
//            a += to_string(RandomInt(0, 9));
//    }
//    a.insert(point, ".");
//    if (a.length() == length) {
//        a.erase(length - 1, 1);
//    }
//    cout << a << "\n";
//    return atof(a.c_str());
//}

int GeneratePointPosition(int length) //Генерация позиции точки в вещественном числе
{
    int pointPos = RandomInt(1, length + 1);
    if (pointPos == length + 1) {
        pointPos -= 1;
    }
    return pointPos;
}

double NumberGenerator(int length, int pointPos) //Генерация вещественного числа
{
    string strNum = "";
    strNum += to_string(RandomInt(1, 10)); //Генерируем первую цифру вещественного числа
    for (int i = 1; i < length; i++) {
        strNum += to_string(RandomInt(0, 10)); //Генерируем оставшиеся цифры вещественного числа
    }
    strNum.insert(pointPos, "."); //Вставляем точку
    if (RandomInt(0, 2) == 0) {
        strNum.insert(0, "-"); //Определяем знак числа
    }
    double num = stod(strNum); //Конвертация строки в вещественное число
    return num;
}

int main()
{
    Matrix mat;
    int numLen, a, b;
    double min, max;
    srand(time(nullptr));
    //std::cout << "Введите размерность матрицы:";
    //std::cin >> a >> b;
    cout << "Длина числа - ";
    cin >> numLen;
    for (int i = 0; i < 100; i++) {
        cout << NumberGenerator(numLen, GeneratePointPosition(numLen)) << endl;
    }
    
    //for (int i = 0; i < 2; i++) {
    //    for (int j = 0; j < 2; j++) {
    //        mat.el[i][j] = TestDouble(numLen);
    //        //std::cout << std::setprecision(6) << mat.el[i][j] << " ";
    //    }
    //    std::cout << "\n";
    //}
}