#include<iostream>
#include<string>
#include"Truck.h"
using namespace std;

Truck::Truck(string plateNO, double capacity) :
			Automobile(plateNO), capacity(capacity) {
	}

void Truck::pay(Park *park) {
    cout<<plateNO<<"离开停车场，缴纳停车费3元" << endl;
    park->getPaid(3);
}
