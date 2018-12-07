#include "pch.h"
#include "Truck.h"


Truck::Truck(std::string name,  std::string color, int wheels, std::string rNumber, int mWagon, bool sSpot) : Vehicle(name,  color, wheels, rNumber), i_maxWagon(mWagon), b_sleepComp(sSpot) {}

void Truck::printType()
{
	std::cout << " --Truck--" << std::endl;
}

void Truck::printName()
{
	std::cout << " Maximum amount of wagons : " << i_maxWagon << std::endl;

	std::cout << " Sleep compartment : ";
	if (b_sleepComp) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl << std::endl; }

	std::cout << " In Garage : ";
	if (b_inGarage) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl << std::endl; }
}

Truck::~Truck() {}



