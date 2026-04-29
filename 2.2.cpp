#include <iostream>

int main() {
    double furlongs;
    
    std::cout << "Enter distance in furlongs: ";
    std::cin >> furlongs;
    
    double yards = furlongs * 220;
    
    std::cout << furlongs << " furlongs = " << yards << " yards.\n";
    
    return 0;
}
