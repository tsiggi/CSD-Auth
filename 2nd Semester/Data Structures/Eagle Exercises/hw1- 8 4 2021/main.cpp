#include <iostream>
#include <iomanip>
#include "Vector.h"
using namespace std;

int main()
{
    Vector a,e(10,5),b;
    double x,y,f;

    cin>>x>>y>>f;
    cout<<fixed<<setprecision(1)<<endl; //The numbers will be printed with 1 decimal digit
    a.Setx(x);
    a.Sety(y);
    a.print();
    cout<<endl;
    e.print();
    cout<<endl;
    a.multiply(f);
    a.print();
    cout<<endl;
    b = a.add(e);
    b.print();
    return 0;
}