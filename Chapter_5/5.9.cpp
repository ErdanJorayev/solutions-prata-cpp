#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    unsigned int count = 0;
    string str;

    cout << "Enter words (for end enter \"done\")\n";
    cin >> str;
    for (count = 0; str != "done"; count++)
        cin >> str;

    cout << "Your enter " << count << " words.\n";

    return 0;
}