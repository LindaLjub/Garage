#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
private:
	bool b_cab;
	bool b_roofBox;

public:
	Car(std::string, std::string, int, std::string, bool, bool);

	void printType();
	void printName();
	
	~Car();
};
