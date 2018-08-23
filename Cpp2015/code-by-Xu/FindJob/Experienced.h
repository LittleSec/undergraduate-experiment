#ifndef EXPERIENCED_H_
#define EXPERIENCED_H_

#include <iostream>
#include "Observer.h"
#include "Subject.h"
using namespace std;

class Experienced: public Observer {
public:
	Experienced(const string &name, Subject *subject);
	void answerPhone(const string &message);
};

#endif
