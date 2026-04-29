#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<unsigned int, 3> aver;

    cout << "Enter 3 numbers:\n";
    cin >> aver[0];
    cin >> aver[1];
    cin >> aver[2];

    cout << aver[0] << endl;
    cout << aver[1] << endl;
    cout << aver[2] << endl; 

    cout << "Average: "
         << (aver[0] + aver[1] + aver[2])/3.0;

    return 0;
}
