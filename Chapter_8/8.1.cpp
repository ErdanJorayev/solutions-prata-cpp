#include <iostream>

void show_str(const char * str, int num = 0);

int main()
{
    show_str("kek");
    show_str("Hehe", 2);
    show_str("Lol", -1);

    return 0;
}
void show_str(const char * str, int num)
{
    static size_t N = 1;
    if (num != 0)
    {
        for (size_t i = 0; i < N; i++)
            std::cout << str << '\n';
    }
    else
        std::cout << str << '\n';
    
    N++;
}