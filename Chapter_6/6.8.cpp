#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main()
{
    std::string filename;
    std::ifstream inFile;
    
    std::cout << "Enter name of data file: ";
    std::getline(std::cin, filename);
    inFile.open(filename);
    if (!inFile.is_open())
    {
        std::cout << "Could not open the file " << filename << '\n';
        std::cout << "Program terminating.\n";
        std::exit(EXIT_FAILURE);
    }
    size_t count = 0;
    inFile.get();
    while (inFile.get())
        ++count;

    if (inFile.eof())
        std::cout << "End of file reached.\n";
    
    if (count == 0)
        std::cout << "No data processed.\n";
    else
        std::cout << "Symbols in file: " << count << '\n';
    
    inFile.close();
    
    return 0;
}