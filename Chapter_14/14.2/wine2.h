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
    T1 & first() { return a; }
    T2 & second() { return b; }

    const T1 & first() const { return a; }
    const T2 & second() const { return b; }

    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair() {}
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;


class Wine : private std::string, private PairArray
{
private: 
    int years;         // Количество лет урожая
public:
    Wine() : std::string("no name"), years(0) {}

    Wine(const char * l, int y, const int yr[], const int bot[])
        : std::string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)), years(y) {}

    Wine(const char * l, int y) 
        : std::string(l), PairArray(ArrayInt(y), ArrayInt(y)), years(y) {}

    void GetBottles();
    const std::string & Label() const { return (const std::string &)*this; } 
    void Show() const;
    int sum() const; 
};


void Wine::GetBottles()
{
    std::cout << "Enter data for " << (const std::string &)*this << " for " << years << " year(s):\n";
    for (int i = 0; i < years; ++i)
    {
        std::cout << "Enter year: ";
        std::cin >> PairArray::first()[i]; 
        std::cout << "Enter bottles: ";
        std::cin >> PairArray::second()[i];
    }
}

int Wine::sum() const
{
    return PairArray::second().sum(); 
}

void Wine::Show() const
{
    std::cout << "Wine: " << (const std::string &)*this << "\n";
    std::cout << "\tYear\tBottles\n";
    for (int i = 0; i < years; ++i)
    {
        std::cout << "\t" << PairArray::first()[i] 
                  << "\t" << PairArray::second()[i] << "\n";
    }
}