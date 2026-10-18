#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <chrono>

int main() 
{
    constexpr std::size_t N = 1000000; // 1 000 000 элементов

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 1000000);

    std::vector<int> vi0(N);
    std::generate(vi0.begin(), vi0.end(), [&]() { return dist(gen); });

    std::vector<int> vi = vi0;
    std::list<int> li(vi0.begin(), vi0.end());

    std::cout << "Testing with " << N << " elements...\n\n";

    auto start_vector = std::chrono::high_resolution_clock::now();
    
    std::sort(vi.begin(), vi.end());
    
    auto end_vector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_vector = end_vector - start_vector;
    
    std::cout << "1. std::sort(vector): " << time_vector.count() << " s\n";

    auto start_list = std::chrono::high_resolution_clock::now();
    
    li.sort();
    
    auto end_list = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_list = end_list - start_list;
    
    std::cout << "2. list::sort():       " << time_list.count() << " s\n";

    // Сначала восстанавливаем неотсортированные данные в li
    li.assign(vi0.begin(), vi0.end());

    auto start_hybrid = std::chrono::high_resolution_clock::now();

    // Копируем list в vector
    std::vector<int> temp_vi(li.begin(), li.end());
    // Сортируем vector
    std::sort(temp_vi.begin(), temp_vi.end());
    // Копируем отсортированные данные обратно в list
    li.assign(temp_vi.begin(), temp_vi.end());

    auto end_hybrid = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_hybrid = end_hybrid - start_hybrid;

    std::cout << "3. Hybrid (copy list->vector, std::sort, copy back->list): " 
              << time_hybrid.count() << " s\n";

    return 0;
}