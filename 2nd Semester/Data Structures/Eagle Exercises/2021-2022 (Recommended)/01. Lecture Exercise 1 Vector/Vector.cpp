//
// Created by chris on 28-Oct-22.
//

#include <math.h>
#include "Vector.h"

// First Constructor initialize Vector to O(0,0)
Vector::Vector() {
    this->x = 0;
    this->y = 0;
}
// Second Constructor initialize Vector to P(x,y)
Vector::Vector(double x,double y) {
    this->x = x;
    this->y = y;
}
// Returns the x
double Vector::GetX(){
    return this->x;
}
// Returns the y
double Vector::GetY(){
    return this->y;
}
// Sets the x
void Vector::SetX(double x2){
    this->x = x2;
}
// Sets the y
void Vector::SetY(double y2){
    this->y = y2;
}

double Vector::magnitude(){
    return sqrt(this->x*this->x + this->y*this->y);
}

double Vector::angle(){
    // this is in rad
    return atan(y/x);
}

double Vector::angleD(){
    // 2 * acos(0.0) = pi
    // convert rad in degrees
    // degrees = radians × 180° / π
    return (angle()*180)/(2 * acos(0.0));
}

void Vector::multiply(double f){
    this->x = this->x * f;
    this->y = this->y * f;
}

Vector Vector::add(Vector v){
    Vector temp(this->x+ v.GetX(), this->y + v.GetY());
    return temp;
}

Vector Vector::clone() {
    Vector temp(this->x, this->y);
    return temp;
}