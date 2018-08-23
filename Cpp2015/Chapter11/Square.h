#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include"Rectangle.h"
using namespace std;

class Square:public Rectangle{
public:
    Square(double a);
    double getCircumference()const;
    void print()const;
    int getID()const;
    double getPrice()const;
private:
    double a;
    int classID;
    double price;
};

#endif // SQUARE_H_INCLUDED
