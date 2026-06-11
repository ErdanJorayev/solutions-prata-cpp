#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

int main()
{
    unsigned int count = 0;
    char arr[20];

    cout << "Enter words (for end enter \"done\")\n";
    cin >> arr;
    for (count = 0; strcmp(arr, "done"); count++)
        cin >> arr;

    cout << "Your enter " << count << " words.\n";

    return 0;
}