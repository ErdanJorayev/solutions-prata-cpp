#include <iostream>
#include <array>

int main()
{
    std::array<double, 10> dnts{};
    double sum = 0;
    double aver = 0;
    size_t over_avg = 0;
    size_t count = 0;
    size_t a = 0;

    std::cout << "Enter the donations: ";
    for (a = 0; a < dnts.size(); a++)
    {
        std::cin >> dnts[a];
        sum += dnts[a];
    }
    aver = sum / static_cast<double>(a); 
    std::cout << "Average in donations is " 
         << aver << '\n';
    
    for (a = 0; a < dnts.size(); a++)
        if (dnts[a] > aver)
            count++;
    std::cout << "Nums over average donations: " << count;

    return 0;
}