#include <iostream>
#include <string>

using namespace std;

struct car 
{
    string name;
    unsigned int year;
};

int main()
{   
    size_t num = 0;
    
    cout << "Enter the number of cars: ";
    (cin >> num).get();
    car * cPtr = new car[num];

    for (size_t i = 0; i < num; i++)
    {
        cout << "Automobile #" << i + 1 << ":\n";
        cout << "Enter brand: ";
        getline(cin, cPtr[i].name);
        cout << "Enter the year: ";
        (cin >> cPtr[i].year).get();
    }

    cout << "Your collection cars:\n";
    for (size_t i = 0; i < num; i++)
        cout << cPtr[i].year << ' ' 
             << cPtr[i].name << endl;

    delete [] cPtr;

    return 0;
}