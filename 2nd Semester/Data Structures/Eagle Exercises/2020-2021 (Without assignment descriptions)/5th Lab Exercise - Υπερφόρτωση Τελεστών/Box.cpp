#include "Box.h"
#include <iostream>
using namespace std;

float Box::GetX() const
{
    return x;
}
float Box::GetY() const 
{
    return y;
}
float Box::GetZ() const 
{
    return z;
}

Box operator *(Box b ,int a)
{   
    b.SetX(b.GetX()*a);
    b.SetY(b.GetY()*a);
    b.SetZ(b.GetZ()*a);
    return b;
}
Box operator/(Box b ,float a)
{   
    b.SetX(b.GetX()/a);
    b.SetY(b.GetY()/a);
    b.SetZ(b.GetZ()/a);
    return b;
}
Box operator+(Box b ,float a)
{   
    b.SetX(b.GetX()+a);
    b.SetY(b.GetY()+a);
    b.SetZ(b.GetZ()+a);
    return b;
}
Box operator-(Box b ,float a)
{   
    b.SetX(b.GetX()-a);
    b.SetY(b.GetY()-a);
    b.SetZ(b.GetZ()-a);
    return b;
}
Box Box::operator=(const Box &other)
{
    if(this==&other)
        return *this;
    this->x=other.x;
    this->y=other.y;
    this->z=other.z;
    return *this;
}

bool Box::operator==(Box &a)
{
    return this->x==a.GetX()&&this->y==a.GetY()&&this->z==a.GetZ();
}
bool Box::operator!=(Box &a)
{
    return !(*this==a);
}
Box operator+(Box a,Box b)
{
    a.SetX(a.GetX()+b.GetX());
    a.SetY(a.GetY()+b.GetY());
    a.SetZ(a.GetZ()+b.GetZ());
    return a;
}
Box operator-(Box a,Box b) 
{
    a.SetX(a.GetX()-b.GetX());
    a.SetY(a.GetY()-b.GetY());
    a.SetZ(a.GetZ()-b.GetZ());
    return a;
}
Box operator++( Box &a)//προθεματικά
{
    a.SetX(a.GetX()+1);
    a.SetY(a.GetY()+1);
    a.SetZ(a.GetZ()+1);
    return a;
}
Box operator++(Box &a,int k) //επιθεματικά διαφορετική δήλωση με διαφορετικά ορίσματα
{
    Box temp;
    temp=a;
    a.SetX(a.GetX()+1);
    a.SetY(a.GetY()+1);
    a.SetZ(a.GetZ()+1);
    return temp;
}
Box operator--(Box &a)//προθεματικά
{
    a.SetX(a.GetX()-1);
    a.SetY(a.GetY()-1);
    a.SetZ(a.GetZ()-1);
    return a;
}
Box operator--(Box &a,int k) //επιθεματικά διαφορετική δήλωση με διαφορετικά ορίσματα
{
    Box temp;
    temp=a;
    a.SetX(a.GetX()-1);
    a.SetY(a.GetY()-1);
    a.SetZ(a.GetZ()-1);
    return temp;
}

void Box::operator +=(int a)
{
    this->x+=a;
    this->y+=a;
    this->z+=a;
}
void Box::operator -=(float a)
{
    this->x-=a;
    this->y-=a;
    this->z-=a;
}
void Box::operator *=(float a)
{
    this->x*=a;
    this->y*=a;
    this->z*=a;
}
void Box::operator /=(float a)
{
    this->x/=a;
    this->y/=a;
    this->z/=a;
}
ostream &operator<<(ostream &c,const Box &other)
{
    cout<<"length: "<<other.GetX()<<", width: "<<other.GetY()<<", height: "<<other.GetZ();
    return cout;
}