#include "Product.h"
#include "Date.h"

#include <iostream>


Product::Product(char NAME[],Date expir,int a)
{
  for(int i=0;NAME[i]!='\0'&&i<21;i++)
    name[i]=NAME[i];
  exp.Setday(expir.Getday());
  exp.Setmonth(expir.Getmonth());
  exp.Setyear(expir.Getyear());      
  
  SetGrams(a);
};


Date Product::getExpiry()
{
  return synarthsh();
}

char* Product::Getname()
{
  return name;
}