#include<iostream>
#include"Automobile.h"
#include"Park.h"
#include<string>
using namespace std;

void Automobile::enter(Park *park) {
	park->assignSpace(this);
}

string Automobile::getPlateNO() {
	return plateNO;
}

void Automobile::leave(Park *park) {
    park->reclaimSpace(this);    // 让停车场收回停车位
    pay(park);                     // 向支付支付停车费，由派生类实现本方法
}
