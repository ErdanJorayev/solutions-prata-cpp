#include <iostream>
#include "new_cd.h"

// Helper function to test polymorphism (pass-by-reference)
void Bravo(const Cd& disk) 
{
    disk.Report();
}

int main() 
{
    std::cout << "========================================\n";
    std::cout << "1. OBJECT CREATION VIA CONSTRUCTORS\n";
    std::cout << "========================================\n";

    // Creating objects using parameterized constructors
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2("Piano Sonata No. 14", "Beethoven", "Philips", 3, 14.25);

    std::cout << "\n--- Calling Report() directly ---\n";
    std::cout << "[Cd Object]:\n";
    c1.Report();

    std::cout << "\n[Classic Object]:\n";
    c2.Report();

    std::cout << "\n========================================\n";
    std::cout << "2. TESTING POLYMORPHISM (Pass-by-reference)\n";
    std::cout << "========================================\n";

    std::cout << "\n--- Bravo(c1) ---\n";
    Bravo(c1);

    std::cout << "\n--- Bravo(c2) (Should invoke Classic::Report) ---\n";
    Bravo(c2);

    std::cout << "\n========================================\n";
    std::cout << "3. TESTING COPY CONSTRUCTOR\n";
    std::cout << "========================================\n";

    // Calls Classic copy constructor (Deep Copy check)
    Classic copy_c2 = c2; 
    std::cout << "\n--- Copied object (copy_c2) ---\n";
    copy_c2.Report();

    std::cout << "\n========================================\n";
    std::cout << "4. TESTING ASSIGNMENT OPERATOR\n";
    std::cout << "========================================\n";

    // Default constructor (all pointers initialized to nullptr)
    Cd empty_cd; 
    std::cout << "\n--- Default object before assignment ---\n";
    empty_cd.Report();

    // Invokes Cd::operator=
    empty_cd = c1; 
    std::cout << "\n--- Default object AFTER assignment (empty_cd = c1) ---\n";
    empty_cd.Report();

    // Invokes Classic::operator=
    Classic empty_classic;
    empty_classic = c2; 
    std::cout << "\n--- Default Classic AFTER assignment (empty_classic = c2) ---\n";
    empty_classic.Report();

    std::cout << "\n========================================\n";
    std::cout << "5. TESTING SELF-ASSIGNMENT SAFETY\n";
    std::cout << "========================================\n";

    // Should not crash or produce dangling pointers
    c2 = c2; 
    std::cout << "\n--- Result of c2 = c2 (should work normally) ---\n";
    c2.Report();

    std::cout << "\n========================================\n";
    std::cout << "6. DYNAMIC ALLOCATION & POLYMORPHIC DELETION\n";
    std::cout << "========================================\n";

    // Base pointer pointing to derived object
    Cd* pcd = new Classic("Four Seasons", "Vivaldi", "Sony", 12, 42.0);
    std::cout << "\n--- Calling Report via Cd* pcd ---\n";
    pcd->Report();

    // Virtual destructor ~Cd() guarantees ~Classic() is properly invoked
    delete pcd; 
    std::cout << "\nMemory successfully cleaned up without crashes!\n";

    std::cout << "\n========================================\n";
    std::cout << "Test completed successfully!\n";
    std::cout << "========================================\n";

    return 0;
}