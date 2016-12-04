//
//  main.cpp
//  cppransac
//
//  Created by ललित सिंह on 09/11/2016.
//  Copyright © 2016 ललित सिंह. All rights reserved.
//

#include <iostream>
#include "Header.hpp"
#include "LinearEqu.hpp"
#include "mypoint2f.hpp"
#include "Circle.hpp"
#include <vector>
#include <time.h>
#include <cstdlib>
using namespace std;
double error(Circle C, mypoint2f p){
    return abs(distance(C.getCenter(), p) - C.getRadius());
}

vector<Circle> rnsac( vector<mypoint2f> points, int Nmin,int imax,float tau,int d, int num){
    
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);
    vector<Circle> selectedCircles;
    vector<mypoint2f> qualifiedPoints;
    for(int m = 0; m<num; m++){
        int size = points.size();
        cout<<"Total num of remaining points: "<<size<<endl;
        Circle qualifiedCircle;
        int voteNum=0;
        // vector<float> errors;
        int i = 0;
        while(i< imax){
            vector<int> rands;//random numbers
            
            //cout<<"just entered"<<endl;
            vector<mypoint2f> tempQualifiedPoints;
            //vector<float> tempErrors;
            for(int j = 0 ; j< Nmin; j++){
                rands.push_back(rand() % size);
                //cout<<rands[i] <<endl;
                //  tempQualifiedPoints.push_back(points[rands[i]]);
            }
            Circle C = Circle(points[rands[0]], points[rands[1]], points[rands[2]]);
            if (C.getSingular()){
                continue;
            }
            for( int i = 0; i<points.size(); i++){
                if( error(C, points[i])<tau){
                    // cout<<"error"<<error(C, points[i])<<" tau "<<tau<<endl;
                    tempQualifiedPoints.push_back(points[i]);
                }
            }
            if (tempQualifiedPoints.size()-Nmin > d){
               // cout<<"tempvote "<<tempQualifiedPoints.size()<<endl;
                if( voteNum < tempQualifiedPoints.size()){
                   // cout<<C;
                    qualifiedCircle =C;
                    qualifiedPoints = tempQualifiedPoints;
                    voteNum = tempQualifiedPoints.size();
                   // cout<<"vote "<<voteNum<<endl;
                }
            }
            i++;
        }
        points = compliment(points, qualifiedPoints);
        cout<<endl<<"Elected Circle "<<qualifiedCircle<<" Elected with " <<voteNum<<" votes"<<endl<<endl;
        selectedCircles.push_back(qualifiedCircle);
    }
    return selectedCircles;
}

int main(int argc, const char * argv[]) {
   /* internsectionPoint result = solveLinearEquation(LinearEqu(1.0,2.0,3.0), LinearEqu(2.0,3.0,4.0));
    cout<<result.point;
    Circle C = Circle(mypoint2f(1,1), mypoint2f(2,4), mypoint2f(5,3));
                                //http://math.stackexchange.com/questions/213658/get-the-equation-of-a-circle-when-given-3-points
    
    cout<<C; */
    FILE * file  = fopen("pts_to_ransac.txt","r");
    vector<mypoint2f> points;
    int res=1;
    while(res != EOF){
        float x,y;
        res = fscanf(file, " %f %f\n",&x,&y);
        mypoint2f point = mypoint2f((double)x,(double)y);
        //cout<<point;
        points.push_back(point);
    }
   vector<Circle> Circles = rnsac(points, 3, 1000, 0.05, 0,3);
    
    cout<<"Result"<<endl;
    for(int s = 0 ; s< Circles.size(); s++){
        
        cout<<Circles[s];
    }
    return 0;
}
