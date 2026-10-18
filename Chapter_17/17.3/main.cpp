#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Not 2 file.\n";
        exit(EXIT_FAILURE);
    }

    std::ifstream infl(argv[1]);
    std::ofstream onfl(argv[2]);

    if (!infl.is_open())
    {
        std::cerr << "Not open " << argv[1] << '\n';
        exit(EXIT_FAILURE);
    }

    if (!onfl.is_open())
    {
        std::cerr << "Not open " << argv[2] << '\n';
        exit(EXIT_FAILURE);
    }

    char ch;

    while (infl.get(ch))
        onfl << ch;

    return 0;
}