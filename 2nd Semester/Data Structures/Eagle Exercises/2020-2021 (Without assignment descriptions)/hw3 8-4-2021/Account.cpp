#include "Account.h"
#include <cstring>
using namespace std;

Account::Account(char *d)
{
    description = new char[strlen(d)+1];
    strcpy (description,d);
    balance=0;
}
Account::Account(char *d, float b)
{
    description = new char[strlen(d)+1];
    strcpy (description,d);
    balance=b;
}
bool Account::withdraw(float amount)
{
    if (balance>=amount)
    {
        balance-=amount;
        return true;
    }
    return false;
}
bool Account::deposit(float amount)
{
    if (amount>0)
    {
        balance+=amount;
        return true;
    }
    return false;
}
float Account::getBalance()
{
    return balance;
}
char *Account::getDescription()
{
    return description;
}