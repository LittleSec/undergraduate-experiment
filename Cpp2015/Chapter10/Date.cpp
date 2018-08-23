#include<iostream>
#include"Date.h"

using namespace std;

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
    for(int iMonth = 1; iMonth < month ; iMonth++)
        DayOfYear += JudgeMonth[iMonth];
    DayOfYear = DayOfYear + day;

    if((this->isleapyear() == true) && (month > 1))
        DayOfYear++;
    return DayOfYear;
}

int Date::getLeftDaysYear()const{
    int LeftDaysYear;
    LeftDaysYear = 365 - this->getDayOfYear();

    if((this->isleapyear() == true) && (month > 2))
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

int Date::dayTo (const Date &t2)const{
    int SumDay = 0;
    int iYear;
    if(year >= t2.year){
        for(iYear = t2.year; iYear <= year; iYear++)
            if(iYear % 400 == 0 || (iYear % 4 == 0 && iYear % 100 !=0))
                SumDay= SumDay + 366;
            else
                SumDay= SumDay + 365;
        SumDay= SumDay - this->getDayOfYear() - t2.getLeftDaysYear();
    }
    else{
        for(iYear = year; iYear <= t2.year; iYear++)
            if(iYear % 400 == 0 || (iYear % 4 == 0 && iYear % 100 !=0))
                SumDay = SumDay + 366;
            else
                SumDay = SumDay + 365;
        SumDay =0 - (SumDay - t2.getLeftDaysYear() - this->getDayOfYear());
    }

    return SumDay;
}

bool Date::operator> (const Date &t2)const{
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

