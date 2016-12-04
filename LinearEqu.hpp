//
//  LinearEqu.hpp
//  cppransac
//
//  Created by ललित सिंह on 09/11/2016.
//  Copyright © 2016 ललित सिंह. All rights reserved.
//

#ifndef LinearEqu_hpp
#define LinearEqu_hpp

#include <stdio.h>
#include "mypoint2f.hpp"
//This class represents a linear equation in the form Ax + By = C where
// x and y are the variables and A, B, C are the constants.

class LinearEqu{
private:
    double A;
    double B;
    double C;
public:
    LinearEqu();
    LinearEqu(double, double , double);  // when A, B, C are given
    LinearEqu(mypoint2f, mypoint2f); // two independent on circle
    double getA();
    double getB();
    double getC();
};
#endif /* LinearEqu_hpp */
