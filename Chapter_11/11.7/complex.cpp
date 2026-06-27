#include "complex.h"

complex::complex()
{
    real = imaginary = 0.0;
}

complex::complex(double r, double i)
{
    real = r;
    imaginary = i;
}

complex operator+(const complex & a, const complex & b)
{
    return complex(a.real + b.real, a.imaginary + b.imaginary);
}

complex operator-(const complex & a, const complex & b)
{
    return complex(a.real - b.real, a.imaginary - b.imaginary);
}


complex operator*(const complex & a, const complex & b)
{
    return complex(a.real * b.real - a.imaginary * b.imaginary, 
                   a.real * b.imaginary + a.imaginary * b.real);
}

complex operator*(double num, const complex & b)
{
    return complex(num * b.real, num * b.imaginary);
}

complex operator~(const complex & a)
{
    return complex(a.real, -a.imaginary);
}

std::ostream & operator<<(std::ostream & os, const complex & s)
{
    os << "(" << s.real << ", " << s.imaginary << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, complex & s)
{
    std::cout << "real: ";
    is >> s.real;
    std::cout << "imaginary: ";
    is >> s.imaginary;
    return is;
}