#include<iostream>
#include<string>
using namespace std;

class Date{                                   //定义日期类
public:
    Date(int oyear=1990, int omouth = 1, int oday = 1,char oseparator = '-'){
        year=oyear;
        mouth=omouth;
        day=oday;
        separator=oseparator;
    }
	void setdate (int oyear, int omouth , int oday);

	void printFullYear() const;
	void printStandardYear() const;

    void setYear(int NewYear);
    int getYear();
    void setMonth(int NewMonth);
    int getMonth();
    void setDay(int NewDay);
    int getDay();
    void setSeparator(char NewSeparator);

	int fullyearsto(const Date& date) const;
    int daysto(const Date& date) const;
	int getdayofyear(int omouth) const;
	int getleftdaysyear(int omouth) const;
private:
    int year;
	int mouth;
	int day;
	char separator;
	int checkday(int oday) const;
};

void Date::setYear(int NewYear){
    year=NewYear;
}

int Date::getYear(){
    return year;
}

void Date::setMonth(int NewMonth){
    if(NewMonth>12||NewMonth<1)
        mouth=1;
    else
        mouth=NewMonth;
}

int Date::getMonth(){
    return mouth;
}

void Date::setDay(int NewDay){
    int JudgeMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(year%400==0||(year%4==0&&year%100!=0))   //闰年2月有29天
        JudgeMonth[1]=29;

    if(NewDay>JudgeMonth[mouth-1])
        day=1;
    else
        day=NewDay;
}

int Date::getDay(){
    return day;
}

void Date::printFullYear()const{
    if(mouth<10)
        cout<<year<<separator<<"0"<<mouth<<separator<<day<<endl;
    else
        cout<<year<<separator<<mouth<<separator<<day<<endl;
}

void Date::printStandardYear()const{
    if(mouth<10)
        cout<<year%100<<separator<<"0"<<mouth<<separator<<day<<endl;
    else
        cout<<year%100<<separator<<mouth<<separator<<day<<endl;
}

void Date::setSeparator(char NewSeparator){ //改变连接符号
    separator=NewSeparator;
}

int Date::fullYearsTo(int LatterYear, int LatterMonth, int LatterDay){
    int GapYear;
    GapYear=LatterYear-year-1;  //不算LatterYear

    if(LatterMonth>month)       //当前月份大于设定月份，则满一年，所以+1
        GapYear=GapYear+1;
    else if(LatterMonth==month) //当前月份和设定月份相同的时候，若当前日比设定日同日或后，则满一年
        if(LatterDay>=day)
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
            if(iYear%400==0||(iYear%4==0&&iYear%100!=0))
                SumDay=SumDay+366;
            else
                SumDay=SumDay+365;
        SumDay=0-(SumDay-LastYearDay+FirstYearDay);
    }
    return SumDay;
}

//雇员类定义
class Employee{
public:
	Employee(const string l,const string f,const Date& b,const Date& h,const Date& t):birthDate(b),hireDate(h),todayDate(t){
		firstname = f;
		lastname = l;
	}
	void print()const;
	int getage(Date& date)const;
	int getyearworked(Date& date)const;
	int getdayworked(Date& date)const;
	~Employee(){};
private:
	string firstname;
	string lastname;
	const Date birthDate;
	const Date hireDate;
	const Date todayDate;
};

void Employee::print()const{
      cout<<firstname<<","<<lastname<<" Hired: ";
      hireDate.printfullyear();
	  cout<<" Birthday: ";
      birthDate.printfullyear();
}

int  Employee::getage(Date& date)const{
    return  birthDate.fullyearsto (todayDate);
}

int  Employee::getyearworked(Date& date)const{
    return  hireDate.fullyearsto (todayDate);
}

int  Employee::getdayworked(Date& date)const{
    return  hireDate.daysto (todayDate);
}

int main(){
	Date birth(1969,8,11);
	Date hire(1998,4,1);
	Date today(2010,4,30);
	Employee manager("Bob","Blue",birth,hire,today);
    cout<<endl;
	manager.print();
	cout<<endl;
	cout<<"work full "<<manager.getage(today)<<" years."<<endl;
	cout<<"have worked "<<manager.getdayworked(today)<<" days"<<endl;
	return 0;
}
