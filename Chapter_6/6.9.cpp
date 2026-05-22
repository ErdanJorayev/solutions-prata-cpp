#include <iostream>
#include <string>
#include <fstream>

struct vipDefendGroup 
{
    std::string name;
    double donation;
};

int main() 
{
    const int LIMIT = 30; // Используем четкое имя для константы
    vipDefendGroup arr[LIMIT];
    
    std::ifstream inFile;
    std::string filename;

    std::cout << "Enter name of data file: ";
    std::getline(std::cin, filename);

    inFile.open(filename);
    if (!inFile.is_open()) 
    {
        std::cout << "Could not open the file " << filename << '\n';
        return 1;
    }

    unsigned int actual_count = 0;

    while (actual_count < LIMIT && (inFile >> arr[actual_count].donation)) 
    {
        inFile.get(); 
        if (!std::getline(inFile, arr[actual_count].name)) 
            break; 
        actual_count++;
    }

    std::cout << "\nGrand Patrons:\n";
    bool empty = true;

    for (size_t i = 0; i < actual_count; i++) 
    {
        if (arr[i].donation >= 10000) 
        {
            std::cout << arr[i].name << " - " << arr[i].donation << '\n';
            empty = false;
        }
    }
    if (empty) std::cout << "none\n";

    std::cout << "\nPatrons:\n";
    empty = true;
    for (size_t i = 0; i < actual_count; i++) 
    {
        if (arr[i].donation < 10000) 
        {
            std::cout << arr[i].name << " - " << arr[i].donation << '\n';
            empty = false;
        }
    }
    if (empty) std::cout << "none\n";

    return 0;
}
