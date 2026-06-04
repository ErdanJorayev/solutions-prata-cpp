#include <iostream>

const size_t N = 20;

struct chaff
{
    char dross[N];
    int slag;
};

alignas(chaff) char buffer[sizeof(chaff) * 2];

int main()
{
    chaff * ptr = new (buffer) chaff[2];

    for (size_t i = 0; i < 2; i++)
    {
        std::cout << "Enter the dross: ";
        std::cin.getline(ptr[i].dross, N);
        std::cout << "Enter the slag: ";
        (std::cin >> ptr[i].slag).get();
    }
    
    std::cout << "\n--- Output ---\n";
    for (size_t i = 0; i < 2; i++)
    {
        std::cout << "Dross: " << ptr[i].dross << '\n';
        std::cout << "Slag: " << ptr[i].slag << '\n';
    }

    return 0;
}
