#include <iostream>
#include <cstring>
#include "plorg.h"

plorg::plorg(const char * n, unsigned int c)
{
    strncpy(name, n, S);
    name[S - 1] = '\0';
    CI = c;
}

void plorg::indx(unsigned int c)
{
    CI = c;
}

void plorg::show() const
{
    std::cout << "Name " << name << '\n'
              << "Index " << CI << '\n';
}