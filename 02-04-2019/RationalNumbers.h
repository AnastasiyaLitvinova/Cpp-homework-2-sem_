#pragma once
#include<iostream>

class FractionNamber
{
public:
	FractionNamber();

	explicit FractionNamber(int);

	FractionNamber(int, int);

	int GetNumerator() const;

	int GetDenominator() const;

	FractionNamber& operator +=(const FractionNamber&);

	FractionNamber& operator +=(int);

	FractionNamber& operator -=(const FractionNamber&);

	FractionNamber& operator -=(int);

	FractionNamber& operator *= (const FractionNamber&);

	FractionNamber& operator *= (int);

	FractionNamber& operator /=(const FractionNamber&);

	FractionNamber& operator /=(int);

	inline FractionNamber& operator ++();

	inline FractionNamber const operator++(int);

	inline FractionNamber& operator --();

	inline FractionNamber const operator --(int);

	inline FractionNamber const operator +(FractionNamber const&) const;

	inline FractionNamber const operator +(int) const;

	friend inline FractionNamber const operator+(int, FractionNamber const&);

	inline FractionNamber const operator - (FractionNamber const&) const;

	inline FractionNamber const operator -(int) const;

	friend inline FractionNamber const operator -(int, FractionNamber const&);

	inline FractionNamber operator * (const FractionNamber&);

	inline FractionNamber operator *(int);

	friend inline FractionNamber operator* (int, const FractionNamber&);

	inline FractionNamber operator /(const FractionNamber&);

	inline FractionNamber operator / (int);

	friend inline FractionNamber operator / (int, const FractionNamber&);

	explicit operator double() const { return (double)this->GetNumerator() / this->GetDenominator(); }

	friend std::istream& operator >> (std::istream&, FractionNamber& r);

	friend inline std::ostream& operator << (std::ostream&, const FractionNamber& r);


private:

	void SetNum(int);

	void SetDenom(int);

	static void Normalize(FractionNamber&);

	static int GSD(int, int);

	int numerator;
	int denominator;
};

#pragma region RNumn

FractionNamber::FractionNamber()
{
	this->SetNum(0);
	this->SetDenom(1);
}

void FractionNamber::SetNum(int x)
{
	this->numerator = x;
}

void FractionNamber::SetDenom(int x)
{
	if (x == 0)
	{
		throw std::invalid_argument("The denominator is 0");
	}
	this->denominator = x;
}

FractionNamber::FractionNamber(int x)
{
	this->SetNum(x);
	this->SetDenom(1);
}

FractionNamber::FractionNamber(int argNum, int argDenom)
{
	this->SetNum(argNum);
	this->SetDenom(argDenom);

	Normalize(*this);
}

int FractionNamber::GetDenominator() const
{
	return this->denominator;
}

int FractionNamber::GetNumerator() const
{
	return this->numerator;
}

int FractionNamber::GSD(int a, int b)
{
	return b ? GSD(b, a%b) : a;
}

void FractionNamber::Normalize(FractionNamber& x)
{
	int gsd = GSD(x.GetDenominator(), x.GetNumerator());

	x.SetNum(x.GetNumerator() / gsd);
	x.SetDenom(x.GetDenominator() / gsd);
}

inline FractionNamber& FractionNamber::operator*=(const FractionNamber& r)
{
	this->SetNum(this->GetNumerator() * r.GetNumerator());
	this->SetDenom(this->GetDenominator() * r.GetDenominator());

	Normalize(*this);

	return *this;
}

inline FractionNamber& FractionNamber::operator*=(int a)
{
	this->SetNum(this->GetNumerator() *a);

	Normalize(*this);
}

inline FractionNamber& FractionNamber::operator /= (const FractionNamber& r)
{
	this->SetNum(this->GetNumerator() * r.GetDenominator());
	this->SetDenom(this->GetDenominator() * r.GetNumerator());

	Normalize(*this);

	return *this;
}

inline FractionNamber& FractionNamber::operator /= (int a)
{
	this->SetDenom(this->GetDenominator() * a);

	Normalize(*this);

	return *this;
}

inline FractionNamber& FractionNamber::operator +=(const FractionNamber& r)
{
	this->SetNum(this->GetNumerator() * r.GetDenominator() + this->GetDenominator()*r.GetNumerator());
	this->SetDenom(this->GetDenominator()* r.GetDenominator());

	Normalize(*this);

	return *this;
}

inline FractionNamber& FractionNamber::operator+=(int a)
{
	this->SetNum(this->GetNumerator() + a * this->GetDenominator());

	Normalize(*this);

	return *this;
}

inline FractionNamber& FractionNamber::operator-=(const FractionNamber& r)
{
	this->SetNum(this->GetNumerator()* r.GetDenominator() - r.GetNumerator()*this->GetDenominator());
	this->SetDenom(this->GetDenominator() * r.GetDenominator());

	Normalize(*this);

	return *this;
}

inline FractionNamber& FractionNamber::operator-=(int a)
{
	this->SetNum(this->GetNumerator() - a * this->GetDenominator());

	Normalize(*this);
	return(*this);
}

inline FractionNamber& FractionNamber::operator++() //prefix
{
	this->SetNum(this->GetNumerator() + this->GetDenominator());

	Normalize(*this);
	return *this;
}

inline FractionNamber const FractionNamber::operator++(int) //postfix
{
	FractionNamber r = *this;
	++*this;
	return r;
}

inline FractionNamber& FractionNamber::operator--()
{
	this->SetNum(this->GetNumerator() - this->GetDenominator());
	return *this;
}

inline FractionNamber const FractionNamber::operator--(int)
{
	FractionNamber r = *this;
	--*this;
	return r;
}

inline FractionNamber const FractionNamber::operator +(FractionNamber const& r) const
{
	return FractionNamber(this->GetNumerator() * r.GetDenominator() + r.GetNumerator() * this->GetDenominator(), this->GetDenominator() * r.GetDenominator());
}

inline FractionNamber const FractionNamber::operator+(int a) const
{
	return FractionNamber(this->GetNumerator() + a * this->GetDenominator(), this->GetDenominator());
}

inline FractionNamber const operator + (int a, FractionNamber const& r)
{
	return FractionNamber(a*r.GetDenominator() + r.GetNumerator(), r.GetDenominator());
}

inline FractionNamber const FractionNamber::operator -(FractionNamber const& r) const
{
	return FractionNamber(this->GetNumerator() * r.GetDenominator() - r.GetNumerator() * this->GetDenominator(), this->GetDenominator() * r.GetDenominator());
}

inline FractionNamber const FractionNamber::operator-(int a) const
{
	return FractionNamber(this->GetNumerator() - a * this->GetDenominator(), this->GetDenominator());
}

inline FractionNamber const operator - (int a, FractionNamber const& r)
{
	return FractionNamber(a*r.GetDenominator() - r.GetNumerator(), r.GetDenominator());
}

inline FractionNamber FractionNamber::operator*(const FractionNamber& r)
{
	return FractionNamber(this->GetNumerator() * r.GetNumerator(), this->GetDenominator() * r.GetDenominator());
}

inline FractionNamber FractionNamber::operator*(int a)
{
	return FractionNamber(this->GetNumerator()*a, this->GetDenominator());
}

inline FractionNamber operator*(int a, const FractionNamber& r)
{
	return FractionNamber(a*r.GetNumerator(), r.GetDenominator());
}

inline FractionNamber FractionNamber::operator/(const FractionNamber& r)
{
	return FractionNamber(this->GetNumerator()*r.GetDenominator(), this->GetDenominator() * r.GetNumerator());
}

inline FractionNamber FractionNamber::operator/(int a)
{
	return FractionNamber(a*this->GetDenominator(), this->GetNumerator());
}

inline FractionNamber operator / (int a, const FractionNamber& r)
{
	return FractionNamber(a*r.GetDenominator(), r.GetNumerator());
}

inline std::istream& operator >> (std::istream& is, FractionNamber& r)
{
	char ch;
	int num;
	int denom;
	is >> num;

	r.SetNum(num);
	is.unsetf(std::ios_base::skipws);
	is >> ch;
	if (ch == '/')
	{

		is >> denom;
		r.SetDenom(denom);
	}
	else
	{
		is.putback(ch);
		r.SetDenom(1);
	}
	is.setf(std::ios_base::skipws);
	while (r.GetDenominator() == 0)
	{

		is >> denom;
		r.SetDenom(denom);
		is.unsetf(std::ios_base::skipws);

		is >> ch;
		if (ch == '/')
		{
			is >> denom;
			r.SetDenom(denom);
		}
		else
		{
			is.putback(ch);
			r.SetDenom(1);
		}
		is.setf(std::ios_base::skipws);
	}
	FractionNamber::Normalize(r);
	return is;
}

inline std::ostream& operator << (std::ostream& os, const FractionNamber& r)
{
	os << r.GetNumerator();
	if (1 != r.GetDenominator())
	{
		os << '/' << r.GetDenominator();
	}
	return os;
}
#pragma endregion



