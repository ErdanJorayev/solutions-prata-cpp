#include <iostream>

using namespace std;

int main()
{
    int num;
    int sum = 0;

    do 
    {
       cout << "Enter the num: (0 to quit): ";
       cin >> num;
    
       sum += num; 
        cout << "Current sum: " << sum << endl;
    } while (num);
    cout << "End\n";
    return 0;
}