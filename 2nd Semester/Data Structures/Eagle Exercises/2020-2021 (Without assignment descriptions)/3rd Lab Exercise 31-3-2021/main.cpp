#include <iostream>
#include <iomanip>
#include <cmath>

#include "Circle.h"
#include "Sphere.h"
#include "Cylinder.h"

using namespace std;

double roundTo(double val, int digits)
{
    double k = pow(10,digits);
    return round(val*k)/k;
}

int main()
{
    float x1,y1,r,x2,y2; //Circle data
    cin>>x1>>y1>>r>>x2>>y2;
    float xs1,ys1,zs1,rs,xs2,ys2,zs2; //Sphere data
    cin>>xs1>>ys1>>zs1>>rs>>xs2>>ys2>>zs2;
    float xc1,yc1,zc1,rc,lc,xc2,yc2,zc2; //Cylinder data
    cin>>xc1>>yc1>>zc1>>rc>>lc>>xc2>>yc2>>zc2;


    Circle a(x1,y1,r);

    cout<<"Circle Area="<<roundTo(a.Area(),1)<<" Perimeter="<<roundTo(a.Perimeter(),1)<<" Diameter="<<roundTo(a.Diameter(),1)<<endl;

    if (a.inCircle(x2,y2))
        cout<<"Point ("<<x2<<", "<<y2<<") in circle."<<endl;
    else
        cout<<"Point ("<<x2<<", "<<y2<<") not in circle."<<endl;



    Sphere s(xs1,ys1,zs1,rs);
    cout<<"Sphere Area="<<roundTo(s.Area(),1)<<" Volume="<<roundTo(s.Volume(),1)<<endl;

    if (s.inSphere(xs2,ys2,zs2))
        cout<<"Point ("<<xs2<<", "<<ys2<<", "<<zs2<<") in sphere."<<endl;
    else
        cout<<"Point ("<<xs2<<", "<<ys2<<", "<<zs2<<") not in sphere."<<endl;



    Cylinder c;

    c.Setx(xc1);
    c.Sety(yc1);
    c.Setz(zc1);
    c.SetR(rc);
    c.SetL(lc);

    cout<<"Cylinder Area="<<roundTo(c.Area(),1)<<" Volume="<<roundTo(c.Volume(),1)<<endl;

    if (c.inCylinder(xc2,yc2,zc2))
        cout<<"Point ("<<xc2<<", "<<yc2<<", "<<zc2<<") in cylinder."<<endl;
    else
        cout<<"Point ("<<xc2<<", "<<yc2<<", "<<zc2<<") not in cylinder."<<endl;




    return 0;
}
