#include <iostream>
using namespace std;

int main()
{
    char l_name[30]{};
    char f_name[30]{};
    char ch;
    unsigned int age = 0;

    cout << "What is your first name? ";
    cin.getline(f_name, 30);

    cout << "What is your last name? ";
    cin.getline(l_name, 30);

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