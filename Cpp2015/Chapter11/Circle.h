#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include"Shape.h"
using namespace std;

class Circle:public Shape{
public:
    Circle(double r);
    double getCircumference()const;
    void print()const;
    int getID()const;
    double getPrice()const;
private:
    double radius;
    int classID;
    double price;
};

#endif // CIRCLE_H_INCLUDED
