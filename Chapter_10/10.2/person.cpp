#include "person.h"
#include <iostream>
#include <cstring>


Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
    fname[LIMIT - 1] = '\0';
}

void Person::Show() const
{
    std::cout << "First name: " << fname << '\n'
              << "Last name: " << lname << '\n';
}

void Person::FormalShow() const
{
    std::cout << "Last name: " << lname << '\n'
              << "First name: " << fname << '\n';
}
