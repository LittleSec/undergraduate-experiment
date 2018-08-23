#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED
#include"Automobile.h"
#include<string>

class Truck: public Automobile {
public:
	Truck(string plateNO, double capacity);
protected:
    void pay(Park *park);
	double capacity;
};

#endif // TRUCK_H_INCLUDED
