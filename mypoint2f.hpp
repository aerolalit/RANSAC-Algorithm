//
//  mypoint2f.hpp
//  hw3class
//
//  Created by ललित सिंह on 28/10/2016.
//  Copyright © 2016 ललित सिंह. All rights reserved.
//

#ifndef mypoint2f_hpp
#define mypoint2f_hpp

#include <stdio.h>
#include <iostream>
//#include "vect.hpp"
class mypoint2f{
private:
    double x;
    double y;

    
public:
    mypoint2f();
    mypoint2f(double, double);
    double getx();
    double gety();
    friend mypoint2f operator -(mypoint2f&, mypoint2f&);
    friend mypoint2f operator *( mypoint2f&, mypoint2f&);
    friend mypoint2f operator +(mypoint2f&, mypoint2f&);
    friend mypoint2f operator *(double&, mypoint2f&);
    friend mypoint2f operator *( mypoint2f&, double&);
    friend std::ostream& operator <<(std::ostream&, mypoint2f&);
    friend bool operator ==(mypoint2f&, mypoint2f&);
};
#endif /* mypoint2f_hpp */
