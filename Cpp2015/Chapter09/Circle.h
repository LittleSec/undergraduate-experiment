#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include"Shape.h"
using namespace std;



class Circle:public Shape{
public:
    Circle(double r);
    double getCircumference()const;
    void print()const;
private:
    double radius;
};

#endif // CIRCLE_H_INCLUDED
