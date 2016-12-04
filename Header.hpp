//
//  Header.hpp
//  cppransac
//
//  Created by ललित सिंह on 09/11/2016.
//  Copyright © 2016 ललित सिंह. All rights reserved.
//

#ifndef Header_hpp
#define Header_hpp

#include <stdio.h>
#include "mypoint2f.hpp"
#include "LinearEqu.hpp"
#include <vector>

struct internsectionPoint{
    bool doesIntersect;
    mypoint2f point;
};
std::vector<mypoint2f> compliment(std::vector<mypoint2f>, std::vector<mypoint2f>);
double abs(double);
double sqr(double sqr);
double distance(mypoint2f , mypoint2f);
double determinant(double, double, double, double);
internsectionPoint solveLinearEquation(LinearEqu, LinearEqu);


#endif /* Header_hpp */
