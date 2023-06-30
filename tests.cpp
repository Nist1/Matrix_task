#include "tests.h"
#include "random_data.h"
#include <iostream>
#include <cmath>


void TestDoubleInterval() 
{

	double num = RandomDouble(2, 3);
	if ((num < 2) || (num > 3)) {
		std::cout << "Number " << num << " is out of interval (" << 2 << ", " << 3 << ") " << "\n";
	}
	else
		std::cout << "Everything is okay in {2,3} " << num << "\n";
}


double GetStep(double min, double max) 
{
	return (max - min) / 10;
}


int GetDiapasonIndex(double min, double max, double randomNum)
{
	if (randomNum < min || randomNum > max) {
		return -1;
	}
	double step = GetStep(min, max);
	int index = (randomNum - min) / step;
	if (randomNum == max) {
		index = 9;
	}
	return index;
}


void Count(int arr[10], double min, double max, double randomNum) 
{
	int i = GetDiapasonIndex(min, max, randomNum);
	arr[i] += 1;
}


int sumMas(int l, int* arr) 
{
	int sum = 0;
	for (int i = 0; i < l; i++) {
		sum += arr[i];
	}
	return sum;
}


void FillZero(int* mas, int len) 
{
	for (int i = 0; i < len; i++) {
		mas[i] = 0;
	}
}


void TestDoubleWithZeroEdge() 
{
	std::cout << "{-20,0} " << RandomDouble(-20, 0) << "\n";
	//if (a<-20)||(a
	//std::cout
}


void TestDoubleMinDiff() 
{	//тестируем различные границы по знакам
	std::cout << "{-100,-99} " << RandomDouble(-100, -99) << "\n";
}


void TestDoubleMinPlus() 
{	//тестируем различные границы по знакам
	std::cout << "{-100,100} " << RandomDouble(-100, 100) << "\n";
}


void TestDoubleSame() 
{
	std::cout << "{1,1} " << RandomDouble(1, 1) << "\n";
}

void OutputTest(int sum, std::string a) 
{
	//std::cout<<"Сумма элементов = " << sum <<"\n";
	if (sum == 1000000) {
		std::cout << a << " = OK" << "\n";
	}
	else {
		std::cout << a << " = FAILED" << "\n";
		std::cout << "Lost Numbers = " << 1000000 - sum << "\n";
	}
}


void OutputArrayOfRangedNumbers(int* arr, double range1, double range2, double step) 
{
	/*std::cout<<"step = " << step << "\n";
	for (int i = 0;i<10;i++) {
		if (range1+step>range2) {
		std::cout << "{ " << range1 << "," << range2 << "} "  << arr[i] << " | ";
		} else {
		std::cout << "{ " << range1 << "," << range1+step << "} "  << arr[i] << " | ";
		}
		std::cout <<  100000 - arr[i] <<" | "<< fabs((100000 - arr[i])/100000.0 *100) << "%" << "\n";
	range1+=step;
}*/
}


void TestUniformDistribution_SimmetricRange() 
{
	int arr[10];
	FillZero(arr, 10);
	double min = -59;
	double max = 59;
	for (int i = 0; i < 1000000; i++) {
		double k = RandomDouble(min, max);
		Count(arr, min, max, k);
	}
	OutputArrayOfRangedNumbers(arr, min, max, GetStep(min, max));
	int sum = sumMas(10, arr);
	std::string a = "TestUniformDistributionSimmetricRange";
	OutputTest(sum, a);
}


void TestUniformDistribution_SimmetricRange2() 
{
	int arr[10];
	FillZero(arr, 10);
	double min = -100;
	double max = 100;
	for (int i = 0; i < 1000000; i++) {
		double k = RandomDouble(min, max);
		Count(arr, min, max, k);
	}
	OutputArrayOfRangedNumbers(arr, min, max, GetStep(min, max));
	int sum = sumMas(10, arr);
	std::string a = "TestUniformDistributionSimmetricRange2";
	OutputTest(sum, a);
}


void TestUniformDistribution_NegativeRange()
{
	int arr[10];
	FillZero(arr, 10);
	double min = -110;
	double max = -35;
	for (int i = 0; i < 1000000; i++) {
		double k = RandomDouble(min, max);
		Count(arr, min, max, k);
	}
	OutputArrayOfRangedNumbers(arr, min, max, GetStep(min, max));
	int sum = sumMas(10, arr);
	std::string a = "testNegativeDiapason";
	OutputTest(sum, a);
}


void TestUniformDistribution_PositiveRange() 
{
	int arr[10];
	FillZero(arr, 10);
	double min = 40;
	double max = 50;
	for (int i = 0; i < 1000000; i++) {
		double k = RandomDouble(min, max);
		Count(arr, min, max, k);
	}
	OutputArrayOfRangedNumbers(arr, min, max, GetStep(min, max));
	int sum = sumMas(10, arr);
	std::string a = "TestPositiveNumbers";
	OutputTest(sum, a);
}


void ExpectedValue(int expected, int actual, std::string name) 
{
	if (expected != actual) {
		std::cout << name << " - FAILED \n EXPECTED value = " << expected << " Actual value = " << actual << "\n";
	}
	else {
		std::cout << name << " - OK \n";
	}
}


void TestGetDiapasonIndex_inside() 
{
	int i = GetDiapasonIndex(-15, 35, 1);
	ExpectedValue(3, i, "TestGetDiapasonIndex_inside");
}


void TestGetDiapasonIndex_min() 
{
	int i = GetDiapasonIndex(-15, 35, -15);
	ExpectedValue(0, i, "TestGetDiapasonIndex_min");
}


void TestGetDiapasonIndex_max() 
{
	int i = GetDiapasonIndex(-15, 35, 35);
	ExpectedValue(9, i, "TestGetDiapasonIndex_max");
}


void TestGetDiapasonIndex_outsideLeft() 
{
	int i = GetDiapasonIndex(-15, 35, -40);
	ExpectedValue(-1, i, "TestGetDiapasonIndex_outsideLeft");
}


void TestGetDiapasonIndex_outsideRight() 
{
	int i = GetDiapasonIndex(-15, 35, 40);
	ExpectedValue(-1, i, "TestGetDiapasonIndex_outsideRight");
}


void TestGetDiapasonIndex_binEdge() 
{
	int i = GetDiapasonIndex(-15, 35, 5);
	ExpectedValue(4, i, "TestGetDiapasonIndex_binEdge");
}


void TestGetDiapasonIndex_closeToMax() 
{
	int i = GetDiapasonIndex(-15, 35, 34.9);
	ExpectedValue(9, i, "TestGetDiapasonIndex_closeToMAx");
}


//распределение чисел должно быть равномерным
void TestUniformDistribution() 
{
	TestUniformDistribution_SimmetricRange();
	TestUniformDistribution_SimmetricRange2();
	TestUniformDistribution_PositiveRange();
	TestUniformDistribution_NegativeRange();
}


void TestGetDiapasonIndex() 
{
	TestGetDiapasonIndex_inside();
	TestGetDiapasonIndex_min();
	TestGetDiapasonIndex_max();
	TestGetDiapasonIndex_outsideRight();
	TestGetDiapasonIndex_outsideLeft();
	TestGetDiapasonIndex_binEdge();
	TestGetDiapasonIndex_closeToMax();

}


void TestInt(int min, int max) 
{
	std::cout << RandomInt(min, max);
}


void RunAllTests() 
{
	TestUniformDistribution();
	TestGetDiapasonIndex();
}