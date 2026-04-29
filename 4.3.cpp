#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char f_name[20];
    char l_name[20];
    char new_str[50];

    cout << "Enter your first name: ";
    cin.getline(f_name, 20);

    cout << "Enter your last name: ";
    cin.getline(l_name, 20);
    
    strcpy(new_str, l_name);
    strcat(new_str, ", ");
    strcat(new_str, f_name);

    cout << "Here, s the information in a single string: "; 
    cout << new_str;

    return 0;
}