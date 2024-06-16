#include <iostream>
class Complex
{
    private:
        double real;              // fractional pounds
        // mode PO
        double imag;                // entire weight in pounds
    public:
        Complex(double r, double i); // constructor for stone, lbs
        Complex();                    // default constructor
        ~Complex();
        // operator overloading
        Complex operator+(const Complex & b) const;
        Complex operator-(const Complex & b) const;
        Complex operator*(const Complex & b) const;
        Complex operator*(double n) const;
        Complex operator~() const;

        // compare operator overloading
        bool operator<(const Complex &st) const;
        bool operator>(const Complex &st) const;
        bool operator<=(const Complex &st) const;
        bool operator>=(const Complex &st) const;
        bool operator==(const Complex &st) const;
        bool operator!=(const Complex &st) const;

        // friends
        friend Complex operator*(double n, const Complex & a)
            {return a*n;}
        friend std::ostream & operator<<(std::ostream & os, const Complex & v);
        friend std::istream & operator>>(std::istream & os, Complex & v);
};
