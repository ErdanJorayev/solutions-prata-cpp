#include <iostream>
#include "sales.h"

int main() 
{
    std::cout << "--- Test 1: Constructor with an array ---\n";
    double quarters_data[] = {1100.5, 2400.0, 1850.25};
    SALES::Sales s1(quarters_data, 3);
    s1.showSales();

    std::cout << "\n--- Test 2: Constructor with an empty array ---\n";
    double empty_data[] = {0.0};
    SALES::Sales s2(empty_data, 0);
    s2.showSales();

    std::cout << "\n--- Test 3: Interactive input ---\n";
    double dummy_data[] = {0.0};
    SALES::Sales s3(dummy_data, 0);
    s3.setSales();
    s3.showSales();

    return 0;
}
