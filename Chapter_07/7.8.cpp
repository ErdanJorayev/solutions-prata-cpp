#include <iostream>

const int Seasons = 4;
const char * Snames[4] = 
    {"Spring", "Summer", "Fall", "Winter"};

void fill(double pa[], size_t size);
void show(double da[], size_t size);
int main()
{
    double arr[Seasons];
    fill(arr, Seasons);
    show(arr, Seasons);
    return 0;
}
void fill(double pa[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: "; 
        std::cin >> pa[i];
    }
}
void show(double da[], size_t size)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";                             
    for (size_t i = 0; i < size; i++)
    {
        std::cout << Snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }
    std::cout << "Total Expenses: $" << total << '\n';      
}
