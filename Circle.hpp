//
//  Circle.hpp
//  cppransac
//
//  Created by ललित सिंह on 09/11/2016.
//  Copyright © 2016 ललित सिंह. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "mypoint2f.hpp"
#include "LinearEqu.hpp"
#include "Header.hpp"
#include <vector>

class Circle{
private:
    double radius;
    mypoint2f center;
    bool isSingular;
public:
    Circle();
    Circle(double,  mypoint2f);
    Circle(  mypoint2f,  mypoint2f,  mypoint2f);
    Circle (std::vector<mypoint2f>);
    bool getSingular();
    mypoint2f getCenter();
    double getRadius();
    friend std::ostream& operator<<(std::ostream&, Circle&);
};
#endif /* Circle_hpp */
