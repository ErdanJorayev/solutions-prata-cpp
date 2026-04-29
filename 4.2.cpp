#include <iostream>
#include <string>
using namespace std;

int main()
{
    string l_name;
    string f_name;
    char ch;
    unsigned int age = 0;

    cout << "What is your first name? ";
    getline(cin, f_name);

    cout << "What is your last name? ";
    getline(cin, l_name);

    cout << "What letter grade do you deserve? ";
    cin >> ch;

    cout << "What is you age? ";
    cin >> age;

    cout << "Name: " << l_name << ", "
         << f_name << endl;
    cout << "Grade: " << char(ch + 1) << endl;
    cout << "Age: " << age << endl;

    return 0;
}