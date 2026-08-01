#include "port.h"

char * Port::cloneString(const char * str)
{
    if (str == nullptr) 
        str = "";
    
    char * temp = new char[std::strlen(str) + 1];
    std::strcpy(temp, str);
    return temp;
}

Port::Port(const char * br, const char * st, int b)
    : brand(cloneString(br)), bottles(b)
{
    if (st != nullptr) 
    {
        strncpy(style, st, sizeof(style) - 1);
        style[sizeof(style) - 1] = '\0'; 
    } 
    else 
        style[0] = '\0';
}

Port::Port(const Port & p)
    : brand(cloneString(p.brand)), bottles(p.bottles)
{
    strncpy(style, p.style, sizeof(style) - 1);
    style[sizeof(style) - 1] = '\0';
}

Port & Port::operator=(const Port & p)
{
    if (this == &p)
        return *this;
    
    delete [] brand;
    brand = cloneString(p.brand);
    
    bottles = p.bottles;

    strncpy(style, p.style, sizeof(style) - 1);
    style[sizeof(style) - 1] = '\0';

    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    if (bottles >= b)
        bottles -= b;
    else
        bottles = 0; 

    return *this;
}

void Port::Show() const
{
    std::cout << "Brand: " << brand << '\n'
              << "Kind: " << style << '\n'
              << "Bottles: " << bottles << '\n';
}

ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", "
              << p.bottles << '\n';
    return os;
}

// Relase VintagePort______________________________________
VintagePort::VintagePort()
    : nickname(cloneString("none")), year(0) 
{
}

VintagePort::VintagePort(const char * br, const char * st,
    int b, const char * nn, int y)
    : Port(br, st, b), nickname(cloneString(nn)), year(y)
{
}

VintagePort::VintagePort(const VintagePort & vp)
    : Port(vp), nickname(cloneString(vp.nickname)), year(vp.year)
{
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == &vp)
        return *this;

    Port::operator=(vp);

    delete [] nickname;

    nickname = cloneString(vp.nickname);
    year = vp.year;

    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    std::cout << "Nickname: " << nickname << '\n'
              << "Year: "     << year << '\n';
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << static_cast<const Port &>(vp);

    os << ", " << vp.nickname << ", " << vp.year << '\n';

    return os;
}