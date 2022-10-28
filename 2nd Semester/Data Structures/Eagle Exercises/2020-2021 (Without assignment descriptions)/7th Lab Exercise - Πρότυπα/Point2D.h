#ifndef POINT2D_H_INCLUDED
#define POINT2D_H_INCLUDED

#include <cmath>
#include <iostream>

class Point2D
{
private:
    int x;
    int y;
public:
    Point2D(){x=y=0;};
    Point2D(int a, int b){x=a;y=b;};
    float GetDistance(){return sqrt(x*x+y*y);};
    int GetX(){return x;};
    int GetY(){return y;};
    void SetX(int a){x=a;};
    void SetY(int a){y=a;};
    void operator=(int b)
    {
        x=b;
        y=b;

    }
};
ostream &operator <<(ostream &o,Point2D &a)
{
    o<<"("<<a.GetX()<<","<<a.GetY()<<")";
    return o;
}

bool operator<(Point2D a,Point2D b)
{
    return a.GetDistance()<b.GetDistance();
}
#endif // POINT2D_H_INCLUDED
