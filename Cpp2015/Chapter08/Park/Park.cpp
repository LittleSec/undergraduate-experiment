#include<iostream>
#include<string>
#include"Park.h"
#include"Automobile.h"
using namespace std;

Park::Park(int N) {
	spaces = new Automobile*[N];
	for (int i = 0; i < N; i++)
		spaces[i] = NULL;
	income = 0;
	this->N = N;
	numAuto = 0;
}

Park::~Park() {
	delete[] spaces;
}

void Park::showInfo() {
	if (numAuto == 0)
		cout << "停车场目前停放了" << numAuto << "辆汽车，共收入" << income << "元停车费";
	else {
		cout << "停车场目前停放了" << numAuto << "辆汽车：";
		for (int i = 0; i < N; i++)
			if (spaces[i] != NULL)
				cout << spaces[i]->getPlateNO() << ",";

		cout << "共收入" << income << "元停车费" << endl;
	}
}

bool Park::assignSpace(Automobile *pa) {
	for (int i = 0; i < N; i++) {
		if (spaces[i] == NULL) {
			spaces[i] = pa;
			numAuto++;
			cout << pa->getPlateNO() << "进入停车场，分配停车位" << endl;
			return true;
		}
	}
	cout << "无法为" << pa->getPlateNO() << "分配停车位" << endl;
	return false;
}

bool Park::reclaimSpace(Automobile *pa) {
	for (int i = 0; i < N; i++) {
		if (spaces[i] == pa) {
			spaces[i] = NULL;
			numAuto--;
			return true;
		}
	}
	cout << "停车场中没有车牌为" << pa->getPlateNO() << "的汽车";
	return false;
}

void Park::getPaid(int fee){
    income += fee;
}
