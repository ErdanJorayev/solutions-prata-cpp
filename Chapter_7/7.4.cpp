#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;

    unsigned total_numbers = 47;
    unsigned total_picks = 5;
    unsigned mega_range = 27;

    long double field_chance = probability(total_numbers, total_picks);

    long double mega_chance = probability(mega_range, 1);

    long double total_chance = field_chance * mega_chance;

    cout << "You have one chance in ";
    cout << fixed; 
    cout.precision(0); 
    cout << total_chance << " of winning the grand prize.\n";

    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;

    return result;
}
