#include <iostream>
#include <limits>
#include "kek.h" // Replace with your actual header file name

// Helper function to safely clear invalid cin inputs
void clearInput() 
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() 
{
    size_t count = 0;
    std::cout << "=== RUNTIME OBJECT CREATION & POLYMORPHISM ===\n";
    std::cout << "Enter the number of objects to create: ";

    while (!(std::cin >> count) || count <= 0) 
    {
        std::cout << "Please enter a valid positive integer: ";
        clearInput();
    }

    // Allocate an array of pointers to the abstract base class on the heap
    Abstract** items = new Abstract*[count];

    // Populate the array at runtime based on user input
    for (size_t i = 0; i < count; ++i) 
    {
        std::cout << "\n----------------------------------------\n";
        std::cout << "Creating object #" << i + 1 << " of " << count << "\n";
        std::cout << "Select class type:\n";
        std::cout << "1 — baseDMA\n";
        std::cout << "2 — lacksDMA\n";
        std::cout << "3 — hasDMA\n";
        std::cout << "Your choice (1-3): ";

        int choice = 0;
        while (!(std::cin >> choice) || choice < 1 || choice > 3) 
        {
            std::cout << "Invalid choice. Please enter 1, 2, or 3: ";
            clearInput();
        }

        // Prompt for common Abstract parameters
        char label[100];
        int rating = 0;

        std::cout << "Enter label (string): ";
        std::cin >> label;
        std::cout << "Enter rating (integer): ";
        while (!(std::cin >> rating))
        {
            std::cout << "Invalid rating. Enter an integer: ";
            clearInput();
        }

        // Instantiate the selected derived class polymorphically
        switch (choice) 
        {
            case 1: 
                items[i] = new baseDMA(label, rating);
                break;  
            case 2: 
                char color[40];
                std::cout << "Enter color for lacksDMA: ";
                std::cin >> color;
                items[i] = new lacksDMA(color, label, rating);
                break;
            case 3: 
                char style[100];
                std::cout << "Enter style for hasDMA: ";
                std::cin >> style;
                items[i] = new hasDMA(style, label, rating);
                break;
        }
    }

    // =========================================================
    // POLYMORPHIC DISPLAY
    // =========================================================
    std::cout << "\n========================================\n";
    std::cout << "DISPLAYING CREATED OBJECTS (via View()):\n";
    std::cout << "========================================\n";

    for (size_t i = 0; i < count; ++i) 
    {
        std::cout << "\n[Object #" << i + 1 << "]:\n";
        items[i]->View(); // Polymorphic dispatch via vtable
    }

    // =========================================================
    // MEMORY CLEANUP
    // =========================================================
    std::cout << "\nCleaning up memory...\n";
    for (size_t i = 0; i < count; ++i) 
        delete items[i]; 
    
    delete[] items;

    std::cout << "All memory successfully freed. Execution finished.\n";
    return 0;
}