#ifndef Cylinder_h
#define Cylinder_h
#include "Sphere.h"
class Cylinder:Sphere
{
    private:
        float l;
    public :
        Cylinder();
        Cylinder(float ,float ,float ,float ,float);
        void Setx(float);
        void Sety(float);
        void Setz(float);
        void SetR(float);
        void SetL(float);
        float Area();
        float Volume();
        bool inCylinder(float,float,float);
};
#endif
