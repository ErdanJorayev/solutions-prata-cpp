#include <iostream>

using namespace std;

int main()
{
    double miles = 0.0;
    double gallons = 0.0;

    cout << "Enter the number of miles driven: ";
    cin >> miles;

    cout << "Enter the gallons of gas consumed: ";
    cin >> gallons;

    double mpg = miles / gallons;

    cout << "Your car gets " << mpg << " miles per gallon." << endl;

    return 0;
}
