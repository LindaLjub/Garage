#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
private:
	bool b_emergencyStop;
	bool b_sideCar;

public:
	Motorcycle(std::string, std::string, int, std::string, bool, bool);

	void printType();
	void printName();

	~Motorcycle();
};

