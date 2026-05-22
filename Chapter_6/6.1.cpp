#include <iostream>
#include <cctype>

using std::cout;
using std::cin;

int main()
{
    char ch;

    cout << "Enter symbols: (@ to quit)";
    while ((ch = cin.get()) != '@')
    {
        if (isdigit(ch))
            continue;
        else if (islower(ch))
            ch = toupper(ch);
        else 
            ch = tolower(ch);
        cout.put(ch);
    }
    cout << "\nEnd.\n";

    return 0;
}