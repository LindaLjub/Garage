#pragma once
#include "Vehicle.h"

class Bus : public Vehicle
{
private:
	bool b_toilet;
	bool b_doubleDecker;

public:
	Bus(std::string, std::string, int, std::string, bool, bool);

	void printType();
	void printName();

	~Bus();
};

