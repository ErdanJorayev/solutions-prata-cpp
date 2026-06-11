
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
    CandyBar * snack = new CandyBar[3];
    
    snack[0] = {"Mocha Munch", 2.3, 350};
    snack[1] = {"Keke Lol", 5.4, 222};
    snack[2] = {"Swetie Fox", 44.3, 2545};

    cout << "Name: " << snack[0].name << endl;
    cout << "Weight: " << snack[0].weight << endl;
    cout << "Calories: " << snack[0].calories << endl;

    cout << "Name: " << snack[1].name << endl;
    cout << "Weight: " << snack[1].weight << endl;
    cout << "Calories: " << snack[1].calories << endl;

    cout << "Name: " << snack[2].name << endl;
    cout << "Weight: " << snack[2].weight << endl;
    cout << "Calories: " << snack[2].calories << endl;

    delete [] snack;

    return 0;
}