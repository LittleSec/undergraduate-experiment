#include<iostream>
#include<iomanip>
#include<cmath>
#include"Circle.h"
using namespace std;

const double Pi = 3.1415926;

Circle::Circle(double r):radius(r){
    classID = 1;
    price = 4.0;
}

double Circle::getCircumference()const{
    return 2 * radius * Pi;
}

void Circle::print()const{
    cout<<getID();
    cout<<".Circle, Radius:"<<fixed<<setprecision(2)<<radius;
    cout<<", Circumference:"<<fixed<<setprecision(2)<<getCircumference();
    cout<<", Price:"<<getPrice()<<fixed<<setprecision(2)<<endl;
}

int Circle::getID()const{
    return classID;
}

double Circle::getPrice()const{
    return price;
}
