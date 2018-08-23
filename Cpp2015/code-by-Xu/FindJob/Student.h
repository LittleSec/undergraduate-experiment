#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include "Subject.h"
#include "Observer.h"
using namespace std;

class Student: public Observer {
public:
	Student(const string &name, Subject *subject);
	void answerPhone(const string &message);
};

#endif
