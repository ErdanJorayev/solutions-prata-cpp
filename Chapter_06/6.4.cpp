#include <iostream>

const size_t strsize = 20;
const size_t arsize = 5;
struct  bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};


int main()
{   
    bop members[arsize] = 
    {
        {"Wimp Macho", "Junior Programmer", "WIMPY", 0},
        {"Raki Rhodes", "Middle Developer", "RAKI", 1},
        {"Celia Laiter", "Senior QA", "MIPS", 2},
        {"Hoppy Hipman", "Analyst", "HOPPY", 1},
        {"Pat Hand", "Project Manager", "LOOPY", 2}
    };
    char ch;

    std::cout << "Benevolent Order of Programmers Report\n";
    std::cout << "a. display by name     b. display by title\n"
              << "c. display by bopname  d. display by preference\n"
              << "q. quit" << std::endl;

    std::cout << "Enter your choice: ";
    while (true)
    {
        std::cin >> ch;
        switch (ch)
        {
            case 'a': for (size_t i = 0; i < arsize; i++) 
                              std:: cout << members[i].fullname << '\n';
                        break;
            case 'b': for (size_t i = 0; i < arsize; i++) 
                              std:: cout << members[i].title << '\n';
                        break;
            case 'c': for (size_t i = 0; i < arsize; i++) 
                              std:: cout << members[i].bopname << '\n';
                        break;
            case 'd': for (size_t i = 0; i < arsize; i++)
                       {
                            if (members[i].preference == 0)
                                std:: cout << members[i].fullname << '\n';
                            else if (members[i].preference == 1)
                                std:: cout << members[i].title << '\n';
                            else
                                std:: cout << members[i].bopname << '\n';
                       }
                        break;
            case 'q': break;
            default: std::cout << "Please enter a, b, c, d or q ";
                     continue;
        }
        if (ch == 'q')
            break;
        std::cout << "Next choice: ";
    }
    std::cout << "Bye!\n";

    return 0;
}