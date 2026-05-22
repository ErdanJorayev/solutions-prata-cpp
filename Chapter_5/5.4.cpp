#include <iostream>

using namespace std;

int main()
{
    double daphne = 100.0;
    double kleo = 100.0;
    unsigned years = 0;

    cout << "Years\tDaphne\tKleo\n";

    while (kleo <= daphne) 
    { 
        years++;
        daphne += 10.0;             
        kleo += kleo * 0.05;       
        cout << years << "\t" << daphne << "\t" << kleo << endl;
    }


    cout << "In year " << years 
         << " Cleo's profit exceeded Daphne's profit\n";
    return 0;
}