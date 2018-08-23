#ifndef AUTOMOBILE_H_INCLUDED
#define AUTOMOBILE_H_INCLUDED

#include"Park.h"
#include<string>
using namespace std;
class Park;
// 汽车类
class Automobile {
public:
    Automobile(string plateNO):plateNO(plateNO){}
    void enter(Park *park);
    void leave(Park *park);
    string getPlateNO();
protected:
    virtual void pay(Park *park) = 0;  // 向停车场支付停车费，由派生类实现
    string plateNO;
};

#endif // AUTOMOBILE_H_INCLUDED
