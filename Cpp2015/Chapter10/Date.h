#include<iostream>
using namespace std;
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date{
public:
    Date(int year = 1990, int month = 1, int day = 1);

    int fullYearsTo(const Date &t2)const;
    int getDayOfYear()const; //计算当前日期是本年的第几天
    int getLeftDaysYear()const;//计算当前日期距本年结束还有几天，不包括当前日期这一天
    void setSeparator(char NewSaperator);
    int dayTo (const Date &t2)const;

    bool operator> (const Date &t2)const;
    friend ostream & operator <<(ostream &out ,const Date &t2);
private:
    int year;
    int month;
    int day;
    char separator;
    static const int JudgeMonth[13];
    bool isleapyear()const;
};

#endif // DATE_H_INCLUDED
