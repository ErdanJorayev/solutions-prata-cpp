#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    num1 = num2 = 0;

    cout << "Enter the 1 number: ";
    cin >> num1;

    cout << "Enter the 2 number: ";
    cin >> num2;

    int sum = 0;

    for (int i = num1; i <= num2; i++)
        sum += i;
    
    cout << "Sum = " << sum;

    return 0;
}