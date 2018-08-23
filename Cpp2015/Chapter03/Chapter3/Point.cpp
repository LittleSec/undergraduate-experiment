#include<iostream>
using namespace std;

class Point{
public:
    Point(int xx=0, int yy=0){
        x=xx;
        y=yy;
    }

    void setX(int newX);
    int getX();
    void setY(int newY);
    int getY();
    void print();
    void moveRight(int offset);
    void moveDown(int offset);
private:
    int x;
    int y;
};

void Point::setX(int newX){
    x=newX;
}

int Point::getX(){
    return x;
}

void Point::setY(int newY){
    y=newY;
}

int Point::getY(){
    return y;
}

void Point::moveRight(int offset){
    x=x+offset;
}

void Point::moveDown(int offset){
    y=y+offset;
}

void Point::print(){
    cout<<"( "<<x<<" , "<<y<<" )";
}

int main(){
    int x,y;

    cout<<"Please input a point:";
    cin>>x>>y;
    Point p1(x,y);
    cout<<"Point p1:";
    p1.print();
    cout<<endl;
    Point p2(x*2,y*2);
    cout<<"Point p2:";
    p2.print();
    cout<<endl;

    p1.moveRight(10);
    cout<<"After moving right, p1:";
    p1.print();
    cout<<endl;
    p2.moveDown(-10);
    cout<<"After moving down , p2:";
    p2.print();
    cout<<endl;
}
