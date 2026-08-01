#include "port.h"
using namespace std;

int main()
{
    cout << "=== 1. TESTING BASE CLASS PORT ===" << endl;
    Port p1("Grahams", "ruby", 20);
    Port p2; // Default constructor

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    // Modifying bottle counts
    p1 += 5;
    cout << "p1 after += 5: " << p1 << " (bottles count: " << p1.BottleCount() << ")" << endl;
    p1 -= 10;
    cout << "p1 after -= 10: " << p1 << endl;

    // Copy constructor and assignment operator
    Port p3 = p1; // Copy constructor
    p2 = p1;      // Assignment operator
    cout << "p3 (copy of p1): " << p3 << endl;
    cout << "p2 (after p2 = p1): " << p2 << endl;

    cout << "\n=== 2. TESTING DERIVED CLASS VINTAGEPORT ===" << endl;
    VintagePort vp1("Cockburn", "vintage", 30, "The Old Velvet", 1998);
    VintagePort vp2; // Default constructor

    cout << "vp1: " << vp1 << endl;
    cout << "vp2: " << vp2 << endl;

    // Testing copy constructor
    VintagePort vp3 = vp1;
    cout << "vp3 (copy of vp1): " << vp3 << endl;

    // Testing assignment operator and self-assignment
    vp2 = vp1;
    cout << "vp2 (after vp2 = vp1): " << vp2 << endl;
    
    vp1 = vp1; // Self-assignment check
    cout << "vp1 (after self-assignment): " << vp1 << endl;

    cout << "\n=== 3. TESTING POLYMORPHISM & VIRTUAL FUNCTIONS ===" << endl;
    // Array of pointers to the base class
    Port * drinks[4] = 
    {
        new Port("Taylor", "tawny", 15),
        new Port("Dow's", "vintage", 8),
        new VintagePort("Fonseca", "vintage", 12, "The Dark Lord", 1994),
        new VintagePort("Warre", "ruby", 50, "Warrior", 2003)
    };

    cout << "\n--- Calling Show() via Port* pointers ---" << endl;
    for (int i = 0; i < 4; ++i)
    {
        drinks[i]->Show();
        cout << "-----------------------------------" << endl;
    }

    // Freeing dynamic memory (tests virtual destructor ~Port())
    cout << "\nFreeing memory using virtual destructors..." << endl;
    for (int i = 0; i < 4; ++i)
        delete drinks[i];
    

    cout << "\nAll tests passed successfully!" << endl;
    return 0;
}