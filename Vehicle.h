#pragma once
#include <vector>

class Vehicle
{
private:

protected:
	std::string s_brand;
	std::string s_color;
	std::string s_regNr;
	
	int i_wheels;
	bool b_inGarage;

public:
	Vehicle(std::string, std::string, int, std::string);
	
	// virtual metoder
	virtual void printType() = 0;
	virtual void printName() = 0;
	
	// metoder
	void print();
	void setInGarage(bool a)
	{
		if (a == true)
		{
			this->b_inGarage = true;
		}
		else
		{
			this->b_inGarage = false;	
		}
	}

	// getters
	bool get_InGarage() { return b_inGarage; }
	std::string get_regnr() { return s_regNr; }
	std::string get_color() { return s_color; }
	std::string get_brand() { return s_brand; }
	int get_wheels() { return i_wheels; }

	~Vehicle();	
};

