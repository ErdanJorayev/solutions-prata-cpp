#include <iostream>

using namespace std;

int main(void)
{
    unsigned int inch = 0;
    const int INCHES_PER_FOOT = 12;

    cout << "Enter inch: __\b\b";
    cin >> inch;

    cout << "You weight: " << inch / INCHES_PER_FOOT
         << " foots and " << inch % INCHES_PER_FOOT
         << " inchs";

    return 0;
}
