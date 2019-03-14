#include <iostream>
#include"Matrix.h"
#include <cmath>
using namespace std;

double redictionFormule(double term)
{
	while (term >= 2 * 3.1415)
	{
		term -= 2 * 3.1415;
	}

	return term;
}

 double sinTaylor(double value, double accurancy)
{
	if (accurancy < 0.0 || accurancy >= 1)
	{
		cout<<"Incorrect accurancy"<< endl;
	}

	double term = value, sum = 0;

	for (int i = 1; fabs(term) > accurancy; i++)
	{
		sum += term;
		term = -term * value * value / (2 * i) / (2 * i + 1);
	}

	return sum;
}

 void createSinTaylorMatrix(double** matrix, int rows, int cols, double accur)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (j == i)
			{
				matrix[i][j] = j;
			}

			else
			{
				matrix[i][j] = (sinTaylor(redictionFormule(i*j), accur) + i + 1) / pow(1 + j, 3);
			}
		}

	}
}

 void createSinMatrix(double ** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (j != i)
			{
				matrix[i][j] =i - j;
			}

			else matrix[i][j] = ((i + j - 1) + pow(M_E,( i + j)) / (sin(redictionFormule(2 * i + 2 * j)) + 1);
					     {
						     (sin(redictionFormule(i*j)) + i + 1) / pow(1 + j, 3);
					     }
		}
	}
}

 bool comparisonMatrix(double** taylorMatrix, double** libraryMatrix, int rows, int cols, double acc)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (fabs(taylorMatrix[i][j] - libraryMatrix[i][j]) > acc)
			{
				return false;
			}
		}
	}

	return true;
}
