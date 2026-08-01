#include <iostream>
#include <cstring>
#include "cd.h"

using namespace std;

void Bravo(const Cd & disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    
    Cd *pcd = &c1;
    
    // Direct use of objects
    cout << "Using object directly:\n";
    c1.Report(); // Uses Cd method
    c2.Report(); // Uses Classic method
    
    // Using a pointer to objects of type cd *
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report(); // Uses Cd method for cd object
    pcd = &c2;
    pcd->Report(); // Uses Classic method for classic object
    
    // Calling a function with a Cd reference argument
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    
    // Testing assignment
    cout << "Testing assignment: \n";
    Classic copy;
    copy = c2;
    copy.Report();
    
    return 0;
}

void Bravo(const Cd & disk)
{
    disk.Report();
}
