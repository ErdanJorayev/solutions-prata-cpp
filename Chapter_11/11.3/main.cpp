#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "vect.h"

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

    unsigned int N = 0;

    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        
        cout << "Enter total runs: ";
        cin >> N;

        unsigned long max_steps = 0;
        unsigned long min_steps = ULONG_MAX;
        unsigned long total_steps = 0;

        for (unsigned int i = 0; i < N; i++)
        {
            steps = 0;
            result.reset(0.0, 0.0);

            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }

            total_steps += steps;

            if (steps > max_steps)
                max_steps = steps;
            if (steps < min_steps)
                min_steps = steps;
        }

        cout << "Max steps: " << max_steps << '\n';
        cout << "Min steps: " << min_steps << '\n';
        cout << "Average steps: " << (double)total_steps / N << '\n'; 
        
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    return 0;
}

