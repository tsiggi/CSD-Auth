#ifndef Box_h
#define Box_h
#include <iostream>
using namespace std;

class Box 
{
private:
    float x;
    float y;
    float z;
public:
    Box(){x=0;y=0;z=0;};
    Box(float a,float b,float c){x=a;y=b;z=c;};
    float GetX()const;
    float GetY()const;
    float GetZ()const;
    void SetX(float a){x=a;};
    void SetY(float b){y=b;};
    void SetZ(float c){z=c;};
    Box operator=(const Box &);
    bool operator==(Box &);
    bool operator!=(Box &);
    void operator +=(int);
    void operator -=(float);
    void operator *=(float);
    void operator /=(float);
    
};
Box operator++(Box&);
Box operator++(Box&,int);
Box operator--(Box&);
Box operator--(Box&,int);

Box operator*(Box ,int);
Box operator/(Box ,float);
Box operator+(Box ,float);
Box operator-(Box ,float);
ostream &operator <<(ostream &,const Box &);
Box operator+(Box ,Box );
Box operator-(Box ,Box );


#endif