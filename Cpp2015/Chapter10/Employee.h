#include"Date.h"
#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

class Employee{
public:
	Employee(const string firstname, const string lastname, const Date& birth, const Date& hire);

	int getAge(const Date& t2)const;//计算员工在参数指定的日期时，满多少岁。
	int getYearsWorked(const Date& t2)const;//计算该员工在参数指定的日期时，工作满了多少年
	int getDaysWorked(const Date& t2)const;//计算该员工在参数指定的日期时，工作了多少天。使用Date类的daysTo函数。

    bool operator> (const Employee& e2);
	friend ostream & operator<< (ostream &out, const Employee &e2);
	~Employee(){};
private:
	string firstname;
	string lastname;
	const Date birthDate;
	const Date hireDate;
	const Date today;
};

#endif // EMPLOYEE_H_INCLUDED
