#include <iostream>

const size_t N = 10;

size_t in_arr(unsigned int arr[], size_t size);
double aver(unsigned int arr[], size_t size);
void show(unsigned int arr[], size_t size);
int main()
{
    unsigned int arr[N];

    size_t num = in_arr(arr, N);
    if (num)
        show(arr, num);
    std::cout << "\nEnd\n";
    return 0;
}

size_t in_arr(unsigned int arr[], size_t size)
{
    size_t count = 0;
    std::cout << "Enter 10 numbers result in golf:\n";
    while (count < size && std::cin >> arr[count])
        count++;

    return count;
}

double aver(unsigned int arr[], size_t size)
{
    unsigned int sum = 0;
    for (size_t i = 0; i < size; i++)
        sum += arr[i];
    return static_cast<double>(sum) / size;
}

void show(unsigned int arr[], size_t size)
{
    std::cout << "Your results: ";
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
    std::cout << "\nAverage: " << aver(arr, size);
}