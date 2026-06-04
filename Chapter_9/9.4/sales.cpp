#include <iostream>
#include "sales.h"

namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        int limit = (n < QUARTERS) ? n : QUARTERS;
        
        if (limit <= 0)
        {
            s.min = 0.0;
            s.max = 0.0;
            s.average = 0.0;
            for (int i = 0; i < QUARTERS; ++i)
                s.sales[i] = 0.0;
            return;
        }

        double sum = 0.0;
        s.min = ar[0];
        s.max = ar[0];

        for (int i = 0; i < limit; ++i)
        {
            s.sales[i] = ar[i];
            sum += ar[i];
            if (ar[i] < s.min) s.min = ar[i];
            if (ar[i] > s.max) s.max = ar[i];
        }

        for (int i = limit; i < QUARTERS; ++i)
        {
            s.sales[i] = 0.0;
        }

        s.average = sum / limit;
    }

    void setSales(Sales & s)
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

        setSales(s, input_ar, QUARTERS);
    }

    void showSales(const Sales & s)
    {
        using std::cout;
        using std::endl;

        cout << "\n--- Sales Info ---" << endl;
        cout << "Quarterly sales: ";
        for (int i = 0; i < QUARTERS; ++i)
        {
            cout << s.sales[i] << " ";
        }
        cout << endl;
        cout << "Average: " << s.average << endl;
        cout << "Maximum: " << s.max << endl;
        cout << "Minimum: " << s.min << endl;
        cout << "------------------" << endl;
    }
}
