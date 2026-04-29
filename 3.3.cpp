#include <iostream>

using namespace std;

int main()
{
    unsigned int degrees = 0;
    unsigned int minutes = 0;
    unsigned int seconds = 0;
    const double IN_MIN_SEC = 60;
    const double IN_DEG_MIN = 60;

    cout << "Enter a latitude in degrees, minutes, and seconds: \n";
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;
    cout << degrees << " degrees, " << minutes << " minutes, "
         << seconds << " seconds = " <<
         degrees + (minutes + (seconds / IN_MIN_SEC)) / IN_DEG_MIN;


    return 0;
}
