#include <string>
using std::string;

#include "Date.h"

class Employee
{
public:
	Employee( const string, const string, const Date &, const Date & );
	void print() const;
	
	// 计算员工在参数指定的日期时，满多少岁
	int getAge(const Date& date) const;

	// 计算该员工工作满了多少年
	int getYearsWorked(const Date& date) const;
	// 计算该员工工作了多少天
	int getDaysWorked(const Date& date) const;
	~Employee(); // provide to confirm destruction order
private:
	string firstName;
	string lastName;
	const Date birthDate; // composition: member object
	const Date hireDate;
};
