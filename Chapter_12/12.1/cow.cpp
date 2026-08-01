#include "cow.h"
#include <cstring>
#include <iostream>

Cow::Cow()
{
    strcpy(name, "no name");
    hobby = nullptr;
    weight = 0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
    strncpy(name, nm ? nm : "", 20);
    name[19] = '\0';
    
    const char* safe_ho = ho ? ho : ""; 
    hobby = new char[strlen(safe_ho) + 1];
    strcpy(hobby, safe_ho);
    
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    std::strcpy(name, c.name);

    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);

    weight = c.weight;
}

Cow::~Cow()
{
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    if (this == &c)
        return *this;
    
    delete [] hobby;

    std::strcpy(name, c.name);

    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);

    weight = c.weight;

    return * this; 
}

void Cow::ShowCow() const
{
    std::cout << "Name is " << name << '\n';
    std::cout << "Hobby is " << hobby << '\n';
    std::cout << "Weight is " << weight << '\n';
}

