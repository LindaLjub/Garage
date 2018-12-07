#include "pch.h"
#include "Bus.h"


Bus::Bus(std::string name,  std::string color, int wheels, std::string rNumber, bool toilet, bool dDecker): Vehicle(name,  color, wheels, rNumber), b_toilet(toilet), b_doubleDecker(dDecker) {}

void Bus::printType()
{
	std::cout << " --Bus--" << std::endl;
}

void Bus::printName()
{
	std::cout << " Bus toilet : ";
	if (b_toilet) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl; }

	std::cout << " Double decker : ";
	if (b_doubleDecker) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl; }

	std::cout << " In Garage : ";
	if (b_inGarage) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl << std::endl; }

}


Bus::~Bus() {}
