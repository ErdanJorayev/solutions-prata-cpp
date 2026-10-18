#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric> // для std::iota

using std::vector;

auto Lotto(int nums_card, int rand_select)
{
    // Защита от выхода за границы
    if (rand_select > nums_card)
        rand_select = nums_card;

    vector<int> all_nums(nums_card);
    std::iota(all_nums.begin(), all_nums.end(), 1); // Заполняет числами 1, 2, 3...

    std::mt19937 g(std::random_device{}());
    std::shuffle(all_nums.begin(), all_nums.end(), g);

    return vector<int>(all_nums.begin(), all_nums.begin() + rand_select);
}

int main()
{
    vector<int> winners = Lotto(51, 6);

    std::cout << "Winners:\n";
    for (const auto& n : winners)
        std::cout << n << ' ';
    
    std::cout.put('\n');

    return 0;
}