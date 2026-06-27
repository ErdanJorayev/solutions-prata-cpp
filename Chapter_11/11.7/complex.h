#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream> 
class complex
{
private:
    double real;
    double imaginary;
public:
    complex();
    complex(double r, double i); 
    
    friend complex operator+(const complex & a, const complex & b);
    friend complex operator-(const complex & a, const complex & b);
    friend complex operator*(const complex & a, const complex & b);
    friend complex operator*(double num, const complex & b);
    friend complex operator~(const complex & a);

    friend std::ostream & operator<<(std::ostream & os, const complex & s);
    friend std::istream & operator>>(std::istream & is, complex & s); 
}; 

#endif
