#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle
{
private:
	bool b_rack;
	bool b_supportWheel;

public:
	Bicycle(std::string, std::string, int, std::string, bool, bool);

	void printType();
	void printName();

	~Bicycle();
};

