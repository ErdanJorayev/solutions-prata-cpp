#include <iostream>
#include <cstring>
#include "worker.h"
#include "queue.h"

const int SIZE = 5;

int main()
{
    using std::cin, std::cout, std::endl, std::strchr;

    QueueTP<Worker *> lolas(SIZE); 
    int ct;

    for (ct = 0; ct < SIZE; ct++)
    {
        Worker * base = nullptr;
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter s: singer "
             << "t: singing waiter q: quit\n";
        
        cin >> choice;
        cin.get();
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
       
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'w': base = new Waiter;
            break;
            case 's': base = new Singer;
            break;
            case 't': base = new SingingWaiter;
            break;
        }
        base->Set();
        lolas.enqueue(base);
    }
    cout << "\nHere is your staff:\n";
    int i;
    Worker * kek;
    for (i = 0; i < ct; i++)
    {
        lolas.dequeue(kek);
        kek->Show(); 
        cout << " is kick\n";
        delete kek;
    }

    cout << "Bye.\n";
    return 0;
}