//============================================================================
// Name        : Lab5-3-12.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 5.3.12 Inheritance basics: part 2
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class FarmAnimal{
public:
	FarmAnimal(double water_consumption);
	double getWaterConsumption();
	// ...
private:
	double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption) {
	this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption() {
	return water_consumption;
}




class DummyAnimal : public FarmAnimal{
public:
	DummyAnimal();
	double getWaterConsumption();	// could modify base by overriding method

};

DummyAnimal::DummyAnimal() : FarmAnimal(10.0)
{
}

//************************************************************************************************************
double DummyAnimal::getWaterConsumption()
{
	FarmAnimal *pBase = this;	// this is a way of getting access to the overridden base class method.
	return 100.0 + pBase->getWaterConsumption();
}
//************************************************************************************************************

class DoublingAnimal : public FarmAnimal
{
public:
	DoublingAnimal(double given_water_consumption);
};

DoublingAnimal::DoublingAnimal(double given_water_consumption)
: FarmAnimal(2 * given_water_consumption) {
}


class Sheep : public FarmAnimal
{
public:
	Sheep(double weight);
};

class Horse : public FarmAnimal
{
public:
	Horse(double weight);
};

class Cow : public FarmAnimal
{
public:
	Cow(double weight);
};

Sheep::Sheep(double weight) : FarmAnimal(1.1 * weight / 10.0)
{
	//water_consumption = 1.1 * weight / 10.0;
}

Horse::Horse(double weight) : FarmAnimal(6.8 * weight / 100.0)
{
	//water_consumption = 6.8 * weight / 100.0;
}

Cow::Cow(double weight) : FarmAnimal(8.6 * weight / 100.0)
{
	//water_consumption = 8.6 * weight / 100.0;
}

void printConsumption(FarmAnimal animal)
{
	cout << "This animal consumes " << animal.getWaterConsumption()
								<< " liters of water" << endl;
}

//************************************************************************************************************
void printConsumption2(DummyAnimal animal)	// This allows specifically passing a DummyAnimal parameter
{
	cout << "This animal consumes " << animal.getWaterConsumption()
								<< " liters of water" << endl;
}
//************************************************************************************************************



int main() {
	//	FarmAnimal animalA(5);
	//	DummyAnimal animalB;
	//	DoublingAnimal animalC(21);
	//	cout << "animalA consumes " << animalA.getWaterConsumption()
	//							<< " liters of water." << endl;
	//
	//	cout << "What about the others?" << endl;
	//
	//	printConsumption2(animalB);
	//	printConsumption(animalC);

	string input;
	string animal;
	double weight;
	double total = 0.0;
	do {
		cout << "Enter [animal] [weight] (kg): ";
		getline(cin, input);
		if (input.length() > 0)
		{
			unsigned int idx = input.find(" ");	// find location of space separating animal from weight.
			animal = input.substr(0,idx);
			weight = stod(input.substr(idx+1),NULL);	// ref: http://www.cplusplus.com/reference/string/stod/

			//cin >> animal >> weight;

			if (animal.compare("sheep") == 0)
			{
				Sheep a(weight);
				total += a.getWaterConsumption();
			}
			else if (animal.compare("horse") == 0)
			{
				Horse a(weight);
				total += a.getWaterConsumption();
			}
			else if (animal.compare("cow") == 0)
			{
				Cow a(weight);
				total += a.getWaterConsumption();
			}
			else
			{
				cout << "Invalid animal-skipping." << endl;
			}
		}
	} while (input.compare("") != 0);	// blank string ends input phase

	cout << "Total consumption [liters]: " << total << endl;

	return 0;
}
