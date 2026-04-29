#include <iostream>

using namespace std;

int main()
{
    double liters_per_100km = 0.0;

    cout << "Enter gas consumption in liters per 100 km: ";
    cin >> liters_per_100km;

    // Конвертация: (62.14 мили) / (расход в галлонах)
    // 1 литр = 1 / 3.875 галлона
    double gallons = liters_per_100km / 3.875;
    double mpg = 62.14 / gallons;

    cout << liters_per_100km << " liters per 100 km is approximately " 
         << mpg << " miles per gallon." << endl;

    return 0;
}
