#include <iostream>
#include <cstring>

struct stringy
{
    char * str;
    int ct;
};

void set(stringy & beany, const char arr[]);
void show(const stringy & strii, int num = 1); 
void show(const char * str, int num = 1);     

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    
    set(beany, testing);
    show(beany);
    show(beany, 2);
    
    testing[0] = 'D';
    testing[1] = 'u';
    
    show(testing);
    show(testing, 3);
    show("Done!");

    delete[] beany.str; 

    return 0;
}

// Выделяет память и копирует строку
void set(stringy & beany, const char arr[])
{
    beany.ct = std::strlen(arr);
    beany.str = new char[beany.ct + 1];
    std::strcpy(beany.str, arr); 
}
void show(const stringy & strii, int num)
{
    for (int i = 0; i < num; i++)
        std::cout << strii.str << '\n';
}

void show(const char * str, int num)
{
    for (int i = 0; i < num; i++)
        std::cout << str << '\n';
}
