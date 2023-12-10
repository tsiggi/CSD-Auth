#include "Date.h"
#include <iostream>
int Date::dayInMonth(int m)
{
  if(m%2)
  { 
    if(m<8)
    {
      return 31;
    }
    else
    { 
      return 30;
    }
  }
  else
  {
    if(m==2)
    {
      return 28;
    }
    else 
    { 
      if(m<8)
      {
        return 30;}
      else
      {
        return 31;
      }
    }
  }
}
void Date::add(int k)
{
  int d2=day,m=dayInMonth(month);

  day+=k;
  if (day>m)
  {
    for(;day>m;)
    {
      month++;
      day-=m;
      m=dayInMonth(month);
    }
    if(month>12)
    {
      year+= month/12;
      month%=12;
    }
  }
}
int Date::diff(Date b)
{
  int diafora=0,by=b.Getyear(),bm=b.Getmonth(),bd=b.Getday();
  //std::cout<<"!!!!!!"<<bd<<"!!!!!!!"<<bm<<"!!!!!!!!!"<<by<<"!!!!!!!!!\n";
  
  if(by<year||((by==year)&&(bm<month))||((by==year)&&(bm==month)&&(bd<day)))
    return -1;
 
  for(;(by>year+1||((by==year+1)&&(bm>month))||((by==year+1)&&(bm==month)&&(bd>day)));by--)
    diafora+=365;
  
  int bm2=month, bd2=day;
  for(;(bm2<bm)||((bm2==bm)&&(bm2<bm));bm2++)
  {
    diafora+=dayInMonth(bm2);
  }






  //for(;(bm>month+1)||((bm==month+1)&&(bd>day));bm--)
  //  diafora+=dayInMonth(bm);
  for(;(bd>day);bd--)
   diafora++;
   //std::cout<<"!!!!!!!!!!!!!!!!"<<diafora<<"!!!!!!!!!!!";
  return diafora; 
}