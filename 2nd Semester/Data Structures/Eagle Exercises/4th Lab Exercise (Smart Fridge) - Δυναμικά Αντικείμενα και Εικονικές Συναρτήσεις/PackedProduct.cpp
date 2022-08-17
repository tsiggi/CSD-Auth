#include "PackedProduct.h"
#include "Date.h"
#include <iostream>


PackedProduct::PackedProduct(char name[20],Date exp,int grams,bool open,int lifetime, Date d):Product(name,exp,grams)
{
  this->open=open;
  opened.Setday(d.Getday());
  opened.Setmonth(d.Getmonth());
  opened.Setyear(d.Getyear());
  Setdays(lifetime);
}
Date PackedProduct::synarthsh()
{
  Date c1=Getexp();
  if(open)
  {
    
    //int a=Getexp().Getday(),b=Getexp().Getmonth(),c=Getexp().Getyear();
    opened.add(days);
    //int a2=Getopened().Getday(),b2=Getopened().Getmonth(),c2=Getopened().Getyear();
    
    
     if(Getexp().diff(Getopened())>=0)return Getexp();
     
     return opened; 
  }
  return Getexp();
}
