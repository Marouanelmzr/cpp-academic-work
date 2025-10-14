#include <iostream>
#include <cmath>
#include "complex.h"
#include <algorithm>
#include <cstring>
using namespace std;

complex::complex(double Re, double Im)
{
    this->Re = Re;
    this->Im = Im;
}
double complex::GetRe()
{
    return this->Re;
}
double complex::GetIm()
{
    return this->Im;
}
ostream &operator<<(ostream &os, complex Z)
{
    if (Z.Im > 0)
        os << Z.Re << " + " << Z.Im << "i" << endl;
    else if (Z.Im < 0)
        os << Z.Re << " - " << -Z.Im << "i" << endl;
    else
        os << Z.Re << endl;

    return os;
}
complex complex::operator+(complex Z)
{
    return complex(this->Re + Z.GetRe(), this->Im + Z.GetIm());
}
void complex::operator+=(double N)
{
    this->Re += N;
}
void complex::operator+=(complex C)
{
    this->Re += C.GetRe();
    this->Re += C.GetIm();
}
bool complex::operator==(complex C)
{
    return (this->Re == C.GetRe() && this->Im == C.GetIm());
}
complex &complex::operator=(double x)
{
    this->Re = x;
    this->Im = 0;

    return *this;
}