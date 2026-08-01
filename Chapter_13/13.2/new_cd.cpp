#include "new_cd.h"
#include <iostream>
#include <cstring>



char* Cd::cloneString(const char* str) 
{
    if (str == nullptr) 
        return nullptr;
    
    char* new_str = new char[std::strlen(str) + 1];
    std::strcpy(new_str, str);
    return new_str;
}


Cd::Cd() = default; 

Cd::Cd(const char* s1, const char* s2, int n, double x)
    : performers(cloneString(s1)),
      label(cloneString(s2)),
      selections(n),
      playtime(x) 
{
}

Cd::Cd(const Cd& d)
    : performers(cloneString(d.performers)),
      label(cloneString(d.label)),
      selections(d.selections),
      playtime(d.playtime) 
{
}

Cd::~Cd() 
{
    delete[] performers;
    delete[] label;
}

Cd& Cd::operator=(const Cd& d)
 {
    if (this == &d) 
        return *this;
    

    delete[] performers;
    delete[] label;

    performers = cloneString(d.performers);
    label = cloneString(d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

void Cd::Report() const 
{
    std::cout << "Performers: " << (performers ? performers : "N/A") << "\n";
    std::cout << "Label:      " << (label ? label : "N/A") << "\n";
    std::cout << "Selections: " << selections << "\n";
    std::cout << "Playtime:   " << playtime << " min\n";
}


Classic::Classic() = default;

Classic::Classic(const char* art, const char* per, const char* lab, int num, double pt)
    : Cd(per, lab, num, pt),
      artwork(cloneString(art)) 
{
}

Classic::Classic(const Classic& cl)
    : Cd(cl),
      artwork(cloneString(cl.artwork)) 
{
}

Classic::~Classic() 
{
    delete[] artwork;
}

Classic& Classic::operator=(const Classic& cl) 
{
    if (this == &cl) 
        return *this;
    

    Cd::operator=(cl);

    delete[] artwork;
    artwork = cloneString(cl.artwork);

    return *this;
}

void Classic::Report() const 
{
    Cd::Report();
    std::cout << "Primary work: " << (artwork ? artwork : "N/A") << "\n";
}