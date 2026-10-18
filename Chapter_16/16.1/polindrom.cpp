#include <iostream>
#include <string>

bool is_palindrome(const std::string& str) 
{
    if (str.empty()) return true; // Проверка на пустую строку

    size_t start = 0;
    size_t end = str.size() - 1;

    while (start < end) 
        if (str[start++] != str[end++]) 
            return false;
            
    return true;
}

int main() {
    std::string str1{"1234567654321"};

    if (is_palindrome(str1))
        std::cout << "Это строка — палиндром!\n";
    else
        std::cout << "Это строка — не палиндром!\n";

    return 0;
}