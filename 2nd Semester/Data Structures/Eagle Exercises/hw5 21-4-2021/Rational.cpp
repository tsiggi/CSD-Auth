
#include "Rational.h"
#include <iostream>
#include <cmath>
using namespace std;
#define error 0.000001

void ABC(int &a,int &b)
{
    int ta=a,tb=b,g=a*b,u=1,mkd=1;
    u=a;
    if(b<a)
        u=b;
    while(u!=0)
    {
        mkd=u;
        u=ta % tb;
        ta= tb;
        tb= u;
    }
    a=a/mkd;
    b=b/mkd;
    if(a<0&&b<0)
    {
        a*=(-1);
        b=b*(-1);
    }
    else if(b<0)
        {
            a*=(-1);
            b=b*(-1);
        }



}
Rational::Rational(int a,int b)
{
    ABC(a,b);
    x=a;
    y=b;
}

istream &operator>>(istream &c, Rational &a)
{
    int b,d;
    c>>b;
    c>>d;
    ABC(b,d);
    a.SetX(b);
    a.SetY(d);
    return c;
} 

ostream &operator<<(ostream &c, Rational &a)
{
    c<<a.GetX()<<"/"<<a.GetY();
    return c;
}

Rational Rational::operator=(const Rational &other)
{
    if(this==&other)
        return *this;
    this->x=other.x;
    this->y=other.y;
    ABC(this->x,this->y);
    return *this;
}
bool Rational::operator==( Rational &a)
{
   double c,d;
    c=a.GetX()*(1.0)/a.GetY();
    d=this->x*(1.0)/this->y;
    
    if(abs(d-c)<error)
        return true;
    return false;
}
bool Rational::operator!=( Rational &a)
{
    double c,d;
    c=a.GetX()*(1.0)/a.GetY();
    d=this->x*(1.0)/this->y;
    
    if(abs(d-c)<error)
        return false;
    return true;
}
bool operator>(Rational &a,Rational &b)
{
    double c,d;
    c=(a.GetX()*(1.0))/a.GetY();
    d=(b.GetX()*(1.0))/b.GetY();
    
    if(abs(d-c)>error && c>d)
        return true;
    return false;
}
bool operator<(Rational &a,Rational &b)
{
    double c,d;
    c=a.GetX()*(1.0)/a.GetY();
    d=(b.GetX()*(1.0))/b.GetY();
    if(abs(d-c)>error && c<d)
        return true;
    return false;
}
Rational operator+( Rational &a,Rational &b)
{
    int c=a.GetX()*b.GetY()+a.GetY()*b.GetX(),d=a.GetY()*b.GetY();
    ABC(c,d);
    Rational e(c,d);

    
    return e;
}
Rational operator-( Rational &a,Rational &b)
{
    int f=a.GetX()*b.GetY()-a.GetY()*b.GetX(),g=a.GetY()*b.GetY();
    ABC(f,g);
    Rational c (f,g);
    return c;
}
Rational operator*( Rational &a,Rational &b)
{
    int f=a.GetX()*b.GetX(),g=a.GetY()*b.GetY();
    ABC(f,g);
    Rational c (f,g);
    return c;
}
Rational operator / (Rational &a,Rational &b)
{
    int f=a.GetX()*b.GetY(),g=a.GetY()*b.GetX();
    ABC(f,g);
    Rational c (f,g);
    return c;
}
Rational & Rational::operator*=(int a)
{
    this->x*=a;
    ABC(this->x,this->y);
    return *this;
}
Rational &Rational:: operator /=(Rational &a)
{
    this->x=this->x*a.GetY();
    this->y=this->y*a.GetX();
    ABC(this->x,this->y);
    return *this;
}


