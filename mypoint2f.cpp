//
//  mypoint2f.cpp
//  hw3class
//
//  Created by ललित सिंह on 28/10/2016.
//  Copyright © 2016 ललित सिंह. All rights reserved.
//
//#include "header.hpp"
#include "mypoint2f.hpp"
mypoint2f::mypoint2f(){
    this->x = 0;
    this->y = 0 ;
    
}
mypoint2f::mypoint2f(double x, double y ){
    this->x = x;
    this->y = y;
}
double mypoint2f::getx(){
    return this->x;
}
double mypoint2f::gety(){
    return this->y;
}


mypoint2f operator-(mypoint2f& a, mypoint2f& b){
    mypoint2f result = mypoint2f(a.x - b.x, a.y -b.y);
    return result ;
}
mypoint2f operator *(mypoint2f& a, mypoint2f& b){
    mypoint2f result = mypoint2f(a.x * b.x, a.y *b.y);
    return result ;
}
mypoint2f operator *(double& k, mypoint2f& a){
    mypoint2f result = mypoint2f(a.x * k, a.y * k);
    return result;
}

mypoint2f operator *(mypoint2f& a, double& k){
    mypoint2f result = mypoint2f(a.x * k, a.y * k);
    return result;
}
mypoint2f operator + (mypoint2f& a, mypoint2f& b){
    mypoint2f result = mypoint2f(a.x + b.x, a.y + b.y);
    return result;
}

std::ostream& operator <<(std::ostream& out, mypoint2f& a){
    out<<"x:"<<a.getx()<<" y:"<<a.gety()<<std::endl;
    return out;
}
bool operator == (mypoint2f& a, mypoint2f& b){
    if ( a.x == b.x and a.y == b.y)
        return true;
    else return false;
}









