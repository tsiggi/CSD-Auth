#ifndef date_h
#define date_h
class Date
{
private:
  int day;
  int month;
  int year;
public :
  bool setDate(int ,int,int);
  void dayOfWeek(int&);
  int getYear(){return year;};
  int getMonth(){return month;};
  int getDay(){return day;};
  bool leapYear();

};
#endif




