#include<iostream>
#include<iomanip>
#include"Rectangle.h"
using namespace std;

Rectangle::Rectangle(double a, double b):a(a),b(b){
    classID = 2;
    price = 2.0;
}

double Rectangle::getCircumference()const{
    return 2 * (a + b);
}

void Rectangle::print()const{
    cout<<getID();
    cout<<".Rectangle, Length:"<<fixed<<setprecision(2)<<a;
    cout<<", Width:"<<fixed<<setprecision(2)<<b;
    cout<<", Circumference:"<<fixed<<setprecision(2)<<getCircumference();
    cout<<", Price:"<<getPrice()<<fixed<<setprecision(2)<<endl;
}

int Rectangle::getID()const{
    return classID;
}

double Rectangle::getPrice()const{
    return price;
}
