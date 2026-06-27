#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
public:
    enum Mode { STONE, INT_LBS, FLOAT_LBS };

private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;
    Mode mode; 

public:
    Stonewt(double lbs, Mode form = FLOAT_LBS);
    Stonewt(int stn, double lbs, Mode form = STONE);
    Stonewt();
    ~Stonewt();

    void set_stone_mode() { mode = STONE; }
    void set_int_lbs_mode() { mode = INT_LBS; }
    void set_float_lbs_mode() { mode = FLOAT_LBS; }

    friend Stonewt operator+(const Stonewt & s1, const Stonewt & s2);
    friend Stonewt operator-(const Stonewt & s1, const Stonewt & s2);
    friend Stonewt operator*(const Stonewt & s, double n);
    friend Stonewt operator*(double n, const Stonewt & s) { return s * n; }

    friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};
#endif
