#include<iostream>
#include<iomanip>
#include<cmath>
#include"Circle.h"
using namespace std;

const double Pi = 3.1415926;

Circle::Circle(double r):radius(r){}

double Circle::getCircumference()const{
    return 2 * radius * Pi;
}

void Circle::print()const{
    cout<<"Circle, Radius:"<<fixed<<setprecision(2)<<radius;
    cout<<", Circumference:"<<fixed<<setprecision(2)<<getCircumference()<<endl;
}
