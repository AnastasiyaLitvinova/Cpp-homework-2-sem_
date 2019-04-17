#pragma once
#include <iostream>
#include <fstream>

class ComplexNumber
{
public:
	ComplexNumber() {}
	ComplexNumber(double, double);
	ComplexNumber(const ComplexNumber&);

	ComplexNumber operator + (const ComplexNumber&) const;

	ComplexNumber operator = (const ComplexNumber&);
	ComplexNumber operator -(const ComplexNumber&) const;
	ComplexNumber operator * (const ComplexNumber&) const;
	ComplexNumber operator / (const ComplexNumber&) const;

	friend std::ostream& operator << (std::ostream& stream, const ComplexNumber& num);
	friend std::istream& operator >> (std::istream& stream, ComplexNumber& num);

	double GetReal() const;
	double GetImaginar() const;

	void SetReal(double);
	void SetImaginar(double);

private:
	double real;
	double imaginar;


};
