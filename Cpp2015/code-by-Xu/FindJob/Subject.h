#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "Observer.h"

class Subject {
public:
	virtual void addObserver(Observer *pObserver) = 0;
	virtual void notifyObservers() = 0;
};

#endif