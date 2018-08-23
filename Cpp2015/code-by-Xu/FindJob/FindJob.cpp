#include<iostream>
#include<string>

#include "JobCenter.h"
#include "Student.h"
#include "Experienced.h"
using namespace std;

int main() {
	JobCenter *jobCenter = new JobCenter();

	Student *zhang = new Student("小张", jobCenter);
	Experienced *wang = new Experienced("小王", jobCenter);
	Student *li = new Student("小李", jobCenter);

	jobCenter->publishMessage("腾辉公司需要10个C++程序员。");
	jobCenter->notifyObservers();
	cout << endl;

	jobCenter->publishMessage("海景公司需要8个动画设计师。");
	jobCenter->notifyObservers();
	cout << endl;

	jobCenter->publishMessage("海景公司需要8个动画设计师。");
	jobCenter->notifyObservers();
	cout << endl;

	jobCenter->publishMessage("仁海公司需要9个电工。");
	jobCenter->notifyObservers();
	cout << endl;

	delete li;
	delete wang;
	delete zhang;

	delete jobCenter;

	return 0;
}
