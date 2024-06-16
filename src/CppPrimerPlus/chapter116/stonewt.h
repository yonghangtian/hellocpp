// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
    public:
        enum Mode {ST, PO};
    // ST for stone, PO for pounds
    private:
        enum {Lbs_per_stn = 14};      // pounds per stone
        Mode mode;
        // mode ST
        int stone;                    // whole stones
        double pds_left;              // fractional pounds
        // mode PO
        double pounds;                // entire weight in pounds
    public:
        Stonewt(double lbs, Mode form = PO);          // constructor for double pounds
        Stonewt(int stn, double lbs, Mode form = ST); // constructor for stone, lbs
        Stonewt();                    // default constructor
        ~Stonewt();
        // operator overloading
        Stonewt operator+(const Stonewt & b) const;
        Stonewt operator-(const Stonewt & b) const;
        Stonewt operator*(double n) const;
        // compare operator overloading
        bool operator<(const Stonewt &st) const;
        bool operator>(const Stonewt &st) const;
        bool operator<=(const Stonewt &st) const;
        bool operator>=(const Stonewt &st) const;
        bool operator==(const Stonewt &st) const;
        bool operator!=(const Stonewt &st) const;

        // friends
        friend Stonewt operator*(double n, const Stonewt & a)
            {return a*n;}
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & v);
};
#endif
