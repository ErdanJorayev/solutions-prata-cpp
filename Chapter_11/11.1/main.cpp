#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "vector.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    ofstream outFile("kek.txt");
    if (!outFile.is_open())
    {
        cout << "Not open file\n";
        return 1;
    }

    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        outFile << "Target Distance: " << target << ", "
                << "Step Size: " << dstep << '\n';
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            result.rect_mode();
            outFile << steps << ": " << result << '\n';
            steps++;
        }
        outFile << "After " << steps << " steps, the subject "
               "has the following location:\n";
        outFile << result << endl;
        result.polar_mode();
        outFile << " or\n" << result << endl;
        outFile << "Average outward distance per step = "
             << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}