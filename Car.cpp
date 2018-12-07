#include "pch.h"
#include "Car.h"


Car::Car(std::string name, std::string color, int wheels, std::string rNumber, bool cab, bool takbox)
	: Vehicle(name,  color, wheels, rNumber), b_cab(cab), b_roofBox(takbox) {}

void Car::printType()
{
	std::cout << " --Car--" << std::endl;
}

void Car::printName()
{
	std::cout << " Cab : ";
	if (b_cab) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl; }

	std::cout << " Roof box : ";
	if (b_roofBox) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl << std::endl; }

	std::cout << " In Garage : ";
	if (b_inGarage) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl << std::endl; }

}

Car::~Car() {}