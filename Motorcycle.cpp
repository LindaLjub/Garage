#include "pch.h"
#include "Motorcycle.h"


Motorcycle::Motorcycle(std::string name,  std::string color, int wheels, std::string rNumber, bool eStop, bool sCar) : Vehicle(name,  color, wheels, rNumber), b_emergencyStop(eStop), b_sideCar(sCar) {}

void Motorcycle::printType()
{
	std::cout << " --Motorcycle--" << std::endl;
}

void Motorcycle::printName()
{
	std::cout << " Emergency stop : ";
	if (b_emergencyStop) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl; }

	std::cout << " Sidecar : ";
	if (b_sideCar) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl; }

	std::cout << " In Garage : ";
	if (b_inGarage) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl << std::endl; }

}

Motorcycle::~Motorcycle() {}
