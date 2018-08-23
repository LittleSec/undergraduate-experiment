#include<iostream>
using namespace std;
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point{
public:
    Point(double x = 0, double y = 0);

    double distanceTo();
    bool operator> (Point &p);
    friend ostream & operator <<(ostream &out ,const Point &p2);
private:
    double x;
    double y;
};

#endif // POINT_H_INCLUDED
