#include <iostream>

size_t Fill_array(double arr[], size_t size);
void Show_array(double arr[], size_t size);
void Reverse_array(double arr[], size_t size);

const size_t N = 10;

int main()
{   
    double arr[N];
    
    size_t real_size = Fill_array(arr, N);
    if (real_size)
        Reverse_array(arr, real_size);
    if (real_size)
        Show_array(arr, real_size);
    std::cout << "\nBye\n";

    return 0;
}

size_t Fill_array(double arr[], size_t size)
{
    size_t count = 0;
    std::cout << "Enter the numbers: ";
    while (count < size && std::cin >> arr[count])
        count++;
    
    return count;
}

void Show_array(double arr[], size_t size)
{
    std::cout << "Your array:\n";
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

void Reverse_array(double arr[], size_t size)
{
    if (size < 3)
        return;

    double temp = 0;

    for (size_t i = 1, a = size - 2; i < a; i++, a--)
    {
        temp = arr[i];
        arr[i] = arr[a];
        arr[a] = temp;
    }
}

