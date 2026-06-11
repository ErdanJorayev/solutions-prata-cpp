#include <iostream>

using namespace std;

int main()
{
    long long world_pop = 0;
    long long us_pop = 0;

    cout << "Enter the world's population: ";
    cin >> world_pop;

    cout << "Enter the population of the US: ";
    cin >> us_pop;

    // Явное приведение к double для точного деления
    double percent = (double)us_pop / world_pop * 100.0;

    cout << "The population of the US is " << percent 
         << "% of the world population." << endl;

    return 0;
}
