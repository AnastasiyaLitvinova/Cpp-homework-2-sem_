#include<iostream>
#include"String.h"

using namespace std;
using namespace ArrayExtension;

bool searchForItems(int, int);
int* separationArray(int*, int*, int, int&, predicate);
int* DeleteElements(int*, int, int&);

int main()
{
	cout << "Enter dimension array: ";
	int n = number();
	system("cls");

	int* array = nullptr;

	try
	{
		array = allocateMemory(n);
	}
	catch (const invalid_argument& ex)
	{
		cerr << "Invalid argument: " << ex.what() << '\n';
	}



	cout << "Surce array" << endl;
	randomArray(array, n);
	displayArray(array, n);

	int dim = 0;

	int* newArray = allocateMemory(n);
	int* Array = allocateMemory(n);

	Array = separationArray(array, newArray, n, dim, searchForItems);
	if (dim > 0)
	{
		cout << "Array of positive even elements that are located in front of negative elements" << endl;
		displayArray(newArray, dim);
	}
	else
	{
		cout << "There are no positive even elements in the array, which are located in front of the negative elements." << endl;

	}

	int rasm = 0;
	mergeSort(Array, 0, n - dim - 1);

	int* Array1 = allocateMemory(n - dim);
	Array1 = DeleteElements(Array, n - dim, rasm);
	mergeSort(Array1, 0, rasm - 2, Hexadecimal);

	cout << "Sorted array in descending number of characters (A, B, C, D, E, F) in hexadecimal notation, without duplicate elements." << endl;
	displayArray(Array1, rasm - 1);

	system("Pause");

	return 0;
}

bool searchForItems(int a, int b)
{
	if (a % 2 == 0 && a > 0 && b < 0)
	{
		return true;
	}

	return false;
}

int* separationArray(int* array, int* array2, int n, int& dim, predicate key)
{
	for (int i = 0; i < n; i++)
	{
		if (key(array[i], array[i + 1]))
		{
			dim++;
		}
	}

	int* result = allocateMemory(n - dim);

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (key(array[i], array[i + 1]))
		{
			array2[j] = array[i];
			j++;
		}
		else
		{
			result[k] = array[i];
			k++;
		}
	}

	delete[] array;

	return result;
}

int* DeleteElements(int* array, int n, int& dim)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}
	if (array == nullptr)
	{

		throw std::invalid_argument("Array can not be null.");
	}

	dim = 1;

	for (int i = 0; i < n; i++)
	{
		if (array[i] != array[i + 1])
		{
			dim++;
		}
	}

	int* result = allocateMemory(dim);

	int m = 0;

	for (int i = 0; i < n - m - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			m++;

			for (int j = i; j < n; j++)
			{
				array[j] = array[j + 1];
			}
			i--;
		}
	}

	for (int i = 0; i < dim; i++)
	{
		result[i] = array[i];
	}

	delete[] array;

	return result;
}