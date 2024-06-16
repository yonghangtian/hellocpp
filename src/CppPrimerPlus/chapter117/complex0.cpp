#include "complex0.h"

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

Complex::Complex()
{
    real = imag = 0.0;
}

Complex::~Complex()         // destructor
{
}

// operator overloading
Complex Complex::operator+(const Complex & b) const
{
    return Complex(this->real + b.real, this->imag + b.imag);
}
Complex Complex::operator-(const Complex & b) const
{
    return Complex(this->real - b.real, this->imag - b.imag);
}
Complex Complex::operator*(const Complex & b) const
{
    return Complex(this->real*b.real - this->imag*b.imag, this->real*b.real + this->imag*b.imag);
}

Complex Complex::operator*(double n) const
{
    return Complex(this->real*n, this->imag*n);
}
Complex Complex::operator~() const
{
    return Complex(this->real, -this->imag);
}

// friends
std::ostream & operator<<(std::ostream & os, const Complex & v)
{
    os << "real:" << v.real <<" imag: " << v.imag;
    return os;
}

std::istream & operator>>(std::istream & is, Complex & v)
{
    std::cout << "real: ";
    is >> v.real;
    if (is) {
        std::cout << "imaginary: ";
        is >> v.imag;
    }
    return is;
}