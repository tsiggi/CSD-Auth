#ifndef Sphere_h
#define Sphere_h
#include "Circle.h"
class Sphere:Circle
{
    private :
        float z;
    public:
        Sphere();
        Sphere(float,float,float,float);
        void Setx(float);
        void Sety(float);
        void Setz(float);
        void Setr(float);
        float Getx();
        float Gety();
        float Getz();
        float Getr();
        float Area();
        float Volume();
        bool inSphere(float ,float ,float );
};
#endif // Sphere_h
