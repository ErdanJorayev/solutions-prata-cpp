#include <iostream>
#include "sales.h"

int main()
{
    SALES::Sales sales_interactive;
    SALES::Sales sales_non_interactive;

    std::cout << "Configuring the first Sales object (interactive):" << std::endl;
    SALES::setSales(sales_interactive);

    std::cout << "\nConfiguring the second Sales object (non-interactive):" << std::endl;
    double demo_data[] = { 1200.50, 450.75, 2300.00 }; // Передаем только 3 элемента вместо 4
    SALES::setSales(sales_non_interactive, demo_data, 3);

    std::cout << "\nDisplaying first structure (interactive):";
    SALES::showSales(sales_interactive);

    std::cout << "\nDisplaying second structure (non-interactive):";
    SALES::showSales(sales_non_interactive);

    return 0;
}
