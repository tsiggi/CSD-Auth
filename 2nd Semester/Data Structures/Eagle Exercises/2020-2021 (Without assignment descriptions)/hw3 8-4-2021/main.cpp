#include <iostream>
#include "CreditCard.h"
#include "Savings.h"
using namespace std;

void act(Account *a, const float amount, char action)
{
  if (action=='d')
  {
    if (!a->deposit(amount))
      cout<<"Wrong amount"<<endl;
  }
  else
    if (action=='w')
    {
      if (!a->withdraw(amount))
        cout<<"Withdraw of "<<amount<<" denied for "<<a->getDescription()<<endl;
    }
}

int main()
{
  Account *myAccounts[3];
  myAccounts[0] = new Account ((char *)"simple",100);
  myAccounts[1] = new CreditCard ((char *)"visa",100,200);
  myAccounts[2] = new Savings ((char *)"My savings",100);

  char action;
  float amount;

  cin>>action;
  while (action!='q')
  {
    cin>>amount;
    for (int i=0;i<3;i++)
      act(myAccounts[i],amount,action);
    cin>>action;
  }
  for (int i=0;i<3;i++)
    cout<<myAccounts[i]->getBalance()<<endl;
  return 0;
}