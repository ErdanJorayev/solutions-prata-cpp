#include <iostream>

using namespace std;

int main()
{
    const int SEC_MIN = 60;
    const int MIN_HR = 60;
    const int HR_DAY = 24;

    unsigned long long seconds = 0;

    cout << "Enter the number of seconds: ";
    cin >> seconds;

    unsigned long long total_sec = seconds; 

    unsigned int s = seconds % SEC_MIN; 
    seconds /= SEC_MIN;                 

    unsigned int m = seconds % MIN_HR;  
    seconds /= MIN_HR;                  

    unsigned int h = seconds % HR_DAY;  
    unsigned int d = seconds / HR_DAY; 

    cout << total_sec << " seconds = " << d << " days, "
         << h << " hours, " << m << " minutes, " << s << " seconds" << endl;

    return 0;
}
