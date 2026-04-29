#include <iostream>
#include <string>

using namespace std;

int main()
{
    string f_name;
    string l_name;
    string new_str;

    cout << "Enter your first name: ";
    getline(cin, f_name);

    cout << "Enter your last name: ";
    getline(cin, l_name);

    new_str = l_name + ", " + f_name;

    cout << "Here, s the information in a single string: "; 
    cout << new_str;

    return 0;
}