#include <iostream>

typedef unsigned long long int ull;

ull fact(ull num);

int main()
{
    ull num = 0;
    std::cout << "Enter number for factorial: ";
    std::cin >> num;
    std::cout << num << "!: " << fact(num);
    std::cout << "\nEnd\n";
    return 0;
}

ull fact(ull num)
{
    ull fctrl = 1;

    if (num > 0)
        fctrl = num * fact(num - 1);
   
    return fctrl;
}