/*Garage-projekt Linda, Vidar, Hasse.
  version 1.0
  26/11- Lagt till enum på Garage.cpp(10) och en switch till i_choiceVehicle metoden på (23)
  har även felsökt på main(31 & 32) kika på imorn
  27/11- fixat för att kunna skapa en Car, vi behöver definera printName i
  alla cpp-filerna på subklasserna och även fixa till garage.cpp-filen
  27/11- skrivit klart alla frågor för att skapa fordon inne i Garage.cpp /Vidar
  04/12- Finslipat koden. /Linda */
  

#include "pch.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Bicycle.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Garage.h"


int main()
{
	setlocale(LC_ALL, "");
	Garage lmao;
	
	lmao.CreateGarage();

	return 0;
}
