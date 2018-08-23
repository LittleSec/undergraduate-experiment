#include<iostream>
#include<iomanip>
#include"Rectangle.h"
using namespace std;

Rectangle::Rectangle(double a, double b):a(a),b(b){}

double Rectangle::getCircumference()const{
    return 2 * (a + b);
}

void Rectangle::print()const{
    cout<<"Rectangle, Length:"<<fixed<<setprecision(2)<<a;
    cout<<", Width:"<<fixed<<setprecision(2)<<b;
    cout<<", Circumference:"<<fixed<<setprecision(2)<<getCircumference()<<endl;
}

