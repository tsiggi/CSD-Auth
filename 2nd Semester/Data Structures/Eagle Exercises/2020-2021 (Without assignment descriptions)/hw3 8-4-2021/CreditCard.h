#ifndef cc_h
#define cc_h
#include "Account.h"
class CreditCard:public Account
{
  private: 
    float limit;
  public:  
    CreditCard(char*,float,float);
    bool withdraw(float);
    //using  getBalance();
    //using *getDescription();

};
#endif
