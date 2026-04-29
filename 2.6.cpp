#include <iostream>

using namespace std;

// Функция для конвертации
double lightYearsToAU(double light_years) {
    return light_years * 63240.0;
}

int main() {
    double light_years = 0.0;

    cout << "Enter the number of light years: ";
    cin >> light_years;

    double au = lightYearsToAU(light_years);

    cout << light_years << " light years = " 
         << au << " astronomical units." << endl;

    return 0;
}
