#ifndef prod_h
#define prod_h
#include <string>
#include "Date.h"
class Product
{
  private:
    char name[20];
    int grams;
    Date exp;
  
  
  public:
    void SetGrams(int grams){this->grams=grams;};
    
    Date Getexp(){return exp;};

    Product(char[] ,Date ,int );
    
    Date getExpiry();
    char* Getname();
  
    
    virtual Date synarthsh(){return exp;};


};
#endif
