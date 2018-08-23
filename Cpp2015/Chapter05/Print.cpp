#include<iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

void displayMenu(){
    cout<<"*******************************"<<endl;
    cout<<"   1.  Circle (圆)"<<endl;
    cout<<"   2.  Rectangle (长方形)"<<endl;
    cout<<"   0.  Exit (退出)"<<endl;
    cout<<"*******************************"<<endl;
}

void getTwoPoints( struct Point *start, struct Point *finish ){

    cout<<"Please input the coordinate (x,y) of the start point:";
    cin>> start->x >> start->y ;

    cout<<"Please input the coordinate (x,y) of the end point:";
    cin>> finish->x >> finish->y ;

    if( start->x>=finish->x || start->y>=finish->y ){
        cout<<"Input error, Please input again!"<<endl<<endl;
        getTwoPoints( start, finish );
    }

}

void printPoint( struct Point *printp){
    cout<< "(" << printp->x << "," << printp->y << ")";
}

void drawCircle( struct Point *start, struct Point *finish ){
    struct Point center={ (finish->x + start->x) / 2 , (finish->y + start->y) / 2 };

    if ( (finish->x - start->x) != (finish->y - start->y) )
        cout<<"Not a circle, Select again"<<endl;
    else
    {
        cout<<"Draw a circle at center ";
        printPoint( &center );
        cout<<" with radius "<<(finish->x - start->x)/2<<endl;
    }

}

void drawRectangle( struct Point *start, struct Point *finish){
    int wide, height;
    wide = finish->x - start->x;
    height = finish->y - start->y;

    cout<<"Draw a rectangle at top left ";
    printPoint( start );
    cout<<" , whose wide is "<<wide<<" and height is "<<height<<endl;
}

int main()
{
    int choice=1;

    struct Point startP, endP;

    while ( choice )
    {
        displayMenu();
        cin >> choice;

        switch ( choice )
        {
        case 1:
            getTwoPoints(&startP, &endP);
            drawCircle(&startP, &endP);break;
        case 2:
            getTwoPoints(&startP, &endP);
            drawRectangle(&startP, &endP);break;
        case 0:
            cout << "Good Bye!"<<endl;break;
        default:
            cout << "Not supported! Please select again!"<<endl;break;
        }
    }
    return 0;
}
