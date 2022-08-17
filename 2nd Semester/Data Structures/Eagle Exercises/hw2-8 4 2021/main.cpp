#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    int d,m,y;
    char *Days[] ={(char *) "Sunday",(char *)"Monday",(char *)"Tuesday",(char *)"Wednesday",(char *)"Thursday", (char *)"Friday",(char *)"Saturday"};

    cin>>d>>m>>y;
    while (d!=0 || m!=0 || y!=0)
    {
        Date a;
        if (a.setDate(d,m,y))
        {
            int dw;
            a.dayOfWeek(dw);
            cout<<Days[dw]<<" "<<a.getDay()<<"/"<<a.getMonth()<<"/"<<a.getYear()<<". ";
            if (a.leapYear())
                cout<<a.getYear()<<" is a leap year."<<endl;
            else
                cout<<a.getYear()<<" is a regular year."<<endl;
        }
        else
            cout<<"Wrong date"<<endl;
        cin>>d>>m>>y;
    }
    return 0;
}