#include "Cylinder.h"
#include <cmath>
Cylinder::Cylinder():Sphere()
{
    l=0;
}
Cylinder::Cylinder(float x2,float y2,float z2,float r2,float l2):Sphere(x2,y2,z2,r2)
{
    l=l2;
}
void Cylinder::Setx(float x2)
{
    Sphere::Setx(x2);
}
void Cylinder::Sety(float y2)
{
    Sphere::Sety(y2);
}
void Cylinder::Setz(float z2)
{
    Sphere::Setz(z2);
}
void Cylinder::SetR(float r2)
{
    Sphere::Setr(r2);
}
void Cylinder::SetL(float l)
{
    this->l=l;
}
float Cylinder::Area()
{
    return 2*M_PI*Sphere::Getr()*(Sphere::Getr()+l);
}
float Cylinder::Volume()
{
    return l*M_PI*Sphere::Getr()*Sphere::Getr();
}
bool Cylinder::inCylinder(float x1,float y2,float z2)
{
    float k=sqrt(pow(Sphere::Getx()-x1,2)+pow(Sphere::Gety()-y2,2));
    if((k<=Sphere::Getr())&&(Sphere::Getz()-l/2<=z2)&&(z2<=Sphere::Getz()+l/2))
        return true;
    return false;

}
