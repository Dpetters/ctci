#include "7.4.h"
#include <iostream>

using namespace std;

int Question_7_4::run()
{
	int x, y;
	cout << "Enter the first integer:" << endl;
	cin >> x;
	cout << "Enter the second integer:" << endl;
	cin >> y;
	cout << "Multiplication: " << Question_7_4::multiply(x, y) << endl;
	cout << "Subtraction: " << Question_7_4::subtract(x, y) << endl;
	cout << "Division: " << Question_7_4::divide(x, y) << endl;
	return 0;
}

int Question_7_4::divide(int x, int y)
{
	int sum = y;
	int count = 0;
	while (sum <= x)
	{
		sum += y;
		count++;
	}
	return count;
}

int Question_7_4::multiply(int x, int y)
{
	int sum = 0;
	for (int i = 0; i < y; i++)
	{
		sum += x;
	}
	return sum;
}

int Question_7_4::subtract(int x, int y)
{
	int result = x;
	for (int i = 0; i < y; i++)
	{
		result += -1;
	}
	return result;
}