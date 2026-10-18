#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

std::vector<std::string> getFriends()
{
    std::vector<std::string> names;
    std::string temp;

    while (std::cin >> temp && temp != "end")
        names.push_back(temp);

    std::sort(names.begin(), names.end());
    
    for (const auto& nm : names)
        std::cout << nm << ' ';
    std::cout << '\n';

    return names; // RVO: ноль копирований
}

int main()
{
    std::cout << "Enter friends Matt (end to exit):\n";
    const auto matt = getFriends();

    std::cout << "\nEnter friends Patt (end to exit):\n";
    const auto patt = getFriends();

    // Заполнение set напрямую из векторов — убирает дубликаты и сортирует
    std::set<std::string> all(matt.begin(), matt.end());
    all.insert(patt.begin(), patt.end());

    std::cout << "\nAll guests:\n";
    for (const auto& name : all)
        std::cout << name << ' ';
    std::cout << '\n';
}