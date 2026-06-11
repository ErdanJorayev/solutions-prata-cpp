#include <iostream>

const size_t N = 4;

using pfun = double (*)(double n1, double n2);
double calculate(double a, double b, pfun kek) {return kek(a, b);}
double add(double x, double y) {return x + y;}
double mult(double x, double y) {return x * y;}
double sub(double x, double y) {return x - y;}
double div(double x, double y) {return x / y;}
int main()
{
    double a = 0, b = 0;
    pfun arr_fun[N]{add, mult, sub, div};
    const char * kek{"+*-/"};

    std::cout << "Enter 2 numbers: (q to quit)\n";
    while (std::cin >> a >> b)
    {
        for (size_t i = 0; i < N; i++)
            std::cout << a << kek[i] << b << " = " 
                      << calculate(a, b, arr_fun[i]) << '\n';

        std::cout << "Enter the next numbers: ";
    }
    std::cout << "\nBye!\n";

    return 0;
}
