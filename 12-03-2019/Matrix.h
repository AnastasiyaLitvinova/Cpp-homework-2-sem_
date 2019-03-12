#pragma once

namespace Matrix
{
	 double redictionFormule(double);

	 double sinTaylor(double value, double accurancy);

	 void createSinTaylorMatrix(double** matrix, int rows, int cols, double accur);

	 void createSinMatrix(double **, int, int);

	 bool comparisonMatrix(double**, double**, int, int, double);
}
