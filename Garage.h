#pragma once
#include <vector>
#include <limits>

#include "Vehicle.h"
#include "Bicycle.h"
#include "Bus.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"


class Garage
{
private:

	// const
	const std::string newline = "\n�&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�&�\n\n";

	// pekar vectors
	std::vector<Garage *> vp_pLots;
	std::vector<Vehicle *> vp_vehicles;
	
	// tempor�ra vectors
	Garage * glocal;
	Vehicle * vlocal;

	// strings
	std::string s_vehicle;
	std::string brand, color, regNr;
	std::string answer;

	// ints
	int wheels, wagons;
	int i_numberOfParkinglots; // Det antal som anv�ndaren matar in.
	int antal = 0; // Anv�nds f�r att r�kna antal vehicles found i s�kfunktionen.
	
	// bools
	bool b_taken;

	// enums
	enum e_vehicles { CAR = '1', BUS, TRUCK, BICYCLE, MOTORCYCLE };
	
public:
	// Constructors
	Garage(std::string, bool);
	Garage() {};

	// Programmet
	void CreateGarage(); // Skapar ett garage med x antal platser.
	void startMenu();
	void createVehicle(); 
	void printGarage(int a);
	
	// string metoder
	std::string YesNo();

	// bool metoder
	bool setValueBool(std::string);

	// Pekar metoder
	Garage * searchLot();
	Garage * searchLot(std::string);
	Vehicle * search_regnr(std::string regnr);

	// void metoder
	void uniqueRegnr(); // Kollar unikt regnr n�r du skapar fordon
	
	void ParkQuestion(std::string); // Fr�gar om anv�ndaren vill parkera bilen.
	void parkVehicle(std::string);
	void unparkVehicle(std::string);
	
	void searchVehicle();

	void print_allBrand(std::string brand);
	void print_allColor(std::string color);
	void print_allWheels(int wheels);

	// Deconstructor
	~Garage();
};

