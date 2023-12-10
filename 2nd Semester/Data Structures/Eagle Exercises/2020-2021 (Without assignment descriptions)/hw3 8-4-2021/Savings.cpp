#include "Savings.h"

Savings::Savings(char *name,float d):Account(name,d)
{}

bool Savings::withdraw(float amount)
{
  if(times<3&&balance>=amount)
  {
    times++;
    balance-=amount;
    return true;
  }
  return false;
}

