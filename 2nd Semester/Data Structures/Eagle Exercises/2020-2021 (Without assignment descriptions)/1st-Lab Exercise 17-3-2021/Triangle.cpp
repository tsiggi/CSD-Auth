#include <iostream>
#include <cmath>
#include "Triangle.h"
#ifndef M_PI
#define M_PI 3.14159265
#endif
//using namespace std;

Triangle::Triangle()
{
  xa=0;
  ya=0;
  xb=0;
  yb=0;
  xc=0;
  yc=0;
}
Triangle::Triangle(float a,float b,float c,float d ,float e,float f)
{
  xa=a;
  ya=b;
  xb=c;
  yb=d;
  xc=e;
  yc=f;
}
void Triangle::SetXA(float a)
{
  xa=a;
}
void Triangle::SetYA(float a){
  ya=a;
}
void Triangle::SetXB(float a)
{
  xb=a;
}
void Triangle::SetYB(float a){
  yb=a;
}
void Triangle::SetXC(float a)
{
  xc=a;
}
void Triangle::SetYC(float a){
  yc=a;
}
float Triangle::getAB()
{
  return (sqrt(((xa-xb)*(xa-xb))+((ya-yb)*(ya-yb))));
}
float Triangle::getAC(){
  return (sqrt(((xa-xc)*(xa-xc))+((ya-yc)*(ya-yc))));
}
float Triangle::getBC(){
  return (sqrt(((xb-xc)*(xb-xc))+((yb-yc)*(yb-yc))));
}
float Triangle::getA(){
  float a=getBC(),b=getAC(),c=getAB();
  return acos((b*b+c*c-a*a)/(2*b*c));
}
float Triangle::getB(){
  float a=getBC(),b=getAC(),c=getAB();
  return acos((c*c+a*a-b*b)/(2*a*c));
}
float Triangle::getC(){
  float a=getBC(),b=getAC(),c=getAB();
  return acos((+a*a+b*b-c*c)/(2*a*b));
}
bool Triangle::isIsopleurous(){
  float a=getBC(),b=getAC(),c=getAB();
  if(fabs(a-b)<pow(10,-3)&&fabs(c-b)<pow(10,-3)&&fabs(a-c)<pow(10,-3))  return 1;
  return 0;
}
bool Triangle::isIsosceles(){
  float a=getBC(),b=getAC(),c=getAB();
  if(fabs(a-b)<pow(10,-3)||fabs(c-b)<pow(10,-3)||fabs(a-c)<pow(10,-3))  return 1;
  return 0;
}
bool Triangle::isScalino(){
  float a=getBC(),b=getAC(),c=getAB();
  if(fabs(a-b)>pow(10,-3)&&fabs(c-b)>pow(10,-3)&&fabs(a-c)>pow(10,-3))  return 1;
  return 0;
}
bool Triangle::isOrthogonio(){
  float a=getA(),b=getB(),c=getC();
  if((fabs(a-(M_PI/2))<pow(10,-3))||(fabs(b-(M_PI/2))<pow(10,-3))||(fabs(c-(M_PI/2))<pow(10,-3)))
    return 1;
  return 0;
}
bool Triangle::isOxygonio(){
  float a=getA(),b=getB(),c=getC();
  if((a-(M_PI/2)<pow(10,-3))&&(b-(M_PI/2)<pow(10,-3))&&(c-(M_PI/2))<pow(10,-3))
    return 1;
  return 0;
}
bool Triangle::isAmvligonio(){
  float a=getA(),b=getB(),c=getC();
  if((a-(M_PI/2)>pow(10,-3))||(b-(M_PI/2)>pow(10,-3))||(c-(M_PI/2))>pow(10,-3))
    return 1;
  return 0;
}
float Triangle::getBase(){
  return getAB();
}
float Triangle::getHeight(){
  float a= getA(),ac=getAC();
  return sin(a)*ac;
}
float Triangle::getArea(){
  float b=getBase(),y=getHeight();
  return (b*y)/2;
}