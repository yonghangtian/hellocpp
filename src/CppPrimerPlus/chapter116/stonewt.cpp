// stonewt.cpp -- Stonewt methods
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Mode form)
{
    mode = form;
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);

    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode form)
{
    mode = form;
    stone = stn;
    pds_left = lbs;

    pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

// operator overloading
Stonewt Stonewt::operator+(const Stonewt & b) const
{
    return Stonewt(this->pounds + b.pounds);
}
Stonewt Stonewt::operator-(const Stonewt & b) const
{
    return Stonewt(this->pounds - b.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(this->pounds*n);
}

bool Stonewt::operator<(const Stonewt &st) const
{
    return this->pounds < st.pounds;
}
bool Stonewt::operator>(const Stonewt &st) const
{
    return this->pounds > st.pounds;
}
bool Stonewt::operator<=(const Stonewt &st) const
{
    return this->pounds <= st.pounds;
}
bool Stonewt::operator>=(const Stonewt &st) const
{
    return this->pounds >= st.pounds;
}
bool Stonewt::operator==(const Stonewt &st) const
{
    return this->pounds == st.pounds;
}
bool Stonewt::operator!=(const Stonewt &st) const
{
    return this->pounds != st.pounds;
}


// friends
std::ostream & operator<<(std::ostream & os, const Stonewt & v)
{
    if (v.mode == Stonewt::PO) 
    {
        os << "stonewt in pounds format is:" << v.pounds;
    }
    else
    {
        os << "stonewt in stone format is:" << v.stone <<" stones, and " << v.pds_left << " pounds.";
    }

    return os;
}