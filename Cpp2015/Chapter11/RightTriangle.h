#ifndef RIGHTTRIANGLE_H_INCLUDED
#define RIGHTTRIANGLE_H_INCLUDED

#include"Shape.h"
using namespace std;

class RightTriangle:public Shape{
public:
    RightTriangle(double a, double b);
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

#endif // RIGHTTRIANGLE_H_INCLUDED
