#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int m = 12;
    const char* months[m] = 
    {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };
    unsigned int books[m];
    unsigned int sum = 0;

    cout << "Enter your sales in every months:\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Enter " << months[i] << " sales: ";
        cin >> books[i];
        sum += books[i];
    } 

    cout << "In year sales " << sum << " books\n";

    return 0;
}