#include <iostream>
#include <cctype>
#include "stack.h"
int main()
{
    using namespace std;
    Stack st;            // MAX size
    char ch;
    unsigned long po;
    
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if (st.isfull())
                        cout << "stack already full\n";
                      else
                        st.push(po);
                      break;
            case 'P':
            case 'p': if (st.isempty())
                         cout << "stack already empty\n";
                      else
                      {
                        st.pop(po);
                        cout << "PO #" << po << " popped\n";
                      }
                      break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n ";
    }

    Stack test1(st);
    Stack test2;
    test2 = test1;
    Item data;
    cout << "Is test1:\n";
    for (int i = 0; test1.pop(data); i++)
        cout << data << ' ';

    cout << "\nIs test2:\n";
    for (int i = 0; test2.pop(data); i++)
        cout << data << ' ';

    cout << "\nBye\n";
    return 0;
}