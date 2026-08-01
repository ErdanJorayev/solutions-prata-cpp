#include "kek.h"
#include <cstring>
char * Abstract::cloneString(const char * str)
{
    if (str == nullptr) 
        return nullptr;
    
    char * temp = new char[std::strlen(str) + 1];
    std::strcpy(temp, str);
    return temp;
}

Abstract::Abstract(const char * lb, int rg)
    : label(cloneString(lb))
    ,rating(rg)
{
}

Abstract::Abstract(const Abstract & a)
    : label(cloneString(a.label))
    , rating(a.rating)
{
}

Abstract::~Abstract()
{
    delete [] label;
}

Abstract & Abstract::operator=(const Abstract & a)
{
    if (this == &a)
        return *this;

    delete [] label;
    label = cloneString(a.label);
    rating = a.rating;
    
    return *this;
}

void Abstract::View() const
{
    std::cout << "Label: " << (label ? label : "N/A") 
              << ", Rating: " << rating;
}

// Relaese baseDMA______________________________________________
baseDMA::baseDMA(const char * l, int r)
    : Abstract(l, r)    
{
}

baseDMA::baseDMA(const baseDMA & rs)
    : Abstract(rs)
{
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;

    Abstract::operator=(rs);
    return *this;
}


void baseDMA::View() const
{
    Abstract::View();
}

// Release lacksDMA_________________________________________________
lacksDMA::lacksDMA(const char * a, const char * l, int r)
   : Abstract(l, r)
{
    strncpy(color, a, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA & rs)
    : Abstract(rs)
{
    strncpy(color, rs.color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const
{
    Abstract::View();
    std::cout << "Color: " << color;
}

lacksDMA & lacksDMA::operator=(const lacksDMA & rs)
{
    if (this == &rs)
        return *this;

    Abstract::operator=(rs);
   
    strncpy(color, rs.color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';

    return *this;
}

// Realise hasDMA_______________________________________________
hasDMA::hasDMA(const char * s, const char * l, int r)
    : Abstract(l, r), style(cloneString(s))
{
}

hasDMA::hasDMA(const hasDMA & hs)
    : Abstract(hs), style(cloneString(hs.style))
{   
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
    if (this == &rs)
        return *this;
    
    delete [] style;
    
    Abstract::operator=(rs);
    style = cloneString(rs.style);

    return *this;
}

void hasDMA::View() const
{
    Abstract::View();
    std::cout << "Style: " << style;
}


