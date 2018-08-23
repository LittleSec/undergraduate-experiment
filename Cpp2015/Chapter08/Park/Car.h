#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include"Automobile.h"
#include"Park.h"
#include<string>

class Car: public Automobile {
public:
	Car(string plateNO, string brand);
protected:
    void pay(Park *park);
    string brand;
};

#endif // CAR_H_INCLUDED
