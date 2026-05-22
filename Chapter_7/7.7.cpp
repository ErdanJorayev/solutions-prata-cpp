#include <iostream>
const int Max = 5;

double * fill_array(double * begin, double * end);
void show_array(const double * begin, const double * end);   
void revalue(double r, double * begin, double * end);

int main()
{
    double properties[Max];
    
    double * current_end = fill_array(properties, properties + Max);
    
    show_array(properties, current_end);
    
    if (properties != current_end)
    {
        std::cout << "Enter revaluation factor: "; 
        double factor;
        while (!(std::cin >> factor))              
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input; Please enter a number: "; 
        }
        revalue(factor, properties, current_end);
        show_array(properties, current_end);
    }
    std::cout << "Done.\n";
    std::cin.get();
    std::cin.get();
    return 0;
}

double * fill_array(double * begin, double * end)
{
    double temp = 0;
    int i = 0; 
    while (begin < end)
    {
        std::cout << "Enter value #" << (i + 1) << ": "; 
        std::cin >> temp;
        if (!std::cin)                                 
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)                      
            break;
            
        *begin++ = temp;
        i++;
    }

    return begin; 
}

void show_array(const double * begin, const double * end)
{
    size_t i = 0;
    while (begin < end)
    {
        std::cout << "Property #" << (i + 1) << ": $";
        std::cout << *begin++ << '\n';
        i++;
    }
}

void revalue(double r, double * begin, double * end)
{
    while (begin < end)
    {
        *begin *= r;
        begin++;
    }
}
