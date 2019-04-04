/*
Ïî ìàêñèìàëüíîìó ýëåìåíòó
Åñëè ÷åòíîå ÷èñëî ñòðîê - áàáë ñîðò, íå÷åòíîå - êâèê ñîðò
*/


#include <iostream>
#include<algorithm>

using namespace std;

void swap(int*& a, int*& b);
int getMax(int* arr, int size);
void bubbleSort(int** arr, int n, int m);
int* findLine(int** matrix, int n, int m, int key);
int** getMatrix(int n, int m);
void freeMemory(int** matrix, int n);
void setElemenets(int** matrix, int n, int m);
void display(int** matrix, int n, int m);
int* getArr(int* arr, int size);
void setMatrix(int**& matrix, int**& mtrx);
void arrsort(int** matrix, int n, int m);

int main()
{
	cout << "Enter the sizes of matrix: Ax*m" << endl;
	int n, m;
	cin >> n >> m;
	int** matrix = getMatrix(n, m);
	setElemenets(matrix, n, m);
	display(matrix, n, m);
	cout << endl;
	arrsort(matrix, n, m);
	cout << endl;
	freeMemory(matrix, n);
}

void swap(int*& a, int*& b)
{
	int* t = a;
	a = b;
	b = t;
}

int getMax(int* arr, int size)
{
	int max = 0;

	for (int i = 0; i < size; ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

void bubbleSort(int** arr, int n, int m)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (getMax(arr[j], m) > getMax(arr[j + 1], m)) 
			{
				swap(arr[j], arr[j + 1]);
			}

		}
	}
}

int* findLine(int** matrix, int n, int m, int key)
{
	for (int i = 0; i < n; ++i)
	{
		if (getMax(matrix[i], m) == key)
			return matrix[i];
	}
}

int** getMatrix(int n, int m)
{
	int** matrix = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[m];
	}

	return matrix;
}

void freeMemory(int** matrix, int n)
{
	for (int i = 0; i < n; ++i)
		delete[] matrix[i];

	delete[] matrix;
}

void setElemenets(int** matrix, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> matrix[i][j];
		}
	}
}

void display(int** matrix, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int* getArr(int* arr, int size)
{
	int* a = new int[size];
	for (int i = 0; i < size; ++i) 
	{
		a[i] = arr[i];
	}

	return a;
}

void setMatrix(int**& matrix, int**& mtrx)
{
	matrix = mtrx;
}

void arrsort(int** matrix, int n, int m)
{
	if (n % 2 == 0) 
	{
		bubbleSort(matrix, n, m);
		display(matrix, n, m);
	}
	else 
	{
		vector<int> vect(n);
		for (int i = 0; i < n; ++i)
		{
			int term = getMax(matrix[i], m);
			vect[i] = term;
		}
		sort(vect.begin(), vect.end());

		int** mtrx = new int*[n];
		for (int i = 0; i < n; ++i) 
		{
			mtrx[i] = new int[m];
			for (int j = 0; j < n; ++j) 
			{
				if (getMax(matrix[j], m) == vect[i])
					for (int q = 0; q < m; ++q)
					{
						mtrx[i][q] = matrix[j][q];
					}
			}
		}

		display(mtrx, n, m);

		freeMemory(mtrx, n);`
	}
}
