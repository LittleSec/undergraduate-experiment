#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include"Shape.h"
using namespace std;

class Rectangle:public Shape{
public:
    Rectangle(double a, double b);
    double getCircumference()const;
    void print()const;
    int getID()const;
    double getPrice()const;
private:
    double a;
    double b;
    int classID;
    double price;
};

#endif // RECTANGLE_H_INCLUDED
