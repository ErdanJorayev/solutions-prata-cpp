#include <iostream>
#include "golf.h"

int main()
{
    golf arr[4]{};
    setgolf(arr[0], "Alex Mercer", 23);

    size_t actual_count = 1; // Будем считать, сколько игроков реально заполнили
    for (size_t i = 1; i < 4; i++)
    {
        std::cout << "Enter player #" << i + 1 << '\n';
        // ИСПРАВЛЕНО: прерываем, если функция вернула 0 (пустая строка)
        if (!setgolf(arr[i])) 
            break;
        actual_count++; 
    }

    if (actual_count > 1) 
    {
        std::cout << "Enter new handicap in player #2: ";
        int num = 0;
        std::cin >> num;
        handicap(arr[1], num);
    }

    std::cout << "\n--- All Players ---\n";
    for (size_t i = 0; i < actual_count; i++)
        showgolf(arr[i]);

    std::cout << "\nEnd\n";
    return 0;
}
