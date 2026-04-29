#include <iostream>
#include <string>

using namespace std;

struct pizza
{
    string name_cmp;
    double diametr;
    double weight;
};

int main()
{
    pizza dodopizza;

    cout << "Enter the company: ";
    getline(cin, dodopizza.name_cmp);

    cout << "Enter the diametr: ";
    (cin >> dodopizza.diametr).get();

    cout << "Enter the weight: ";
    (cin >> dodopizza.weight).get();

    cout << "Company name: " << dodopizza.name_cmp << endl;
    cout << "Diametr: " << dodopizza.diametr << endl;
    cout << "Weight: " << dodopizza.weight << endl;
    

    return 0;
}
