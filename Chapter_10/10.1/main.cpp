#include "bank.h"
#include <iostream>

int main()
{
    BankAccount kek("John Doe", "123456789", 500.0);

    kek.show();
    kek.deposit(100);
    kek.show();
    kek.withdraw(30);
    kek.show();

    return 0;
}