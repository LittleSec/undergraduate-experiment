#include<iostream>
#include<string>
using namespace std;

class Date{                                   //定义日期类
public:
    Date(int year=1990, int mouth = 1, int day = 1,char separator = '-'){
        this->year=year;
        this->mouth=mouth;
        this->day=day;
        this->separator=separator;
    }

    int setYear()const;
    int setMouth()const;
    int setDay()const;

    void setseparator(char separator);
	void printfullyear() const;
	void printstandardyear() const;

	int fullYearsTo(const Date& t2) const;
    int daysTo(const Date& date) const;
	int getdayofyear(int omouth) const;
	int getleftdaysyear(int omouth) const;
private:
    int year;
	int mouth;
	int day;
	char separator;
	static const int dayspermonth[12];
	int checkday(int oday) const;
    bool isleapyear(int oyear) const;
};

const int Date::dayspermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

//判断该年是否为闰年
bool Date::isleapyear(int oyear) const{
	if( ((oyear % 4 == 0) && (oyear % 100 != 0)) || oyear % 400 == 0 )
		return true;
	else
	    return false;
}

//计算参数年已过的天数
int Date::getdayofyear(int omouth) const{
	int total=0,i;

	if(omouth>1)
        for(i=0;i<omouth-1;i++)
            total=total+dayspermonth[i];
	return total;
}

int Date::setYear() const{
    return this->year;
}

int Date::setMouth() const{
    return this->mouth;
}

int Date::setDay() const{
    return this->day;
}

//计算当年剩余的天数
int Date::getleftdaysyear(int omouth) const{
    int total=0,i;

	if(omouth<12)
        for(i=omouth;i<12;i++)
            total=total+dayspermonth[i];
	return total;
}

//打印全年日期
void Date::printfullyear()const{
	cout<<year<<separator<<mouth<<separator<<day;
}

//打印标准的日期
void Date::printstandardyear()const{
	cout<<year % 100<<separator<<mouth<<separator<<day;
}

//设置私有数据separator
void Date::setseparator(char separator){
    this->separator = separator;
}

//计算当年与参数年相差的年数
int Date::fullYearsTo(const Date &t2)const{
    int GapYear;
    GapYear=t2.setYear()- this->setYear() - 1;  //不算LatterYear

    if(t2.setMouth() > this->setMouth() )       //当前月份大于设定月份，则满一年，所以+1
        GapYear=GapYear+1;
    else if(t2.setMouth()==this->setMouth()) //当前月份和设定月份相同的时候，若当前日比设定日同日或后，则满一年
        if(t2.setDay() >=this->setDay())
            GapYear=GapYear+1;
    return GapYear;
}

int Date::daysTo(const Date &t2)const{
    int FirstYearDay=0,LastYearDay=0;
    int iMonth,iYear;
    int SumDay=0;

    for(iMonth=0;iMonth<this->setMouth()-1;iMonth++)
        FirstYearDay=FirstYearDay+dayspermonth[iMonth];
    FirstYearDay=FirstYearDay+this->setDay();
    if((isleapyear(this->setYear()) == true) && (this->setMouth() > 1))
        FirstYearDay++;

    for(iMonth=0;iMonth<t2.setMouth()-1;iMonth++)
        LastYearDay=LastYearDay+dayspermonth[iMonth];
    LastYearDay=LastYearDay+t2.setDay();
    if((isleapyear(t2.setYear()) == true) && (t2.setMouth() > 1))
        LastYearDay++;

    //分当前日期和设定日期的前后情况
    if(t2.setYear() >= year){
        for(iYear=year;iYear<t2.setYear();iYear++)
            if(iYear%400==0||(iYear%4==0&&iYear%100!=0))
                SumDay=SumDay+366;
            else
                SumDay=SumDay+365;
        SumDay=SumDay-FirstYearDay+LastYearDay;
        /*减去FirstYearDay的时候把设定日期的那天也减去了，但是加上LastYearDay的时候把最后一天也加上了。
          减法本来就是算前不算后，算后不算前，故在此不用+1或-1处理*/
    }
    else{
        for(iYear = t2.setYear(); iYear < this->setYear(); iYear++)
            if(iYear % 400 == 0 || (iYear % 4 == 0 && iYear % 100 != 0) )
                SumDay = SumDay + 366;
            else
                SumDay = SumDay + 365;
        SumDay = 0 - (SumDay - LastYearDay + FirstYearDay);
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
    return  birthDate.fullYearsTo (todayDate);
}

int  Employee::getyearworked(Date& date)const{
    return  hireDate.fullYearsTo (todayDate);
}

int  Employee::getdayworked(Date& date)const{
    return  hireDate.daysTo (todayDate);
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
