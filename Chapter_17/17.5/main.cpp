#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>

std::vector<std::string> getFriends(const char * fname)
{
    std::vector<std::string> names;
    std::string temp;

    std::ifstream frie(fname); 

    while (frie >> temp)
        names.push_back(temp);

    std::sort(names.begin(), names.end());
    
    for (const auto& nm : names)
        std::cout << nm << ' ';
    std::cout << '\n';

    return names; // RVO: ноль копирований
}

int main()
{
    std::cout << "Matt friends:\n";
    const auto matt = getFriends("matt");

    std::cout << "\nPatt friends:\n";
    const auto patt = getFriends("patt");

    // Заполнение set напрямую из векторов — убирает дубликаты и сортирует
    std::set<std::string> all(matt.begin(), matt.end());
    all.insert(patt.begin(), patt.end());

    std::cout << "\nAll guests:\n";
    for (const auto& name : all)
        std::cout << name << ' ';
    std::cout << '\n';
}