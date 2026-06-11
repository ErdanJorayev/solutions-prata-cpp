#include <iostream>
#include <string>
#include <iomanip>
struct CandyBar
{
    std::string name;
    double weight;
    unsigned int calories;
};

void candy(CandyBar & cbr, const char * name = "Millenium Munch", 
                 double w = 2.85, unsigned int cl = 350);

void show(const CandyBar & cbr);

int main()
{
    CandyBar kek;
    
    candy(kek); 
    
    show(kek); 
    return 0;
}

// В реализации функции значения по умолчанию писать больше НЕЛЬЗЯ!
void candy(CandyBar & cbr, const char * name, double w, unsigned int cl)
{
    cbr.name = name;
    cbr.weight = w;
    cbr.calories = cl;
}

void show(const CandyBar & cbr)
{
    // Манипуляторы работают идеально
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Name: " << cbr.name << '\n'
              << "Weight: " << cbr.weight << '\n'
              << "Calories: " << cbr.calories << '\n';
}
