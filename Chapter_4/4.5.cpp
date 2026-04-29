#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string name;
    double weight;
    unsigned int calories;
};

int main()
{
    CandyBar snack = {"Mocha Munch", 2.3, 350};

    cout << "Name: " << snack.name << endl;
    cout << "Weight: " << snack.weight << endl;
    cout << "Calories: " << snack.calories << endl;

    return 0;
}