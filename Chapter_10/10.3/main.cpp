#include <iostream>
#include "golf.h"

int main() 
{
    std::cout << "--- Test 1: Constructor with parameters ---\n";
    Golf g1("Ann Birdfree", 24);
    g1.showgolf();

    std::cout << "\n--- Test 2: Changing handicap ---\n";
    g1.handicap(28);
    g1.showgolf();

    std::cout << "\n--- Test 3: Interactive player entry ---\n";
    const int MAX_PLAYERS = 3;
    Golf team[MAX_PLAYERS];

    int count = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) 
    {
        std::cout << "\nPlayer #" << i + 1 << ":\n";
        if (team[i].setgolf() == 0) 
        {
            std::cout << "Input terminated by user.\n";
            break;
        }
        count++;
    }

    std::cout << "\n--- Final team roster ---\n";
    for (int i = 0; i < count; i++) {
        team[i].showgolf();
    }

    return 0;
}
