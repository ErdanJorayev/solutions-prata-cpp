#include <iostream>
#include <iomanip>

const unsigned int max5000  = 5000;
const unsigned int max10000 = 10000;
const unsigned int max20000 = 20000;
const unsigned int max35000 = 35000;

const double twarp_0  = max5000 * 0.00;
const double twarp_10 = max10000 * 0.10;
const double twarp_15 = max20000 * 0.15;
const double twarp_20 = 0.20;

int main()
{
    unsigned int my_twarps = 0;
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Please enter your twarps: ";
    while (std::cin >> my_twarps && my_twarps > 0)
    {
        if (my_twarps <= max5000)
            std::cout << "Your tax " << twarp_0 << " twarp\n";
        else if (my_twarps > max5000 && my_twarps <= max10000)
            std::cout << "Your tax " << twarp_0 + twarp_10 << " twarps\n";
        else if (my_twarps > max10000 && my_twarps <= max20000)
            std::cout << "Your tax " << twarp_0 + twarp_10 + twarp_15 << " twarps\n";
        else
            std::cout << "Your tax " << twarp_0 + twarp_10 + twarp_15 +
            (my_twarps - max35000) * twarp_20 << " twarps\n";
        std::cout << "Enter next twarps: ";
    }
    if (my_twarps <= 0)
        std::cout << "Really? Oh shit\n";
    std::cout << "Bye!\n";
    return 0;
}