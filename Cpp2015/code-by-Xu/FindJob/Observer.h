#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>
using namespace std;

class Observer {
public:
	Observer(const string &name) : name(name) { }
	virtual void answerPhone(const string &message) = 0;
protected:
	string name;
};

#endif
