#include "bank.h"
#include <iostream>
BankAccount::BankAccount(const std::string & n, const std::string & num, double bal)
{
    name = n;
    acctnum = num;
    balance = bal;
}
void BankAccount::show() const
{
    std::cout << "Name: " << name << '\n';
    std::cout << "Account Number: " << acctnum << '\n';
    std::cout << "Balance: $" << balance << '\n';
}
void BankAccount::deposit(double cash)
{
    if (cash > 0)
        balance += cash;
    else
        std::cout << "Deposit amount must be positive.\n";
}
void BankAccount::withdraw(double cash)
{
    if (cash > balance)
        std::cout << "Insufficient funds for withdrawal.\n";
    else if (cash <= 0)
        std::cout << "Withdrawal amount must be positive.\n";
    else
        balance -= cash;
}