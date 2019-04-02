#include <iostream>
#include"FractionNumbers.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter the ammount of array elements" <<endl;
	cin >> n;

	if (n < 1)
	{
		throw invalid_argument("Invalid ammount of array elements!");
	}
	cout << "Enter the array elements:" <<endl;
	FractionNumber* arr = new FractionNumber[n];
	int a, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	system("cls");

	cout << "Your array:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int numerator;
	cout << "Search for rational number by numerator: " << endl;
	cout << "Enter the numerator: " << endl;
	cin >> numerator;
	FractionNumber term;
	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i].GetNumerator() == numerator)
		{
			term = arr[i];
			flag = false;
			break;
		}
	}

	if (!flag)
	{
		cout << term << endl;
	}
	else cout << "No such element" << endl;

	system("pause");
	system("cls");
	cout << "Sort by a denominator" << endl;
	

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j].GetDenominator() < arr[j + 1].GetDenominator()) 
			{
				FractionNumber t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;

	system("pause");
	return 0;
}