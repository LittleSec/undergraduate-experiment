#ifndef PARK_H_INCLUDED
#define PARK_H_INCLUDED
#include"Automobile.h"
#include<string>

class Automobile;

class Park {
public:
	Park(int N);
	~Park();
	void showInfo();
	bool assignSpace(Automobile *pa);//分配车位
	bool reclaimSpace(Automobile *pa);//车离开
	void getPaid(int fee);
private:
	Automobile **spaces;
	int income;
	int N;  //车位个数
	int numAuto;//当前停放的车辆
};

#endif // PARK_H_INCLUDED
