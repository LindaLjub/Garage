#include "pch.h"
#include "Garage.h"

// Constructor
Garage::Garage(std::string s_vehicles, bool b_taken): s_vehicle(s_vehicles), b_taken(b_taken)  {}

// Printar ut antingen garaget eller hela fordon som finns i garaget
void Garage::printGarage(int a)
{
	switch (a)
	{
	case 1:
		std::cout << newline;
		std::cout << "\nThe Garage" << std::endl;
		std::cout << " - - - - -|" << std::endl;
		// skriver ut det sparade reg numret i garage platsen
		for (int i = 0; i < i_numberOfParkinglots; i++)
		{
			std::cout << "  " << vp_pLots[i]->s_vehicle << std::endl;
			std::cout << " - - - - -|" << std::endl;
		}
		break;
	case 2:
		std::cout << newline;
		std::cout << "\n --Parked vehicles--" << std::endl;
		for (int i = 0; i < vp_vehicles.size(); i++)
		{
			// skriver ut all information om det parkerade fordorna i garaget
			if (vp_vehicles[i]->get_InGarage() == true)
			{
				vp_vehicles[i]->print();
			}
		}
		break;
	}
}

// En ja/nej metod
std::string Garage::YesNo()
{
	std::cout << "\nY for Yes\tN for No.\n";
	std::cin >> answer;
	answer[0] = toupper(answer[0]);
	return answer;
}

// Första metoden som begränsar antal platser i garaget
void Garage::CreateGarage()
{
	bool b_createGarage = true;
	bool b_createParkinglots = true;
	do {

		std::cout << "Create garage?";
		answer = YesNo();

		switch (answer[0])
		{
			case 'N':
			{
				b_createGarage = false;
				break;
			}
			case 'Y':
			{
				// While loopen kollar så att cout stämmer(vilket den alltid är), sen tror vi att den kollar så att cin är möjligt och att numret användaren skriver in är mellan 1-20
				while ( (std::cout << "How many parkinglots? " << std::endl) && !(std::cin >> i_numberOfParkinglots) && i_numberOfParkinglots < 1 || i_numberOfParkinglots > 20 )
				{
					// Vi clearar cin och ignorerar buffern för att fånga otillåtna inputs
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input\n" << std::endl;
				}
				// Här pushar vi in så många platser i vectorn som användaren har valt
				for (int i = 0; i < i_numberOfParkinglots; i++)
				{
					vp_pLots.push_back(new Garage(" ", false));
				}

				b_createParkinglots = false;
				b_createGarage = false;
				startMenu(); // Skickar vidare till start menyn.

				break;
			}
			default:
			{
				std::cout << "Invalid input\n" << std::endl;
			}
		}
	
	} while (b_createGarage);
}

// Start menyn
void Garage::startMenu()
{
	do
	{
		std::cout << newline; 
		std::cout << "---*** Garage of hallelujah ***---" << std::endl;
		std::cout << " 1. Add a vehicle\n 2. Put vehicle into garage\n 3. Take vehicle out of garage\n 4. List all available vehicles \n 5. Search for vehicles\n 6. Print the parking lots\n 7. Print the vehicle in the garage\n 8. Exit program" << std::endl;
		std::cout << " Type in your choice and press enter : ";
		std::cin >> answer;
		if (answer[0] < '1' || answer[0] > '9')
		{
			std::cout << "Invalid input\n" << std::endl;
		}
	} while (answer[0] < '1' || answer[0] > '9');

	bool regFound=false; // bool till val 2

	switch (answer[0])
	{
	case '1': // Skapa ett fordon
		createVehicle();
		break;

	case '2': // Parkera ett fordon i garaget
		if (vp_vehicles.size() > 0)
		{
			do
			{
				regFound = false;
				std::cout << newline;
				std::cout << "Please enter the licence plate of the vehicle you wish to park: ";
				std::cin >> regNr;

				// Kollar om det angivna regnr fordonet redan är i garaget annars lägg in i garaget om det fordonet finns
				if (search_regnr(regNr)->get_InGarage() == true)
				{
					std::cout << "This vehicle is already parked in the garage!" << std::endl;
					regFound = true;
				}
				else
				{
					if (search_regnr(regNr)->get_regnr() == regNr)
					{
						regFound = true;
						parkVehicle(regNr);
					}
					else
					{
						std::cout << "There was no vehicle with a matching license plate.\nPlease try again.\n" << std::endl;
						regFound = false;
					}
				}
			} while (regFound == false);
		}
		else
		{
			std::cout << "There are no available vehicles." << std::endl;
		}
		startMenu();
		break;

	case '3': // Ta ut fordon ur garaget
		if (vp_vehicles.size() > 0)
		{
			do
			{
				regFound = false;
				std::cout << newline;
				std::cout << "Please enter the licence plate of the vehicle you wish to unpark: ";
				std::cin >> regNr;

				if (search_regnr(regNr)->get_regnr() == regNr)
				{
					regFound = true;
					unparkVehicle(regNr);
				}
				else
				{
					std::cout << "There was no vehicle with a matching license plate.\nPlease try again.\n" << std::endl;
					regFound = false;
				}
			} while (!regFound);
		}
		else
		{
			std::cout << "There are no available vehicles." << std::endl;
		}
		startMenu();
		break;

	case '4': // Printar ut alla skapade fordon
		std::cout << newline;
		for (int i = 0; i < vp_vehicles.size(); i++)
		{
			vp_vehicles[i]->print();
		}
		startMenu();
		break;

	case '5': // Går vidare till sök menyn
		searchVehicle();
		break;

	case '6': // Går till print garage metode med val 1
		printGarage(1);
		startMenu();
		break;

	case '7':// Går till print garage metode med val 2
		printGarage(2);
		startMenu();
		break;

	case '8':

		for (int i = 0; i < vp_pLots.size(); i++)
		{
			delete vp_pLots[i];
		}

		for (int i = 0; i < vp_vehicles.size(); i++)
		{
			delete vp_vehicles[i];
		}
		break;

	case '9': // Lägger in förvalda fordon för test
		vp_vehicles.push_back(new Car("Volvo", "blue", 4, "abc123", false, true));
		vp_vehicles.push_back(new Truck("Skania", "black", 6, "asd321", 2, true));
		vp_vehicles.push_back(new Bus("SLbuss", "blue", 6, "sll000", false, false));
		vp_vehicles.push_back(new Motorcycle("Harley", "red", 2, "hda666", false, false));
		vp_vehicles.push_back(new Bicycle("SteelHorse", "violet", 2, "hej999", true, false));
		startMenu();
		break;

	default:
		break;
	}
}

// Sätter bool värde för specifika fordons egenskaper
bool Garage::setValueBool(std::string question)
{
	bool loop=true;
	bool yesNo;
	do
	{
		std::cout << question;
		std::cin >> answer;
		answer[0] = toupper(answer[0]);
		if (answer[0] == 'Y' || answer[0] == 'N')
		{
			loop = false;
		}
	} while (loop);
	if (answer[0] == 'Y') { yesNo = true; }
	if (answer[0] == 'N') { yesNo = false; }
	return yesNo;
}

// Söker garaget efter tom plats
Garage * Garage::searchLot()
{
	int a = i_numberOfParkinglots;

	int i = 0;
	bool hit = false;
	do
	{
		// Går igenom platserna till den hittar en tom eller tills vi har kommit till sista indexet i vectorn
		if (vp_pLots[i]->b_taken == false || i == (a - 1))
		{
			hit = true;
		}
		else
		{
			i++;
		}
	} while (!hit);
	return vp_pLots[i];
}

// Söker garaget efter fordon med angivet regnr
Garage * Garage::searchLot(std::string regNr)
{
	int a = i_numberOfParkinglots;

	int i = 0;
	bool hit = false;
	do
	{
		if (vp_pLots[i]->s_vehicle == regNr || i == (a - 1))
		{
			hit = true;
		}
		else
		{
			i++;
		}
	} while (!hit);
	return vp_pLots[i];
}

// Parkerar angivet fordon
void Garage::parkVehicle(std::string regNr)
{
	// Vi söker efter en tom plats i garaget och parkerar
	glocal = searchLot();
	if (glocal->b_taken == true)
	{
		std::cout << "There was no available slot, take out a vehicle before parking one again." << std::endl;
	}
	else
	{
	glocal->s_vehicle = regNr;
	glocal->b_taken = true;
	search_regnr(regNr)->setInGarage(true);
	std::cout << "The vehicle is parked." << std::endl;
	}
}

// Tar ut angivet fordon ur garaget
void Garage::unparkVehicle(std::string regNr)
{
	// Vi söker efter om fordonet finns i garaget och plockar då ut det
	glocal = searchLot(regNr);
	if (glocal->s_vehicle != regNr)
	{
		std::cout << "The vehicle was not found in the garage." << std::endl;
	}
	else
	{
		glocal->s_vehicle = "";
		glocal->b_taken = false;
		search_regnr(regNr)->setInGarage(false);
		std::cout << "The vehicle has been taken out of the garage." << std::endl;
	}
}

// Metod till när du skapar frodon så att det bara finns unika regnr
void Garage::uniqueRegnr()
{
	bool regnrCheck = false;
	do
	{
		do
		{
			std::cout << "Please input the Licence plate: ";
			std::cin >> regNr;
			
			// Regnr godtas bara om det har 6 characters
			if (regNr.size() != 6)
			{
				regNr = "";
				std::cout << "The licence plate must be 6 characters long.\n";
			}
		} while (regNr.size() != 6);

		// Söker bara vp_vehicles vectorn om det finns index plaster i den
		if (vp_vehicles.size() > 0)
		{
			// Söker vectorn med det angivna reg numret om det finns ett fordon med samma
			if (search_regnr(regNr)->get_regnr() == regNr)
			{
				std::cout << " That vehicle already exists" << std::endl;
			}
			else
			{
				regnrCheck = true;
			}
		}
		else
		{
			regnrCheck = true;
		}
	} while (!regnrCheck);
}

// Meny för att skapa fordon
void Garage::createVehicle()
{
	bool e, f;
	bool go = true;

	do
	{
		std::cout << newline;
		std::cout << "Choose what kind of vehicle to create." << std::endl;
		std::cout << "1. Car\n2. Bus\n3. Truck\n4. Bicycle\n5. Motorcycle" << std::endl;
		std::cin >> answer;

	switch (answer[0])
	{
		/*Ber användaren skriva in uppgifter om sin bil alla boolvärden skickas vidare till
		setValueBool metoden som returnerar ett boolvärde.*/
	case CAR:
		go = false;

		// Skriv in brand
		std::cout << "Please enter the brand of your car: ";
		brand = "";
		while (brand == "")
		{
			std::getline(std::cin, brand);
		}

		// Skriv in vilken color
		std::cout << "Please enter the color of the car: ";
		std::cin >> color;

		// Sätter wheels
		while ((std::cout << "Please insert the amount of wheels on the car : ") && !(std::cin >> wheels))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, try again." << std::endl;
		}

		// Skriv in regnr
		uniqueRegnr();

		// Sätter bool värden
		e = setValueBool("Is the car a cabriolet ? \nY for Yes\tN for No.\n");
		f = setValueBool("Is the car compatible with a roof box?\nY for Yes\tN for No.\n");

		vp_vehicles.push_back (new Car(brand, color, wheels, regNr, e, f));
		
		// Parkerings fråga
		ParkQuestion(regNr); // Skickar till funktionen som frågar om man vill parkera.
		break;

	case BUS:
		go = false;

		std::cout << "Please enter the brand of your bus: ";
		brand = "";
		while (brand == "")
		{
			std::getline(std::cin, brand);
		}

		std::cout << "Please enter the color of the bus: ";
		std::cin >> color;

		while (std::cout << "Please insert the amount of wheels on the bus : " && !(std::cin >> wheels))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, try again." << std::endl;
		}

		uniqueRegnr();

		e = setValueBool("Does the bus have a toilet ? \nY for Yes\tN for No.\n");
		f = setValueBool("Is the bus a double decker? \nY for Yes\tN for No.\n");
		
		vp_vehicles.push_back(new Bus(brand, color, wheels, regNr, e, f));
		ParkQuestion(regNr); // Skickar till funktionen som frågar om man vill parkera.
		break;

	case TRUCK:
		go = false;
		std::cout << "Please enter the brand of your truck: ";
		brand = "";
		while (brand == "")
		{
			std::getline(std::cin, brand);
		}
		std::cout << "Please enter the color of the truck: ";
		std::cin >> color;
		while (std::cout << "Please insert the amount of wheels on the truck : " && !(std::cin >> wheels))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, try again." << std::endl;
		}
		uniqueRegnr();
		while (std::cout << "Please insert the maximum amount of wagons the truck can pull : " && !(std::cin >> wagons))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, try again." << std::endl;
		}
		e = setValueBool("Does the truck have a sleeping compartment?\nY for Yes\tN for No.\n");

		vp_vehicles.push_back(new Truck(brand, color, wheels, regNr, wagons, e));
		ParkQuestion(regNr); // Skickar till funktionen som frågar om man vill parkera.
		break;

	case BICYCLE:
		go = false;
		std::cout << "Please enter the brand of your bicycle: ";
		brand = "";
		while (brand == "")
		{
			std::getline(std::cin, brand);
		}
		std::cout << "Please enter the color of the bicycle: ";
		std::cin >> color;
		while (std::cout << "Please insert the amount of wheels on the bicycle : " && !(std::cin >> wheels))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, try again." << std::endl;
		}
		uniqueRegnr();
		e = setValueBool("Does the bicycle have a rack?\nY for Yes\tN for No.\n");
		f = setValueBool("Does the bicycle have support wheels?\nY for Yes\tN for No.\n");
		
		vp_vehicles.push_back(new Bicycle(brand, color, wheels, regNr, e, f));
		ParkQuestion(regNr); // Skickar till funktionen som frågar om man vill parkera.
		break;

	case MOTORCYCLE:
		go = false;
		std::cout << "Please enter the brand of your motorcycle: ";
		brand = "";
		while (brand == "")
		{
			std::getline(std::cin, brand);
		}
		std::cout << "Please enter the color of the motorcycle: ";
		std::cin >> color;
		while (std::cout << "Please insert the amount of wheels on the motorcycle : " && !(std::cin >> wheels))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, try again." << std::endl;
		}
		uniqueRegnr();
		e = setValueBool("Does The motorcycle have an emergency stop function?\nY for Yes\tN for No.\n");
		f = setValueBool("Does the motorcycle have a side car?\nY for Yes\tN for No.\n");

		vp_vehicles.push_back(new Motorcycle(brand, color, wheels, regNr, e, f));
		ParkQuestion(regNr); // Skickar till funktionen som frågar om man vill parkera.
		break;

	}
	} while (go);
	startMenu();
}

// Meny för att söka efter fordon
void Garage::searchVehicle() 
{
	bool b_searchVehi = true;
	bool b_parkVehi = true;
	do
	{	/*En switch dit användaren skickas om de vill söka efter ett specifikt fordon*/
		std::cout << newline;
		std::cout << " What do you want to search for?\n 1. License plate\n 2. Vehicles with brand\n 3. Vehicles with color\n 4. Vehicles with number of wheels\n 5. If the vehicle is in the garage\n 6. Go back to start menu" << std::endl;
		std::cout << " Type in your choice and press enter : ";
		std::cin >> answer;
		switch (answer[0])
		{	/*case 1 frågar användaren efter registreringsnummer som användaren vill söka på
			användaren bes efter ett registreringsnummer om inget matchande regnr finns får
			användaren info om detta, om inga bilar gjorts går det ej att komma åt metoden.*/
		case '1':
			if (vp_vehicles.size() > 0)
			{
				std::cout << " Type what license plate you want to search for : ";
				std::cin >> regNr;
				vlocal = search_regnr(regNr);
				if (vlocal->get_regnr() == regNr)
				{
					do
					{
						vlocal->print();
						std::cout << "Do you want to park this vehicle in the garage?";
						answer = YesNo();

						switch (answer[0])
						{
						case 'Y':
							b_parkVehi = false;
							parkVehicle(regNr);
							break;
						case 'N':
							b_parkVehi = false;
							break;
						default:
							std::cout << "Invalid input\n";
						}
					} while (b_parkVehi);

				}
				else
				{
					std::cout << "There was no vehicle with a matching license plate" << std::endl;
				}
			}
			else
			{
				std::cout << "There are no created vehicles." << std::endl;
			}
			break;
		case '2':
			if (vp_vehicles.size() > 0)
			{
				std::cout << " Type what brand you want to search for : ";
				std::cin >> brand;
				print_allBrand(brand);
			}
			else
			{
				std::cout << "There are no created vehicles." << std::endl;
			}
			break;
		case '3':
			if (vp_vehicles.size() > 0)
			{
				std::cout << " Type what color you want to search for : ";
				std::cin >> color;
				print_allColor(color);
			}
			else
			{
				std::cout << "There are no created vehicles." << std::endl;
			}
			break;
		case '4':
			if(vp_vehicles.size() > 0)
			{
				std::cout << " Type the amount of wheels on vehicles you want to search for : ";
				std::cin >> wheels;
				print_allWheels(wheels);
			}
			else
			{
				std::cout << "There are no created vehicles." << std::endl;
			}
			break;
			//hjälper användaren veta ifall ett fordon är i garaget eller inte
		case '5':
			if (vp_vehicles.size() > 0)
			{
				std::cout << " Type the license plate you want to search for in the garage : ";
				std::cin >> regNr;
				glocal = searchLot(regNr);
				if (glocal->s_vehicle == regNr)
				{
					std::cout << " The vehicle with licenseplate number : " << glocal->s_vehicle << ", is parked in the garage." << std::endl;
				}
				else
				{
					std::cout << " There is no vehicle parked with that license plate number in the garage." << std::endl;
				}
			}
			else
			{
				std::cout << "There are no created vehicles." << std::endl;
			}
			break;
		case '6':
			b_searchVehi = false;
			break;
		default:
			std::cout << "Invalid input\n";
			break;
		}
	} while (b_searchVehi);

	if (answer[0] == '6')
	{
		startMenu();
	}
	
}

// Metod som frågar om man vill parkera efter skapat fordon
void Garage::ParkQuestion(std::string regNr)
{	/*Vi frågar användaren om de vill parkera fordonet, om väljaren väljer ja skickar 
	vi vidare till parkVehicle annars skickar vi tillbaka användaren till tidigare metod.*/
	bool goo;
	do
	{
		std::cout << "Do you want to park your vehicle?";
		answer = YesNo();

		switch (answer[0])
		{
		case 'Y':
			parkVehicle(regNr);
			goo = false;
			break;
		case'N':
			goo = false;
			break;
		default:
			std::cout << "Invalid input\n";
		}
	} while (goo);
}

// Returnerar adressen av det angivna reg nummret
Vehicle * Garage::search_regnr(std::string regnr)
{	/*vi tar in registreringsnumret från användaren, vi kikar igenom alla
	fordon i vehicles vectorpekaren efter ett matchande registreringsnummer, om inget matchande
	finns skickar vi iväg sista vectorplatsen som är tom.*/
	int a = vp_vehicles.size();
	bool hit = false;
	int i = 0;
	do
	{
		if (vp_vehicles[i]->get_regnr() == regnr || i == (a - 1))
		{
			hit = true;
		}
		else
		{
			i++;
		}
	} while (!hit);
	return vp_vehicles[i];
}

// Printar alla fordon med det angivna märket
void Garage::print_allBrand(std::string brand)
{	/*Här kikar vi igenom alla vehicles i vehicles vectorpekaren
		alla fordon med samma märke användaren skrivit in skrivs ut med hjälp av print.*/
	for (int i = 0; i < vp_vehicles.size(); i++)
	{	
		if (vp_vehicles[i]->get_brand() == brand)
		{
			vp_vehicles[i]->print();
			antal++;
		}
	}

	std::cout << " Found: " << antal << " vechicle(s)" << std::endl;
}

// Printar alla fordon med den angivna färgen
void Garage::print_allColor(std::string color)
{
	for (int i = 0; i < vp_vehicles.size(); i++)
	{	
		if (vp_vehicles[i]->get_color() == color)
		{
			vp_vehicles[i]->print();
			antal++;
		}
	}

	std::cout << " Found: " << antal << " vechicle(s)" << std::endl;
}

// Printar alla fordon med det angivna hjulantalet
void Garage::print_allWheels(int wheels)
{
	for (int i = 0; i < vp_vehicles.size(); i++)
	{	
		if (vp_vehicles[i]->get_wheels() == wheels)
		{
			vp_vehicles[i]->print();
			antal++;
		}
	}

	std::cout << " Found: " << antal << " vechicle(s)" << std::endl;
}

Garage::~Garage() {}
