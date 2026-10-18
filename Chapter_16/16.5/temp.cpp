#include <iostream>
#include <algorithm>

template <typename T>
int reduce(T ar[], int n);

int main()
{
    long arr[]{23, 455, 66, 66, 432, 11, 11, 24};
    int total_elements = sizeof(arr) / sizeof(arr[0]); // 8

    std::cout << "Исходный массив: ";
    for (int i = 0; i < total_elements; ++i)
        std::cout << arr[i] << " ";

    int n_size = reduce(arr, total_elements);

    std::cout << "\nПосле reduce (уникальные " << n_size << " элементов): ";
    for (int i = 0; i < n_size; ++i)
        std::cout << arr[i] << " ";

    std::string str_arr[]{"alex", "erdan", "alex", "kek", "ted", "kek"};
    total_elements = sizeof(str_arr) / sizeof(str_arr[0]);

    std::cout << '\n';

    std::cout << "Исходный массив: ";
    for (int i = 0; i < total_elements; ++i)
        std::cout << str_arr[i] << " ";

    n_size = reduce(str_arr, total_elements);

    std::cout << "\nПосле reduce (уникальные " << n_size << " элементов): ";
    for (int i = 0; i < n_size; ++i)
        std::cout << str_arr[i] << " ";

    std::cout << "\n";

    return 0;
}

template <typename T>
int reduce(T ar[], int n)
{
    if (n <= 0)
        return 0;

    std::sort(ar, ar + n);
    return static_cast<int>(std::unique(ar, ar + n) - ar);
}