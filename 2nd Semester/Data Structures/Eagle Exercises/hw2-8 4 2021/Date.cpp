#include "Date.h"
#include <iostream>

int LeapYear(int y)
{
  if((y%4==0&&y%100!=0)||(y%100==0&&y%400==0))
    return 1;
  return 0;
}
int dayInMonth(int m,int y)
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
      return 28+LeapYear(y);
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
bool Date::setDate(int day,int month,int year)
{
  if((year<1900||day<1||day>31||month<1||month>12)||(dayInMonth(month,year)<day))
  {
    return 0;
  }
  this->day=day;
  this->month=month;
  this->year=year;
  return 1;
}
void Date::dayOfWeek(int&a)
{
  int diafora=0,by=1900,bm=1,bd=1;
 
  for(;(by+1<year)||((by==year-1)&&(bm<month))||((by==year-1)&&(bm==month)&&(bd<=day));by++)
  {  
    diafora+=(365+LeapYear(by));
    
  }
  for(;(bm+1<month)||((bm==month-1)&&(bd<=day));bm++)
  {
    diafora+=dayInMonth(bm,by);
  }
  for(;(bd<day);bd++)
   diafora++;

  a=diafora%7+1;
  if(a==7)
    a=0;
}
bool Date::leapYear()
{    
  if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
    return 1;
  return 0;
}
