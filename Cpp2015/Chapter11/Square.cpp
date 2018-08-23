#include<iostream>
#include<cmath>
#include<iomanip>
#include"Square.h"
using namespace std;

Square::Square(double a):Rectangle(a,a){
    this->a=a;
    classID = 4;
    price = 1.5;
}

double Square::getCircumference()const{
    return Rectangle::getCircumference();
}

void Square::print()const{
    cout<<getID();
    cout<<".Square, Side:"<<fixed<<setprecision(2)<<a;
    cout<<", Circumference:"<<fixed<<setprecision(2)<<Square::getCircumference();
    cout<<", Price:"<<Square::getPrice()<<fixed<<setprecision(2)<<endl;
}

int Square::getID()const{
    return classID;
}

double Square::getPrice()const{
    return price;
}
