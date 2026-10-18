#include <iostream>
#include <string>
#include <cctype>

bool is_palindrome(const std::string& str) 
{
    std::string filtered;

    for (unsigned char c : str) 
        if (std::isalnum(c)) 
            filtered += static_cast<char>(std::tolower(c));

    if (filtered.empty()) return true;

    size_t start = 0;
    size_t end = filtered.size() - 1;

    while (start < end) 
        if (filtered[start++] != filtered[end--]) 
            return false;
        
    return true;
}

int main() {
    std::string str1{"123456765444d4ddtgg6s34321"};
    std::string str2{"A man, a plan, a canal: Panama"};

    std::cout << (is_palindrome(str1) ? "Палиндром\n" : "Не палиндром\n");
    std::cout << (is_palindrome(str2) ? "Палиндром\n" : "Не палиндром\n");

    return 0;
}