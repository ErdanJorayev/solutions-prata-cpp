#include <iostream>
#include <cstring>
#include "cd.h"

// Base constructor with const parameters for string literals
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    strncpy(performers, s1, sizeof(performers) - 1);
    performers[sizeof(performers) - 1] = '\0';
    
    strncpy(label, s2, sizeof(label) - 1);
    label[sizeof(label) - 1] = '\0';

    selections = n;
    playtime = x;
}

// Base copy constructor
Cd::Cd(const Cd & d)
{
    strncpy(performers, d.performers, sizeof(performers) - 1);
    performers[sizeof(performers) - 1] = '\0';

    strncpy(label, d.label, sizeof(label) - 1);
    label[sizeof(label) - 1] = '\0';

    selections = d.selections;
    playtime = d.playtime;
}

// Base default constructor
Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

// Base destructor
Cd::~Cd()
{
}

// Display base class data
void Cd::Report() const
{
    std::cout << "Performers: " << performers << '\n';
    std::cout << "Label: "      << label      << '\n';
    std::cout << "Selections: " << selections << '\n';
    std::cout << "Playtime: "   << playtime   << '\n';
}

// Base assignment operator
Cd & Cd::operator=(const Cd & d)
{
    if (this == &d)
        return *this;
        
    strncpy(performers, d.performers, sizeof(performers) - 1);
    performers[sizeof(performers) - 1] = '\0';

    strncpy(label, d.label, sizeof(label) - 1);
    label[sizeof(label) - 1] = '\0';

    selections = d.selections;
    playtime = d.playtime;
    
    return *this;
}

// Classic methods

// Derived constructor with const parameters
Classic::Classic(const char * art, const char * per, const char * lab, int num, double pt)
    : Cd(per, lab, num, pt)    
{
    strncpy(artwork, art, sizeof(artwork) - 1);
    artwork[sizeof(artwork) - 1] = '\0';
}

// Derived copy constructor with proper const reference
Classic::Classic(const Classic & cl) : Cd(cl)
{
    strncpy(artwork, cl.artwork, sizeof(artwork) - 1);
    artwork[sizeof(artwork) - 1] = '\0';
}

// Derived default constructor
Classic::Classic()
{
    artwork[0] = '\0';
}

Classic::~Classic()
{
    
}

// Display all data including artwork
void Classic::Report() const
{
    Cd::Report();
    std::cout << "Artwork: " << artwork << '\n';
}

// Derived assignment operator
Classic & Classic::operator=(const Classic & cl)
{
    if (this == &cl)
        return *this;
        
    Cd::operator=(cl);
    
    strncpy(artwork, cl.artwork, sizeof(artwork) - 1);
    artwork[sizeof(artwork) - 1] = '\0';

    return *this;
}
