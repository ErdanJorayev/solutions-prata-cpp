#include <iostream>

int main()
{
    int ct = 0;
    char ch;

    std::cout << "Enter the words: \n";
    while ((ch = std::cin.get()) && ch != '$')
        ct++;

    std::cout << "Sum characters: " << ct << '\n';

    return 0;
}