#include <iostream>

const size_t S = 5;

template <typename T>
T max5(T * arr);

int main()
{
    int arr1[5]{22, 33, 512, 1, 12};
    double arr2[5]{33.3, 21.2, 54.22, 111, 14.14};

    std::cout << "Max in int array: " << max5(arr1) << '\n';
    std::cout << "Max in double array: " << max5(arr2) << '\n';

    return 0;
}

template <typename T>
T max5(T * arr)
{
    T max = arr[0];
    for (size_t i = 1; i < S; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}