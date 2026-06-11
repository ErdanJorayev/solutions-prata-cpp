#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strncpy(g.fullname, name, Len - 1);
    g.fullname[Len - 1] = '\0';
    g.handicap = hc;
}

int setgolf(golf & g)
{
    std::cout << "Enter the name: ";
    std::cin.getline(g.fullname, Len);
    
    std::cout << "Enter the handicap: ";
    (std::cin >> g.handicap).get();   
    
    return g.fullname[0] != '\0'; 
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    std::cout << "Name: " << g.fullname << '\n';
    std::cout << "Handicap: " << g.handicap << '\n';
}
