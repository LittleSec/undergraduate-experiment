#ifndef EXPERIENCED_H_INCLUDED
#define EXPERIENCED_H_INCLUDED
#include"Observer.h"
#include"Subject.h"
// 有工作经验的求职者
class Experienced: public Observer {
public:
    Experienced(const string name, Subject *subject);
    void answerPhone(const string &message);
    ~Experienced(){};
};

#endif // EXPERIENCED_H_INCLUDED
