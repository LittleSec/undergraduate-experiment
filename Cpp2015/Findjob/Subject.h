#ifndef SUBJECT_H_INCLUDED
#define SUBJECT_H_INCLUDED
#include"Observer.h"
class Observer;

class Subject {
public:
    virtual void addObserver(Observer *pObserver) = 0;// 添加观察者对象
    virtual void notifyObservers() = 0;// 通知所有的观察者，让他们接收信息
    virtual ~Subject(){};
};

#endif // SUBJECT_H_INCLUDED
