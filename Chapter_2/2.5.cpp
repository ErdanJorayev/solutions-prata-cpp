#include <iostream>

using namespace std;

// Функция для конвертации
double celsiusToFahrenheit(double celsius) {
    return 1.8 * celsius + 32.0;
}

int main() {
    double celsius = 0.0;

    cout << "Please enter a Celsius value: ";
    cin >> celsius;

    double fahrenheit = celsiusToFahrenheit(celsius);

    cout << celsius << " degrees Celsius is " 
         << fahrenheit << " degrees Fahrenheit." << endl;

    return 0;
}
