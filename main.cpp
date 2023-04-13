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

double GerRandomDouble(int min, int max)
{
    double num = RandomInt(min, max);
    double finalNum = num / abs(max) + abs(RandomInt(min, max));
    return finalNum;
}

void TestPlusPlusRange()
{
    double num = GerRandomDouble(15, 27);
    if (num >= 15 && num <= 27) {
        cout << "Test 1 passed: " << num << " is in range (15, 27)" << endl;
    }
    else {
        cout << "Test 1 not passed: " << num << " is not in range (15, 27)" << endl;
    }
}

void TestMinusMinusRange()
{
    double num = GerRandomDouble(-52, -12);
    if (num >= -52 && num <= -12) {
        cout << "Test 2 passed: " << num << " is in range (-52, -12)" << endl;
    }
    else {
        cout << "Test 2 not passed: " << num << " is not in range (-52, -12)" << endl;
    }
}

void TestPlusMinusRange()
{
    double num = GerRandomDouble(-33, 80);
    if (num >= -33 && num <= 80) {
        cout << "Test 3 passed: " << num << " is in range (-33, 80)" << endl;
    }
    else {
        cout << "Test 3 not passed: " << num << " is not in range (-33, 80)" << endl;
    }
}

void TestZeroRange()
{
    double num = GerRandomDouble(0, 0);
    if (num == 0) {
        cout << "Test 4 passed: " << num << " is 0" << endl;
    }
    else {
        cout << "Test 4 not passed: " << num << " is 0" << endl;
    }
}

void TestOneZeroRange()
{
    double num = GerRandomDouble(0, 25);
    if (num >= 0 && num <= 25) {
        cout << "Test 5 passed: " << num << " is in range (0, 25)" << endl;
    }
    else {
        cout << "Test 5 not passed: " << num << " is not in range (0, 25)" << endl;
    }

    num = GerRandomDouble(-30, 0);
    if (num >= -30 && num <= 0) {
        cout << "Test 6 passed: " << num << " is in range (-30, 0)" << endl;
    }
    else {
        cout << "Test 6 not passed: " << num << " is not in range (-30, 0)" << endl;
    }
}

void TestEqualRange()
{
    double num = GerRandomDouble(15, 15);
    if (num == 15) {
        cout << "Test 7 passed: " << num << " is 15" << endl;
    }
    else {
        cout << "Test 7 not passed: " << num << " is not 15" << endl;
    }
}

void TestSmallRange()
{
    double num = GerRandomDouble(-1, 1);
    if (num >= -1 && num <= 1) {
        cout << "Test 8 passed: " << num << " is in range (-1, 1)" << endl;
    }
    else {
        cout << "Test 8 not passed: " << num << " is not in range (-1, 1)" << endl;
    }
}

void RandomRangeTest()
{
    int min = RandomInt(-10000, 10000);
    int max = RandomInt(-10000, 10000);
    if (min > max) {
        int tmp = max;
        max = min;
        min = max;
    }
    double num = GerRandomDouble(min, max);
    if (num > -33 && num < 80) {
        cout << "Random test passed: " << num << " is in range ("<< min << ' , ' << max << ")" << endl;
    }
    else {
        cout << "Random test not passed: " << num << " is not in range (" << min << ' , ' << max << ")" << endl;
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
    RandomRangeTest();
}

int main()
{
    Matrix mat;
    int numLen, a, b;
    int min, max;
    srand(time(nullptr));
    TestRandomDouble();
}   