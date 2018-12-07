#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
	int i_maxWagon;
	bool b_sleepComp;

public:
	Truck(std::string, std::string, int, std::string, int, bool);

	void printType();
	void printName();

	~Truck();
};

