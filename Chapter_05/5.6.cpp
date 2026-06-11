#include <iostream>

using namespace std;

int main()
{
    const size_t m = 12;
    const size_t y = 3;
    const char* months[m] = 
    {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };
    unsigned int books[y][m]{};
    unsigned int every_year = 0;
    unsigned int in_one_year[y]{};

    cout << "Enter your sales in every months:\n";
    for (size_t n = 0; n < y; n++)
    {
        cout << "Enter for " << n + 1 << " year\n";
        for (size_t i = 0; i < m; i++)
        {
            cout << "Enter " << months[i] << " sales: ";
            cin >> books[n][i];
            in_one_year[n] += books[n][i];
            every_year += books[n][i];
         } 
    }
    for (size_t n = 0; n < y; n++)
        cout << "In " << n + 1 
             << " year sales " << in_one_year[n] << endl;
    cout << "In every year sales: " << every_year << endl;
    
    return 0;
}