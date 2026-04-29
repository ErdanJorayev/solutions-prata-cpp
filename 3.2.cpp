#include <iostream>

using namespace std;

int main()
{
    unsigned int foots = 0;
    unsigned int inchs = 0;
    double pound = 0;

    unsigned int pound_to_inchs = 12;
    double inchs_to_metr = 0.0254;
    double pound_to_kg = 2.2;

    cout << "Enter your height in pound and inch: ";
    cin >> foots;
    cin >> inchs;

    cout << "Enter your weight in pounds: ";
    cin >> pound;

    double metr = inchs_to_metr * (foots * pound_to_inchs + inchs);
    double kg = pound / pound_to_kg;

    cout << "You BMI in " << kg / (metr * metr);

    return 0;
}
