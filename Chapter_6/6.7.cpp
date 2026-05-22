#include <iostream>
#include <string>
#include <cctype> // для isalpha

using namespace std;

int main() 
{
    string word;
    unsigned int vowels = 0;     
    unsigned int consonants = 0; 
    unsigned int others = 0;      

    cout << "Enter words (q to quit):" << endl;

    while (cin >> word && word != "q") 
    {
        if (isalpha(word[0])) 
        {
            char ch = tolower(word[0]);

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') 
                vowels++;
            else 
                consonants++;
        } 
        else 
            others++;
    }

    cout << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " others" << endl;

    return 0;
}
