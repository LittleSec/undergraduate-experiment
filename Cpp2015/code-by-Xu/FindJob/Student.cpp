#include "Student.h"

Student::Student(const string &name, Subject *subject) : Observer(name) {
	subject->addObserver(this);
}

void Student::answerPhone(const string &message) {
	cout << "我叫" << name << "，我是一名毕业生，我收到了招聘信息：" << message << endl;
}
