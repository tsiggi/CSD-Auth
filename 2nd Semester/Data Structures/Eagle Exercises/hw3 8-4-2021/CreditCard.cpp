#include "CreditCard.h"

CreditCard::CreditCard(char *name,float a,float limit):Account(name,a)
{
  this->limit=limit;
}
bool CreditCard::withdraw(float amount)
{
  if(balance+limit>=amount)
  {
    //limit-=amount;
    balance-=amount;
    return true;
  }
  return false;
}


