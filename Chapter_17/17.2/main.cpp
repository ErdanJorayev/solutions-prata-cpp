#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " filenames\n";
        exit(EXIT_FAILURE);
    }

    std::ofstream file(argv[1]);

    if (!file.is_open())
    {
        std::cerr << "Could not open " << argv[1] << '\n';
        exit(EXIT_FAILURE);
    }

    char ch;
    int count = 0;

    while ((std::cin.get(ch)))
        file << ch;
    
    if (std::cin.eof())
        std::cout << "End of file.\n";


    return 0;
}