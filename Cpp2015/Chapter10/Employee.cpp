#include<iostream>
#include<string>
#include"Employee.h"
#include"Date.h"

Employee::Employee(const string firstname, const string lastname, const Date& birth, const Date& hire):
    firstname(firstname),lastname(lastname),birthDate(birth),hireDate(hire){}

int Employee::getAge(const Date& t2)const{//计算员工在参数指定的日期时，满多少岁。
    return birthDate.fullYearsTo(t2);
}

int Employee::getYearsWorked(const Date& t2)const{//计算该员工在参数指定的日期时，工作满了多少年
    return hireDate.fullYearsTo(t2);
}

int Employee::getDaysWorked(const Date& t2)const{//计算该员工在参数指定的日期时，工作了多少天。使用Date类的daysTo函数。
    return t2.dayTo(hireDate);
}

bool Employee::operator> (const Employee& e2){
    if(e2.birthDate > birthDate)
        return true;
    else
        return false;
}
