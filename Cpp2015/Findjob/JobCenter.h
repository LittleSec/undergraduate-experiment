#ifndef JOBCENTER_H_INCLUDED
#define JOBCENTER_H_INCLUDED
#include<string>
#include"Subject.h"
#include"Observer.h"

class Observer;

class JobCenter: public Subject {
public:
    JobCenter();
    void addObserver(Observer *pObserver);// 添加求职者对象
    void publishMessage(const string message); // 发布职位需求信息
    void notifyObservers();// 通知所有的求职者，让他们接收职位需求信息
    ~JobCenter();
private:
    string message;// 职位需求信息
    bool statusChanged;// 对象状态是否发生变化，即是否出现新的职位需求信息
    int numObserver;// 当前求职者的数量，也是下面指针数组的最有一个元素的下标
    Observer *list[100]; // 指针数组，保存Observer对象的指针
};

#endif // JOBCENTER_H_INCLUDED
