#include <iostream>
#include<algorithm>

using namespace std;

void swap(int& a, int& b);
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
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
	cout << "Enter the sizes of matrix: Ax*m" << endl;
	int n, m;
	cin >> n >> m;
	int** matrix = getMatrix(n, m);
	setElemenets(matrix, n, m);
	cout << std::endl << endl << endl;
	display(matrix, n, m);
	cout << endl;
	arrsort(matrix, n, m);
	cout << endl;
	freeMemory(matrix, n);

	system("pause");
	return 0;
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
		int* VECTOR = new int[n];
		
		for (int i = 0; i < n; ++i)
		{
			int term = getMax(matrix[i], m);
			VECTOR[i] = term;
		}

		quickSort(VECTOR, 0, n - 1);

		int** mtrx = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			mtrx[i] = new int[m];
			for (int j = 0; j < n; ++j)
			{
				if (getMax(matrix[j], m) == VECTOR[i])
					for (int q = 0; q < m; ++q)
					{
						mtrx[i][q] = matrix[j][q];
					}
			}
		}

		delete[] VECTOR;
		display(mtrx, n, m);

		freeMemory(mtrx, n); 
	}
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];     
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;   
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void swap(int& a, int& b) 
{
	int t = a;
	a = b;
	b = t;
}
