#include <iostream>
#include "sales.h"

namespace SALES
{
    Sales::Sales(const double ar[], const unsigned int n)
    {
        int limit = (n < QUARTERS) ? n : QUARTERS;
        
        if (limit <= 0)
        {
            min = 0.0;
            max = 0.0;
            average = 0.0;
            for (unsigned i = 0; i < QUARTERS; ++i)
                sales[i] = 0.0;
            return;
        }

        double sum = 0.0;
        min = ar[0];
        max = ar[0];

        for (int i = 0; i < limit; ++i)
        {
            sales[i] = ar[i];
            sum += ar[i];
            if (ar[i] < min) min = ar[i];
            if (ar[i] > max) max = ar[i];
        }

        for (unsigned int i = limit; i < QUARTERS; ++i)
            sales[i] = 0.0;
        

        average = sum / limit;
    }

    void Sales::setSales()
    {
        using std::cout;
        using std::cin;

        double input_ar[QUARTERS];
        cout << "Enter sales for " << QUARTERS << " quarters:\n";
        
        for (int i = 0; i < QUARTERS; ++i)
        {
            cout << "Quarter " << i + 1 << ": ";
            while (!(cin >> input_ar[i])) 
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Invalid input. Please enter a number for Quarter " << i + 1 << ": ";
            }
        }

        *this = Sales(input_ar, QUARTERS);
    }

    void Sales::showSales() const
    {
        using std::cout;
        using std::endl;

        cout << "\n--- Sales Info ---" << endl;
        cout << "Quarterly sales: ";
        for (unsigned int i = 0; i < QUARTERS; ++i)
            cout << sales[i] << " ";
        
        cout << endl;
        cout << "Average: " << average << endl;
        cout << "Maximum: " << max << endl;
        cout << "Minimum: " << min << endl;
        cout << "------------------" << endl;
    }
}
