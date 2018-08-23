#ifndef OBSERVER_H_INCLUDED
#define OBSERVER_H_INCLUDED
#include<string>
using namespace std;

class Observer {
public:
    Observer(const string name):name(name){}
    string getName(){return name;}
    virtual void answerPhone(const string &message) = 0; // 接收职位需求信息
    virtual ~Observer(){};
protected:
    string name;// 观察者的名字
};

#endif // OBSERVER_H_INCLUDED
