#include <iostream>
#include <string>
#include <valarray>
#include <iomanip> // Для красивого вывода в Show()

template <typename T1, typename T2>
class Pair
{
private:
    T1 a; 
    T2 b; 
public:
    // Неконстантные версии возвращают ссылки для модификации
    T1 & first() { return a; }
    T2 & second() { return b; }

    // Константные версии возвращают CONST-ссылки (без лишнего копирования!)
    const T1 & first() const { return a; }
    const T2 & second() const { return b; }

    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair() {}
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private: 
    std::string label; // Название вина
    int years;         // Количество лет урожая
    PairArray pair;    // pair.first() — годы, pair.second() — бутылки

public:
    Wine() : label("no name"), years(0) {}

    Wine(const char * l, int y, const int yr[], const int bot[])
        : label(l), years(y), pair(ArrayInt(yr, y), ArrayInt(bot, y)) {}

    Wine(const char * l, int y) 
        : label(l), years(y), pair(ArrayInt(y), ArrayInt(y)) {}

    void GetBottles();
    const std::string & Label() const { return label; } 
    void Show() const;
    int sum() const; 
};


void Wine::GetBottles()
{
    std::cout << "Enter data for " << label << " for " << years << " year(s):\n";
    for (int i = 0; i < years; ++i)
    {
        std::cout << "Enter year: ";
        std::cin >> pair.first()[i]; 
        std::cout << "Enter bottles: ";
        std::cin >> pair.second()[i];
    }
}

int Wine::sum() const
{
    return pair.second().sum(); 
}

void Wine::Show() const
{
    std::cout << "Wine: " << label << "\n";
    std::cout << "\tYear\tBottles\n";
    for (int i = 0; i < years; ++i)
    {
        std::cout << "\t" << pair.first()[i] 
                  << "\t" << pair.second()[i] << "\n";
    }
}