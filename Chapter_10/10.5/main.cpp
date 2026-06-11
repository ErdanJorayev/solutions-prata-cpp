#include "stack.h"
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    Stack st;
    Item cust;
    char ch;
    double total = 0;

    cout << "Please enter A to add a customer,\n"
         << "P to delete customer, or Q to quit.\n";
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
            case 'a': cout << "Enter a name of customer:\n";
                      cin.getline(cust.fullname, 35);
                      cout << "Enter a payment of customer:\n";
                      (cin >> cust.payment).get();

                      if (st.isfull())
                        cout << "stack already full\n";
                      else
                        st.push(cust);
                      break;
            case 'P':
            case 'p': if (st.isempty())
                         cout << "stack already empty\n";
                      else
                      {
                        st.pop(cust);
                        cout << "Customer " << cust.fullname << " deleted\n";
                        total += cust.payment;
                      }
                      break;
        }
        cout << "Please enter A to add a customer,\n"
         << "P to delete customer, or Q to quit.\n";
    }
    cout << "Total payment " << total << "$, " << "wow!\n";
    cout << "\nBye!\n";

    return 0;
}