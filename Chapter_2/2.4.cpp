#include <iostream>

int main() {
    int age;
    
    std::cout << "Enter your age: ";
    std::cin >> age;
    
    int months = age * 12;
    
    std::cout << "Your age in months is " << months << ".\n";
    
    return 0;
}
