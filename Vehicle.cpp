#include "pch.h"
#include "Vehicle.h"


Vehicle::Vehicle(std::string name, std::string color, int wheels, std::string rNumber) : s_brand(name), s_color(color), i_wheels(wheels), s_regNr(rNumber) {

	b_inGarage = false;
}


void Vehicle::print()
{
	printType();
	std::cout << " Registration number : " << s_regNr << std::endl;
	std::cout << " Brand : " << s_brand << std::endl;
	std::cout << " Vehicle Color : " << s_color << std::endl;
	std::cout << " Number of wheels : " << i_wheels << std::endl;
	printName();
}

Vehicle::~Vehicle() {}

