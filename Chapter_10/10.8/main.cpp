#include <iostream>
#include "list.h"

void displayItem(Item & item) 
{
    std::cout << item << " ";
}

void squareItem(Item & item) 
{
    item = item * item;
}

int main() 
{
    List myList;

    std::cout << "--- Test 1: Empty check ---\n";
    std::cout << "Is list empty? " << (myList.listempty() ? "Yes" : "No") << "\n";

    std::cout << "\n--- Test 2: Adding items up to MAX ---\n";
    for (unsigned int i = 1; i <= 12; ++i) 
    {
        if (myList.listpush(i * 5)) 
        {
            std::cout << "Pushed: " << i * 5 << "\n";
        } 
        else 
        {
            std::cout << "Failed to push: " << i * 5 << " (List full)\n";
        }
    }

    std::cout << "\n--- Test 3: List status ---\n";
    std::cout << "Is list empty? " << (myList.listempty() ? "Yes" : "No") << "\n";
    std::cout << "Is list full? " << (myList.listfull() ? "Yes" : "No") << "\n";

    std::cout << "\n--- Test 4: Displaying list elements ---\n";
    std::cout << "List contents: ";
    myList.visit(displayItem);
    std::cout << "\n";

    std::cout << "\n--- Test 5: Modifying elements using visit ---\n";
    std::cout << "Squaring all items...\n";
    myList.visit(squareItem);
    
    std::cout << "Updated contents: ";
    myList.visit(displayItem);
    std::cout << "\n";

    return 0;
}
