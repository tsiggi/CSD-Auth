#ifndef Date_H
#define Date_H
class Date
{
protected:
    int day;
    int month;
    int year=2021;
public:
    Date(){day=0;month=0;year=0;};
    Date(int day,int month,int year){
        this->day=day;this->month=month;this->year=year;};
    void Setday(int day){this->day=day;};
    void Setmonth(int month){this->month=month;};
    void Setyear(int year){this->year=year;};
    int Getday(){return day;};
    int Getmonth(){return month;};
    int Getyear(){return year;};
    int dayInMonth(int);
    void add(int );
    int diff(Date);

};
#endif // DATE_H
