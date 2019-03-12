#pragma once
namespace ArrayExtension
{
	typedef bool(*Predicate)(int);
	typedef double(*Rule)(int);
	typedef int(*key)(int);
	typedef int(*keyD)(double);
	typedef bool(*Key)(char, int);
	typedef bool(*predicate)(int, int);


	int* allocateMemory(int);

	double* allocateMemoryDouble(int);

	void inputArray(int *, int);

	void inputArray(double *, int);

	void randomArray(int *, int);

	void displayArray(int *, int);

	void displayArray(double *, int);

	void bubbleSort(int *, int);

	void bubbleSort(int*, int*, int);

	void bubbleSort(double*, int*, int, key);

	void bubbleSort(int*, int*, int, int*, int);

	void bubbleSort(int *, int, key);
	//void bubbleSort(int *, int, int(*key)(int));

	void swap(int&, int&);

	void swap(double&, double&);

	int* createKeys(int*, int);

	int* createKeys(int*, int, key);

	int* createKeys(double*, int, keyD);

	int countOfUnitInBinaryPresentation(int);

	int countOfZerosInBinaryPresentation(int);

	int sqr(int);

	double * transform(int*, int, Predicate, Rule);

	bool isOdd(int);

	double sin(int);

	int roundDown(double);

	int number();

	int Hexadecimal(int);

	void deleteElments(int*, int, int&);

	bool presenceÑheck(char, int);

	void merge(int*, int, int, int);

	void mergeSort(int*, int, int);

	void merge(int*, int, int, int, key);

	void mergeSort(int*, int, int, key);
}
