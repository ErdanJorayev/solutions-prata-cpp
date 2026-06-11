#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf() {
    fullname[0] = '\0';
    handicap_value = 0;
}

Golf::Golf(const char* name, int hc) 
{
    std::strncpy(fullname, name, LEN - 1);
    fullname[LEN - 1] = '\0';
    handicap_value = hc;
}

int Golf::setgolf() 
{
    char temp_name[LEN];
    int temp_hc;

    std::cout << "Enter player name (or hit Enter to quit): ";
    std::cin.getline(temp_name, LEN);

    if (temp_name[0] == '\0') 
        return 0;
    

    std::cout << "Enter handicap: ";
    while (!(std::cin >> temp_hc)) 
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Please enter an integer for handicap: ";
    }
    std::cin.get();

    *this = Golf(temp_name, temp_hc);
    return 1;
}

void Golf::handicap(int hc) 
{
    handicap_value = hc;
}

void Golf::showgolf() const
 {
    if (fullname[0] == '\0') 
        std::cout << "[Empty player profile]\n";
    else 
        std::cout << "Player: " << fullname << ", Handicap: " << handicap_value << "\n";
    
}
