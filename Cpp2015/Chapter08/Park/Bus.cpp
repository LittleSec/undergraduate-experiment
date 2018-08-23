#include<iostream>
#include<string>
#include"Bus.h"
using namespace std;

Bus::Bus(string plateNO, int numPassengers) :
			Automobile(plateNO), numPassengers(numPassengers) {
	}

void Bus::pay(Park *park) {
    cout<<plateNO<<"离开停车场，缴纳停车费2元" << endl;
    park->getPaid(2);
}
