#include <cmath>
#include <iostream>
class Vector
{
private:
  float x;
  float y;
public:
  Vector(){x=0;y=0;};
  Vector(float a,float b){x=a;y=b;};
  void Setx(float a){x=a;};
  void Sety(float b){y=b;};
  float Getx(){return x;};
  float Gety(){return y;};
  float magnitude(){return sqrt(x*x+y*y);};
  float angle(){return atan(y*(1.0)/x);};
  float angleD(){return (angle()*180)/(4*atan(1));};
  void print(){std::cout<<"("<<x<<","<<y<<")\n"<<magnitude()<<std::endl<<angleD()<<std::endl;};
  void multiply(double f){x*=f;y*=f;};
  Vector add(Vector v){Vector t(x+v.x,y+v.y);
  return t;};
};