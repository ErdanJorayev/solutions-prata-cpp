#include <iostream>

int main() 
{
    char choice;

    std::cout << "Please enter one of the following choices:\n"
              << "c) carnivore    p) pianist\n"
              << "t) tree         g) game\n";

    while (true) 
    {
        std::cin >> choice;

        switch (choice) 
        {
            case 'c': std::cout << "A tiger is a carnivore.\n"; break;
            case 'p': std::cout << "The pianist is playing.\n"; break;
            case 't': std::cout << "A maple is a tree.\n";      break;
            case 'g': std::cout << "Game start!\n";             break;
            default:
                std::cout << "Please enter a c, p, t, or g: ";
                continue; 
        }
        break;
    }

    return 0;
}
