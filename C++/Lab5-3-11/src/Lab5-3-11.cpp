//============================================================================
// Name        : Lab5-3-11.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Inheritance basics: part 1
//============================================================================

#include <iostream>
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
	FarmAnimal animalA(5);
	DummyAnimal animalB;
	DoublingAnimal animalC(21);
	cout << "animalA consumes " << animalA.getWaterConsumption()
					<< " liters of water." << endl;

	cout << "What about the others?" << endl;

	printConsumption2(animalB);
	printConsumption(animalC);

	return 0;
}
