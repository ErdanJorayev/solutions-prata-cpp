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
    CandyBar snack[3] = {{"Mocha Munch", 2.3, 350},
                         {"Keke Lol", 5.4, 222},
                         {"Swetie Fox", 44.3, 2545}};

    cout << "Name: " << snack[0].name << endl;
    cout << "Weight: " << snack[0].weight << endl;
    cout << "Calories: " << snack[0].calories << endl;

    cout << "Name: " << snack[1].name << endl;
    cout << "Weight: " << snack[1].weight << endl;
    cout << "Calories: " << snack[1].calories << endl;

    cout << "Name: " << snack[2].name << endl;
    cout << "Weight: " << snack[2].weight << endl;
    cout << "Calories: " << snack[2].calories << endl;
    return 0;
} 