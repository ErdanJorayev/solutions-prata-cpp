#include <iostream>
#include "stonewt.h"

int main()
{
    Stonewt arr[6]{23, 34, 45};
    Stonewt min, max;
    Stonewt up_11(11);
    size_t count_11 = 0;
    double num = 0;

    std::cout << "Enter 3 numbers:\n";
    for (size_t i = 3; i < 6 && std::cin >> num; i++)
        arr[i] = Stonewt(num);

    min = arr[0];
    max = arr[0];
    
    for (size_t i = 1; i < 6; i++)
    {
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    for (size_t i = 0; i < 6; i++)
        if (arr[i] >= up_11)
            count_11++;

    std::cout << "Max in array: ";
    max.show_lbs();
    std::cout << "Min in array: ";
    min.show_lbs();
    std::cout << "Count in >11: " << count_11 << '\n';

    return 0;
}