#include <iostream>
#include <cstring> 
template <typename T>
T maxn(const T arr[], size_t n)
{
    T max_val = arr[0];
    for (size_t i = 1; i < n; i++)
        if (arr[i] > max_val)
            max_val = arr[i];

    return max_val;
}

template <> 
const char* maxn<const char*>(const char* const arr[], size_t n)
{
    int max_index = 0;
    size_t max_len = std::strlen(arr[0]);

    for (size_t i = 1; i < n; i++)
    {
        size_t current_len = std::strlen(arr[i]);
        if (current_len > max_len)
        {
            max_len = current_len;
            max_index = i;
        }
    }
    return arr[max_index];
}

int main()
{
    int int_arr[6] = {10, 45, 2, 99, 34, 50};
    std::cout << "Max int: " << maxn(int_arr, 6) << "\n";

    double double_arr[4] = {12.5, 88.33, 91.4, 43.12};
    std::cout << "Max double: " << maxn(double_arr, 4) << "\n";

    const char* str_arr[5] = 
    {
        "Apple",
        "Banana", 
        "Kiwi",
        "Cherry",
        "Fig"
    };
    
    std::cout << "Longest string address returns: " << maxn(str_arr, 5) << "\n";

    return 0;
}
