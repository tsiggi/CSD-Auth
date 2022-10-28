#include <cmath>
#include "Circle.h"
//#define PI 3,14159265
Circle::Circle()
{
    x=0;
    y=0;
    r=0;
}
Circle::Circle(float a,float b,float c)
{
    x=a;
    y=b;
    r=c;
}
void Circle::Setx(float k)
{
    x=k;
}
void Circle::Sety(float k)
{
    y=k;
}
void Circle::Setr(float k)
{
    r=k;
}
float Circle::Diameter()
{
    return 2*r;
}
bool Circle::inCircle(float a,float b)
{
    float k;
    k=sqrt(pow(x-a,2)+pow(y-b,2));
    if(k<=r)
        return true;
    return false;
}
float Circle::Area()
{
    return M_PI*r*r;
}
float Circle::Perimeter()
{
    return 2*M_PI*r;
}
float Circle::Getx()
{
    return x;
}
float Circle::Gety()
{
    return y;
}
float Circle::Getr()
{
    return r;
}
