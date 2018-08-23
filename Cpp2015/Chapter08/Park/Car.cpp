#include<iostream>
#include<string>
#include"Car.h"
using namespace std;

Car::Car(string plateNO, string brand) :
			Automobile(plateNO), brand(brand) {
	}

void Car::pay(Park *park) {
    cout<<plateNO<<"离开停车场，缴纳停车费1元" << endl;
    park->getPaid(1);
}
