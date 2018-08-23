#include<iostream>
#include<string>
#include<cmath>
#include"Date.h"
#include"Point.h"
#include"Employee.h"
using namespace std;

/*

class Date{
public:
    Date(int year = 1990, int month = 1, int day = 1);

    int fullYearsTo(const Date &t2)const;
    int getDayOfYear()const; //计算当前日期是本年的第几天
    int getLeftDaysYear()const;//计算当前日期距本年结束还有几天，不包括当前日期这一天
    void setSeparator(char NewSaperator);
    bool operator> (const Date &t2);
    int operator- (const Date &t2);
    friend ostream & operator <<(ostream &out ,const Date &t2);
private:
    int year;
    int month;
    int day;
    char separator;
    static const int JudgeMonth[13];
    bool isleapyear()const;
};

bool Date::isleapyear()const{
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 !=0))
        return true;
    else
        return false;
}

const int Date::JudgeMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
    this->separator = '-';
}

void Date::setSeparator(char NewSeparator){
    separator=NewSeparator;
}

int Date::getDayOfYear()const{
    int DayOfYear = 0;
    for(int iMonth = 0; iMonth < month ; iMonth++)
        DayOfYear += JudgeMonth[iMonth];
    DayOfYear = DayOfYear + day;

    if((this->isleapyear() == true) && (month > 1))
        DayOfYear++;

    return DayOfYear;
}

int Date::getLeftDaysYear()const{
    int LeftDaysYear;
    LeftDaysYear = 365 - this->getDayOfYear();

    if((this->isleapyear() == true) && (month > 1))
        LeftDaysYear++;

    return LeftDaysYear;
}

int Date::fullYearsTo(const Date &t2)const{
    int GapYear;
    GapYear = t2.year - year - 1;  //不算LatterYear

    if(t2.month > month)       //当前月份大于设定月份，则满一年，所以+1
        GapYear = GapYear + 1;
    else if(t2.month == month) //当前月份和设定月份相同的时候，若当前日比设定日同日或后，则满一年
        if(t2.day >= day)
            GapYear = GapYear + 1;
    return GapYear;
}

int Date::operator- (const Date &t2){
    int SumDay = 0;
    int iYear;
    if(t2.year >= year){
        for(iYear = year; iYear < t2.year; iYear++)
            if(iYear % 400 == 0 || (iYear % 4 == 0 && iYear % 100 !=0))
                SumDay= SumDay + 366;
            else
                SumDay= SumDay + 365;
        SumDay= SumDay - this->getDayOfYear() + t2.getLeftDaysYear();
    }
    else{
        for(iYear = t2.year; iYear < year; iYear++)
            if(iYear % 400 == 0 || (iYear % 4 == 0 && iYear % 100 !=0))
                SumDay = SumDay + 366;
            else
                SumDay = SumDay + 365;
        SumDay = 0 - (SumDay - t2.getLeftDaysYear() + this->getDayOfYear());
    }

    return SumDay;
}

bool Date::operator> (const Date &t2){
    if (year > t2.year)
        return true;
    else if(year != t2.year)
        return false;
    else if(month > t2.month)
        return true;
    else if(month != t2.month)
        return false;
    else if(day > t2.day)
        return true;
    else
        return false;
}

class Point{
public:
    Point(int x=0, int y=0);

    int distanceTo();
    bool operator> (Point &p);
    friend ostream & operator <<(ostream &out ,const Point &p2);
private:
    int x;
    int y;
};

Point::Point(int x, int y):x(x),y(y){}

int Point::distanceTo(){
    return sqrt(x*x+y*y);
}

bool Point::operator> (Point &p){
    if(distanceTo() > p.distanceTo())
        return true;
    else
        return false;
}

*/

ostream & operator <<(ostream &out ,const Date &t2){
    cout<<t2.year<<t2.separator<<t2.month<<t2.separator<<t2.day;
    return out;
}

ostream & operator <<(ostream &out ,const Point &p2){
    cout<<"("<<p2.x<<","<<p2.y<<")";
    return out;
}

ostream & operator <<(ostream &out, const Employee &e2){
    cout<<e2.firstname<<","<<e2.lastname<<", birthday:"<<e2.birthDate<<" , hireday:"<<e2.hireDate<<endl;
    return out;
}

template<typename T>
int comp(T *p, int n){
    int i = 0, m = i;
    for(; i < n; i++)
        if(p[i] > p[m])
            m = i;
    return m;
}

int main(){
    Point p[5] = {Point(2,3),Point(20,30),Point(19,31),Point(8,5),Point(15,15)};
    Date hire[5] = {Date(2011,4,30),Date(2001,6,3),Date(2010,8,31),Date(2003,1,1),Date(2008,8,8)};
    Date bir[5] = {Date(1995,9,4),Date(1989,1,1),Date(1970,6,6),Date(1988,12,30),Date(1992,2,29)};
    Date today(2015,6,12);
    Employee e[5] = {Employee("He","JX",bir[0],hire[0]),Employee("Fan","LX",bir[1],hire[1]),Employee("Han","GQ",bir[2],hire[2]),
                     Employee("Gong","H",bir[3],hire[3]),Employee("Xu","WH",bir[4],hire[4])};
    cout<<"Longest Point:"<<p[comp(p,5)]<<endl;
    cout<<"Newest Date:"<<hire[comp(hire,5)]<<endl;
    cout<<"Oldest Employee:"<<endl<<e[comp(e,5)]<<endl;

    return 0;
}
