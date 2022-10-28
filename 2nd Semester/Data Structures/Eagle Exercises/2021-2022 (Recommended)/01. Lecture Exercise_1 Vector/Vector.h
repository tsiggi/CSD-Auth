#ifndef VECTOR_H
#define VECTOR_H


class Vector {
private:
    double x,y;
public:
    Vector();
    Vector(double ,double);
    double GetX();
    double GetY();
    void SetX(double);
    void SetY(double);
    double magnitude();
    double angle();
    double angleD();
    void multiply(double);
    Vector add(Vector);
    Vector clone();
};


#endif VECTOR_H
