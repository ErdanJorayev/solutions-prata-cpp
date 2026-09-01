#include "pers.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "=== 1. ТЕСТ ОБЫЧНЫХ ОБЪЕКТОВ ===" << std::endl;
    
    Person civilian("John", "Doe");
    Gunslinger shooter("Clint", "Eastwood", 12.5); // 12.5 сек время готовности
    PokerPlayer gambler("Lucky", "Luke");
    BadDude villain("El", "Mariachi", 8.2);

    std::cout << "-- Civilian --\n";
    civilian.Show();
    std::cout << "\n-- Gunslinger --\n";
    shooter.Show();
    std::cout << "\n-- PokerPlayer --\n";
    gambler.Show();
    std::cout << "\n-- BadDude --\n";
    villain.Show();

    std::cout << "\n=== 2. ТЕСТ УНИКАЛЬНЫХ МЕТОДОВ BADDUDE ===" << std::endl;
    std::cout << "Gdraw (Время выстрела): " << villain.Gdraw() << " сек" << std::endl;
    std::cout << "Cdraw (Случайная карта): " << villain.Cdraw() << std::endl;

    std::cout << "\n=== 3. ТЕСТ ПОЛИМОРФИЗМА (МАССИВ УКАЗАТЕЛЕЙ) ===" << std::endl;
    /
    Person* gang[4];
    gang[0] = &civilian;
    gang[1] = &shooter;
    gang[2] = &gambler;
    gang[3] = &villain;

    for (int i = 0; i < 4; ++i)
    {
        std::cout << "--- Член банды #" << i + 1 << " ---\n";
        gang[i]->Show(); 
        std::cout << std::endl;
    }

    return 0;
}