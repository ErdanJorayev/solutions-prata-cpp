#include <iostream>
#include <cmath> 
#include "stonewt.h"

using std::cout;

Stonewt::Stonewt(double lbs, Mode form)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn + lbs - int (lbs);
    pounds = lbs;
    mode = form;
}

Stonewt::Stonewt(int stn, double lbs, Mode form)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = form;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
    mode = STONE;
}

Stonewt::~Stonewt()
{
}

Stonewt operator+(const Stonewt & s1, const Stonewt & s2)
{
    double total_lbs = s1.pounds + s2.pounds;
    return Stonewt(total_lbs, s1.mode);
}

Stonewt operator-(const Stonewt & s1, const Stonewt & s2)
{
    double diff_lbs = s1.pounds - s2.pounds;
    if (diff_lbs < 0) 
        diff_lbs = 0; 
    return Stonewt(diff_lbs, s1.mode);
}

Stonewt operator*(const Stonewt & s, double n)
{
    double mult_lbs = s.pounds * n;
    return Stonewt(mult_lbs, s.mode);
}

std::ostream & operator<<(std::ostream & os, const Stonewt & s)
{
    if (s.mode == Stonewt::STONE)
        os << s.stone << " stone, " << s.pds_left << " pounds";
    else if (s.mode == Stonewt::INT_LBS)
        os << (int)std::round(s.pounds) << " pounds (int)";
    else if (s.mode == Stonewt::FLOAT_LBS)
        os << s.pounds << " pounds";
    else
        os << "Stonewt object mode is invalid";
    return os;
}
