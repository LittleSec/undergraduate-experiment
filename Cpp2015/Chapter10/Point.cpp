#include<iostream>
#include<cmath>
#include"Point.h"

using namespace std;

Point::Point(double x, double y):x(x),y(y){}

double Point::distanceTo(){
    return sqrt(x*x+y*y);
}

bool Point::operator> (Point &p){
    if(distanceTo() > p.distanceTo())
        return true;
    else
        return false;
}
