#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

using namespace std;

class Shape{
public:
    virtual double getCircumference()const =0;
    virtual void print()const=0;
};

#endif // SHAPE_H_INCLUDED
