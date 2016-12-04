//
//  LinearEqu.cpp
//  cppransac
//
//  Created by ललित सिंह on 09/11/2016.
//  Copyright © 2016 ललित सिंह. All rights reserved.
//

#include "LinearEqu.hpp"
#include "Header.hpp"
LinearEqu::LinearEqu(){
    this -> A = 0;
    this -> B = 0;
    this -> C = 0;
}
LinearEqu::LinearEqu(double A, double B, double C){
    this-> A = A;
    this-> B = B;
    this-> C = C;
}
LinearEqu:: LinearEqu( mypoint2f a, mypoint2f b ){
    this-> A = 2* (b.getx() - a.getx());
    this-> B = 2 * ( b.gety() - a.gety());
    this-> C = sqr(b.getx()) + sqr(b.gety()) - sqr(a.getx()) - sqr(a.gety());
}
double LinearEqu::getA(){
    return this->A;
}
double LinearEqu::getB(){
    return this->B;
}
double LinearEqu::getC(){
    return this->C;
}
