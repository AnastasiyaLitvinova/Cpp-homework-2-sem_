#include "ComplexNumber.h"
#include <fstream>

using namespace std;

#pragma region constructors
ComplexNumber::ComplexNumber(double real, double imaginar)
{
	this->SetReal(real);
	this->SetImaginar(imaginar);
}

ComplexNumber::ComplexNumber(const ComplexNumber & other)
{
	this->SetReal(other.GetReal());
	this->SetImaginar(other.GetImaginar());
}
#pragma endregion

#pragma region operators

ComplexNumber ComplexNumber::operator+(const ComplexNumber & num) const
{
	ComplexNumber temp;

	temp.real = this->real + num.real;
	temp.imaginar = this->imaginar + num.imaginar;

	return temp;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber & num) const
{
	ComplexNumber temp;

	temp.real = this->real - num.real;
	temp.imaginar = this->imaginar - num.imaginar;

	return temp;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber & num) const
{
	ComplexNumber temp;

	temp.real = - (this->imaginar * num.imaginar) + (this->real * num.real);
	temp.imaginar = (this->real * num.imaginar) + (this->imaginar * num.real);
	return temp;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber & num) const
{
	ComplexNumber temp;

	double r = num.real * num.real + num.imaginar * num.imaginar;
	temp.real = (this->real * num.real + this->imaginar * num.imaginar) / r;
	temp.imaginar = (this->imaginar * num.real - this->real * num.imaginar) / r;

	return temp;
}

ComplexNumber ComplexNumber::operator=(const ComplexNumber & num)
{
	this->SetReal(num.real);
	this->SetImaginar(num.imaginar);

	return (*this);
}
#pragma endregion

#pragma region set-and-get-accsessors
void ComplexNumber::SetReal(double rational)
{
	this->real = rational;
}

void ComplexNumber::SetImaginar(double imaginar)
{
	this->imaginar = imaginar;
}

double ComplexNumber::GetReal() const
{
	return this->real;
}

double ComplexNumber::GetImaginar() const
{
	return this->imaginar;
}
#pragma endregion

#pragma region friend - operators
std::ostream & operator<<(std::ostream& stream, const ComplexNumber & num)
{
	stream << num.GetReal() << " + " << num.GetImaginar() << "i";

	return stream;
}

std::istream & operator>>(std::istream& stream, ComplexNumber & num)
{
	double real, imaginar;
	stream >> real;
	num.SetReal(real);
	stream >> imaginar;
	num.SetImaginar(imaginar);

	return stream;
}
#pragma endregion