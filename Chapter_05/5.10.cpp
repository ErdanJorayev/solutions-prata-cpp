#include <iostream>

using std::cin;
using std::cout;

int main()
{
    size_t num = 0;

    cout << "Enter the number of lines: ";
    cin >> num;

    for (size_t i = 1; i <= num; i++)
    {
        for (size_t n = 0; n < num - i; n++)
            cout.put('.');
        for (size_t j = 0; j < i; j++)
            cout.put('*');
        cout.put('\n');
    }
    return 0;
}