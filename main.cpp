#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <math.h>
#include <iomanip>
#include <sstream>
using namespace std;

struct Matrix {
    long double el[2][2];
};

int RandomInt(int min, int max) {
    int x;
    x = min + rand() / ((RAND_MAX + 1u) / (max - min));
    return x;
}

void FillZero(int* mas, int len)
{
    for (int i = 0; i < len; i++) {
        mas[i] = 0;
    }
}

double GetDouble(int l, int m, int* arr) 
{
    double x = 0;
    int k = 0;
    for (int i = 1; i <= l; i++)
    {
        x += arr[k++] * pow(10, m - i);
    }
    return x;
}

double RandomDouble(int min, int max)
{
    int lengthOfNumber = RandomInt(1, 8);
    int arr[8];
    FillZero(arr, 8);
    int maxDegree = RandomInt(0, lengthOfNumber);
    for (int i = 0; i < lengthOfNumber; i++)
    {
        arr[i] = RandomInt(0, 9);
    }
    return GetDouble(lengthOfNumber, maxDegree, arr);
}

void TestPlusPlusRange()
{
    double num = RandomDouble(15, 27);
    if (num >= 15 && num <= 27) {
        cout << "Test 1 passed: " << num << " is in range (15, 27)" << endl;
    }
    else {
        cout << "Test 1 NOT passed: " << num << " is NOT in range (15, 27)" << endl;
    }
}

void TestMinusMinusRange()
{
    double num = RandomDouble(-52, -12);
    if (num >= -52 && num <= -12) {
        cout << "Test 2 passed: " << num << " is in range (-52, -12)" << endl;
    }
    else {
        cout << "Test 2 NOT passed: " << num << " is NOT in range (-52, -12)" << endl;
    }
}

void TestPlusMinusRange()
{
    double num = RandomDouble(-33, 80);
    if (num >= -33 && num <= 80) {
        cout << "Test 3 passed: " << num << " is in range (-33, 80)" << endl;
    }
    else {
        cout << "Test 3 NOT passed: " << num << " is NOT in range (-33, 80)" << endl;
    }
}

void TestZeroRange()
{
    double num = RandomDouble(0, 0);
    if (num == 0) {
        cout << "Test 4 passed: " << num << " is 0" << endl;
    }
    else {
        cout << "Test 4 NOT passed: " << num << " is 0" << endl;
    }
}

void TestOneZeroRange()
{
    double num = RandomDouble(0, 25);
    if (num >= 0 && num <= 25) {
        cout << "Test 5 passed: " << num << " is in range (0, 25)" << endl;
    }
    else {
        cout << "Test 5 NOT passed: " << num << " is NOT in range (0, 25)" << endl;
    }

    num = RandomDouble(-30, 0);
    if (num >= -30 && num <= 0) {
        cout << "Test 6 passed: " << num << " is in range (-30, 0)" << endl;
    }
    else {
        cout << "Test 6 NOT passed: " << num << " is NOT in range (-30, 0)" << endl;
    }
}

void TestEqualRange()
{
    double num = RandomDouble(15, 15);
    if (num == 15) {
        cout << "Test 7 passed: " << num << " is 15" << endl;
    }
    else {
        cout << "Test 7 NOT passed: " << num << " is NOT 15" << endl;
    }
}

void TestSmallRange()
{
    double num = RandomDouble(-1, 1);
    if (num >= -1 && num <= 1) {
        cout << "Test 8 passed: " << num << " is in range (-1, 1)" << endl;
    }
    else {
        cout << "Test 8 NOT passed: " << num << " is NOT in range (-1, 1)" << endl;
    }
}

void TestRandomDouble()
{
    TestPlusPlusRange();
    TestMinusMinusRange();
    TestPlusMinusRange();
    TestZeroRange();
    TestOneZeroRange();
    TestEqualRange();
    TestSmallRange();
}

int main()
{
    Matrix mat;
    int numLen, a, b;
    int min, max;
    srand(time(nullptr));
    TestRandomDouble();
}   
