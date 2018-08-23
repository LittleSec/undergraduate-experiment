#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED
#include"Automobile.h"
#include<string>

class Bus: public Automobile {
public:
	Bus(string plateNO, int numPassengers) ;
protected:
	int numPassengers;
	void pay(Park *park);
};

#endif // BUS_H_INCLUDED
