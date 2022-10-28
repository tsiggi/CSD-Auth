#ifndef sav_h
#define sav_h
#include "Account.h"
class Savings:public Account
{
  private:
    int times=0;
  public:
    Savings(char*,float);
    bool withdraw(float);
};
#endif
