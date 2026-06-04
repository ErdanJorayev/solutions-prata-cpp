#include <iostream>
#include <string>
#include <cctype> 
void upper(std::string & str);

int main()
{
    std::string str;

    std::cout << "Enter a string (q to quit): ";
    
    while (std::getline(std::cin, str) && (str.length() > 1 || str[0] != 'q'))
    {
        upper(str);
        std::cout << str << '\n';
        std::cout << "Next string (q to quit): ";
    }
    return 0;
}

void upper(std::string & str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
}
