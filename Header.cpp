//
//  Header.cpp
//  cppransac
//
//  Created by ललित सिंह on 09/11/2016.
//  Copyright © 2016 ललित सिंह. All rights reserved.
//

#include "Header.hpp"
#include <math.h>
double sqr(double a){
    return a*a;
}
double abs(double a){
    if (a<0)
        return -1* a;
    else
        return a;
}
double distance(mypoint2f a, mypoint2f b){
    return sqrt( sqr(a.getx()- b.getx()) + sqr(a.gety()- b.gety()));
}
double determinant(double a11, double a12, double a21, double a22){
    return a11 * a22 - a12 * a21;
}
internsectionPoint solveLinearEquation(LinearEqu a, LinearEqu b){
    double den = determinant(a.getA(), a.getB(), b.getA(), b.getB());
    internsectionPoint result;
    if ( den == 0){
        result.doesIntersect = true;
        return result;
    }
    double x = determinant(a.getC(), a.getB(), b.getC(), b.getB());
    double y = determinant(a.getA(), a.getC(), b.getA(), b.getC());
    result.point = mypoint2f(x/den, y/den);
    result.doesIntersect = false;
    return result;
}
std::vector<mypoint2f> compliment(std::vector<mypoint2f> set, std::vector<mypoint2f> subset ){
    std::vector<mypoint2f> complimentset;
    for(int i = 0; i<set.size();i++){
        bool check = false;
        for (int j = 0 ; j< subset.size(); j++){
            if (set[i]==subset[j]){
                check = true;
                break;
            }
            
        }
        if (!check){
            complimentset.push_back(set[i]);
        }
    }
    return complimentset;
}
