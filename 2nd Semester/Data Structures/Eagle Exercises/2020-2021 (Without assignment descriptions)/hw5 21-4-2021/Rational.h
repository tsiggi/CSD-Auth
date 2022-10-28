#ifndef rational_h
#define rational_h
#include <iostream> 
using namespace std;
class Rational
{
private:
    int x;
    int y;
    
public:
    Rational(int a,int b);//
    Rational(){x=1;y=1;};
    void SetX(int a){x=a;};
    void SetY(int a){y=a;};
    int GetX(){return x;};
    int GetY(){return y;};
    //void A(int&,int&);
    Rational operator=(const Rational &);
    bool operator == (Rational &);
    bool operator!=(Rational &);
    Rational &operator*=(int);
    Rational &operator/=(Rational &);
};
istream &operator>>(istream &, Rational & );
ostream &operator << (ostream &,  Rational &);
bool operator>(Rational &,Rational &);
bool operator<(Rational &,Rational &);
Rational operator+(Rational &,Rational&);  
Rational operator-(Rational&,Rational&);
Rational operator*(Rational&,Rational&);
Rational operator/(Rational&,Rational&);
#endif