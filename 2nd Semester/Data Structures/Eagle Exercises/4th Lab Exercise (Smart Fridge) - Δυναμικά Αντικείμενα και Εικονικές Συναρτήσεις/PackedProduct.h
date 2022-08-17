#ifndef pa_h
#define pa_h

#include "Date.h"
#include "Product.h"
class PackedProduct : public Product
{
private:
  bool open;
  Date opened;
  int days;
public:
  void Setdays(int a){days=a;};
  PackedProduct(char[],Date,int,bool,int,Date);  
  void ela(char[],Date,int,bool,int,Date);
  Date getExpiry();
  Date Getopened(){return opened;};

  Date synarthsh();
};
#endif

