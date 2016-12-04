//
//  Circle.cpp
//  cppransac
//
//  Created by ललित सिंह on 09/11/2016.
//  Copyright © 2016 ललित सिंह. All rights reserved.
//

#include "Circle.hpp"

Circle::Circle(){
    this-> radius = 0;
    this-> center =  mypoint2f();
    this-> isSingular = true;
}
Circle::Circle(double radius,  mypoint2f center){
    this-> radius = radius;
    this->center = center;
    this-> isSingular = false;
}
Circle::Circle(mypoint2f a, mypoint2f b, mypoint2f c){
    LinearEqu equ1 = LinearEqu(a,b);
    LinearEqu equ2 = LinearEqu(b,c);
    internsectionPoint intesecPoint = solveLinearEquation(equ1, equ2);

    double radius = distance(a, intesecPoint.point);
    this-> center = intesecPoint.point;
    this->radius = radius;
    this->isSingular = intesecPoint.doesIntersect;
}
bool Circle::getSingular(){
    return this->isSingular;
}
mypoint2f Circle::getCenter(){
    return this->center;
}
double Circle::getRadius(){
    return this->radius;
}
std::ostream& operator <<(std::ostream& out, Circle& c){
    out<<"radius:"<<c.radius<<" ";
    out<<c.center;
    return out;
}
