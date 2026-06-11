#include <iostream>

double harmony(double x, double y);

int main()
{
    double n1, n2;
    n1 = n2 = 0;

    std::cout << "Enter 2 numbers: ";
    while ((std::cin >> n1 >> n2) && (n1 && n2))
    {
        std::cout << "Harmony: " << harmony(n1, n2);
        std::cout << "\nEnter the next numbers: ";
    }

    std::cout << "End\n";

    return 0;
}

double harmony(double x, double y)
{
    return 2.0 * x * y / (x + y);
}