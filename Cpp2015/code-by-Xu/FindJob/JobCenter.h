#ifndef JOBCENTER_H_
#define JOBCENTER_H_

#include <iostream>
#include "Subject.h"
using namespace std;

class JobCenter: public Subject {
public:
	JobCenter();
	~JobCenter();

	void addObserver(Observer *pObserver);
	void publishMessage(const string &message);
	void notifyObservers();
private:
	string message;
	bool statusChanged;
	int numObserver;
	Observer *list[100];
};

#endif