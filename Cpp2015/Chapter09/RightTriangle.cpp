#include<iostream>
#include<cmath>
#include<iomanip>
#include"RightTriangle.h"
using namespace std;

RightTriangle::RightTriangle(double a, double b):a(a),b(b){}

double RightTriangle::getCircumference()const{
    return a + b + sqrt(a * a + b * b);
}

void RightTriangle::print()const{
    cout<<"RightTriangle, Leg1:"<<fixed<<setprecision(2)<<a;
    cout<<", Leg2:"<<fixed<<setprecision(2)<<b;
    cout<<", Circumference:"<<fixed<<setprecision(2)<<getCircumference()<<endl;
}
