#include "Sphere.h"
#include <cmath>
Sphere::Sphere():Circle()
{
    z=0;
}
Sphere::Sphere(float x2,float y2,float z2,float r2):Circle(x2,y2,r2)
{
    z=z2;
}
void Sphere::Setx(float a)
{
    Circle::Setx(a);
}
void Sphere::Sety(float a)
{
    Circle::Sety(a);
}
void Sphere::Setz(float a)
{
    z=a;
}
void Sphere::Setr(float a)
{
    Circle::Setr(a);
}
float Sphere::Getx()
{
    return Circle::Getx();
}
float Sphere::Gety()
{
    return Circle::Gety();
}
float Sphere::Getz()
{
    return z;
}
float Sphere::Getr()
{
    return Circle::Getr();
}
float Sphere::Area()
{
    return 4*Circle::Area();
}
float Sphere::Volume()
{
    return (M_PI*Getr()*Getr()*Getr()*4)/3;
}
       float Volume();
bool Sphere::inSphere(float x1,float y1 ,float z1)
{
    float k;
    k=sqrt(pow(Circle::Getx()-x1,2)+pow(Circle::Gety()-y1,2)+pow(z-z1,2));
    if(k<=Circle::Getr())
        return true;
    return false;
}
