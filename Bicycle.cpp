#include "pch.h"
#include "Bicycle.h"



Bicycle::Bicycle(std::string name,  std::string color, int wheels, std::string rNumber, bool rack, bool sWheel) : Vehicle(name, color, wheels, rNumber), b_rack(rack), b_supportWheel(sWheel) {}

void Bicycle::printType()
{
	std::cout << " --Bicycle--" << std::endl;
}

void Bicycle::printName()
{
	std::cout << " Bicycle rack : ";
	if (b_rack) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl; }

	std::cout << " Support wheels : ";
	if (b_supportWheel) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl; }

	std::cout << " In Garage : ";
	if (b_inGarage) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl << std::endl; }
}


Bicycle::~Bicycle() {}
