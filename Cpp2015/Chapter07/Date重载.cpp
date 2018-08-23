#include<iostream>
using namespace std;

class Date{
public:
    Date(int yyear = 1990, int mmonth = 1, int dday = 1){
        year=yyear;
        month=mmonth;
        day=dday;
        separator='-';
    }

    //设置日期，如果有非法的月或日，将其置为1
    void setDate(int year, int month, int day);

    void setYear(int NewYear);
    int getYear();
    void setMonth(int NewMonth);
    int getMonth();
    void setDay(int NewDay);
    int getDay();
    void setSeparator(char NewSeparator);

    /*  打印函数  */
    void printFullYear();
    void printStandardYear();   //年份取两位数字。

    /*  计算函数  */
    // 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况
    int fullYearsTo(const Date &t2);
    // 计算当前日期与参数日期之间相差多少天(考虑闰年)，如果参数日期在当前日期之前，返回负数。
    int operator- (const Date &t2);
    bool operator> (const Date &t2);
    bool operator< (const Date &t2);
    friend ostream & operator <<(ostream &out ,const Date &date){
        out<<date.year<<date.separator<<date.month<<date.separator<<date.day;
        return out;
    }
private:
    int year;
    int month;
    int day;
    char separator;
};

void Date::setYear(int NewYear){
    year=NewYear;
}

int Date::getYear(){
    return year;
}

void Date::setMonth(int NewMonth){
    if(NewMonth>12||NewMonth<1)
        month=1;
    else
        month=NewMonth;
}

int Date::getMonth(){
    return month;
}

void Date::setDay(int NewDay){
    int JudgeMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(year%400==0||(year%4==0&&year%100!=0))   //闰年2月有29天
        JudgeMonth[1]=29;

    if(NewDay>JudgeMonth[month-1])
        day=1;
    else
        day=NewDay;
}

int Date::getDay(){
    return day;
}

void Date::printFullYear(){
    if(month<10)
        cout<<year<<separator<<"0"<<month<<separator<<day<<endl;
    else
        cout<<year<<separator<<month<<separator<<day<<endl;
}

void Date::printStandardYear(){
    if(month<10)
        cout<<year%100<<separator<<"0"<<month<<separator<<day<<endl;
    else
        cout<<year%100<<separator<<month<<separator<<day<<endl;
}

void Date::setSeparator(char NewSeparator){ //改变连接符号
    separator=NewSeparator;
}

int Date::fullYearsTo(const Date &t2){
    int GapYear;
    GapYear=t2.year-year-1;  //不算LatterYear

    if(t2.month>month)       //当前月份大于设定月份，则满一年，所以+1
        GapYear=GapYear+1;
    else if(t2.month==month) //当前月份和设定月份相同的时候，若当前日比设定日同日或后，则满一年
        if(t2.day>=day)
            GapYear=GapYear+1;
    return GapYear;
}

int Date::operator- (const Date &t2){
    int JudgeMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    //月份从1开始，数组从0开始，所以设定第0月有0天。
    //FirstYearDay记录设定日期是该年的第几天,LastYearDay记录的则是形参日期
    int FirstYearDay=0,LastYearDay=0;
    int iMonth,iYear;
    int SumDay=0;

    if(year%400==0||(year%4==0&&year%100!=0))
        JudgeMonth[2]=29;
    for(iMonth=0;iMonth<month;iMonth++)
        FirstYearDay=FirstYearDay+JudgeMonth[iMonth];
    FirstYearDay=FirstYearDay+day;

    /*由于初始化2月是28天，若设定年是闰年，则会变成29天，所以此时应该判断的是是否非闰年
      直接判断是不是非闰年比较难，所以在闰年条件前加个非运算符即可*/
    if(!(t2.year%400==0||(t2.year%4==0&&t2.year%100!=0)))
        JudgeMonth[2]=28;
    for(iMonth=0;iMonth<t2.month;iMonth++)
        LastYearDay=LastYearDay+JudgeMonth[iMonth];
    LastYearDay=LastYearDay+t2.day;

    //分当前日期和设定日期的前后情况
    if(t2.year>=year){
        for(iYear=year;iYear<t2.year;iYear++)
            if(iYear%400==0||(iYear%4==0&&iYear%100!=0))
                SumDay=SumDay+366;
            else
                SumDay=SumDay+365;
        SumDay=SumDay-FirstYearDay+LastYearDay;
        /*减去FirstYearDay的时候把设定日期的那天也减去了，但是加上LastYearDay的时候把最后一天也加上了。
          减法本来就是算前不算后，算后不算前，故在此不用+1或-1处理*/
    }
    else{
        for(iYear=t2.year;iYear<year;iYear++)
            if(iYear % 400 == 0 || (iYear % 4 == 0 && iYear % 100 != 0) )
                SumDay = SumDay + 366;
            else
                SumDay = SumDay + 365;
        SumDay=0-(SumDay - LastYearDay + FirstYearDay);
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

bool Date::operator< (const Date &t2){
    if (year < t2.year)
        return true;
    else if(year != t2.year)
        return false;
    else if(month < t2.month)
        return true;
    else if(month != t2.month)
        return false;
    else if(day < t2.day)
        return true;
    else
        return false;
}

int main(){
    Date birthDate(1969, 8, 11);
    Date t2(2010, 4, 15);
    Date China(1949, 10, 1);
    birthDate.printFullYear();
    birthDate.printStandardYear();
    birthDate.setSeparator('/');
    birthDate.printFullYear();

    cout<<birthDate.fullYearsTo(t2)<<", Full of "<<birthDate.fullYearsTo(t2)<<" years."<<endl;
    cout<<birthDate-t2<<" , Had lived "<<birthDate-t2<<" days."<<endl;
    cout<<-(birthDate-China)<<" , The People's Republic of China was born "<<-(birthDate-China)<<" days earlier than me."<<endl;

    if(t2> birthDate)
        cout<<t2<<" > "<<birthDate<<endl;
    else
        cout<<t2<<" <= "<<birthDate<<endl;

    if(China < birthDate)
        cout<<China<<" < "<<birthDate<<endl;
    else
        cout<<China<<" >= "<<birthDate<<endl;

    return 0;
}
