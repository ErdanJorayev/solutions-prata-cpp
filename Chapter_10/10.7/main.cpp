#include <iostream>
#include "plorg.h"

int main() 
{
    std::cout << "=== Test 1: Default Object ===" << std::endl;
    plorg default_plorg;
    default_plorg.show();

    std::cout << "\n=== Test 2: Custom Object ===" << std::endl;
    plorg custom_plorg("Gorg", 75);
    custom_plorg.show();

    std::cout << "\n=== Test 3: Modifying CI ===" << std::endl;
    custom_plorg.indx(99);
    custom_plorg.show();

    std::cout << "\n=== Test 4: Long Name Handling ===" << std::endl;
    plorg long_plorg("ThisNameIsWayTooLongForPlorg", 40);
    long_plorg.show();

    return 0;
}
