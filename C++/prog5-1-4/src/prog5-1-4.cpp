//============================================================================
// Name        : prog5-1-4.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Classes and objects: ShopItemOrder
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class ShopItemOrder
{
private:
	string name;
	float unitPrice;
	unsigned int numItemsOrdered;
public:
	ShopItemOrder();
	string get_name();
	float get_unitPrice();
	unsigned int get_numItemsOrdered();
	void set_name(string n);
	void set_unitPrice(float p);
	void set_numItemsOrdered(unsigned int n);

	float totalPriceOrder();
	void printOrder();
};

ShopItemOrder::ShopItemOrder()
{
	name = "";
	unitPrice = 0.;
	numItemsOrdered = 0;
}

string ShopItemOrder::get_name()
{
	return name;
}

float ShopItemOrder::get_unitPrice()
{
	return unitPrice;
}

unsigned int ShopItemOrder::get_numItemsOrdered()
{
	return numItemsOrdered;
}

void ShopItemOrder::set_name(string n)
{
	if (n.length() > 0)
	{
	this->name = n;
	}
}

void ShopItemOrder::set_unitPrice(float p)
{
	if (p > 0.0)
	{
	this->unitPrice = p;
	}
}

void ShopItemOrder::set_numItemsOrdered(unsigned int n)
{
	this->numItemsOrdered = n;
}

float ShopItemOrder::totalPriceOrder()
{
	return numItemsOrdered * unitPrice;
}

void ShopItemOrder::printOrder()
{
	cout << "Total order: " << numItemsOrdered << " " << name << " at $" << fixed << setprecision(2)
			<< unitPrice << " each, $" << totalPriceOrder() << " total." << endl;
}

int main() {
	ShopItemOrder s;

	s.set_name("something");
	s.set_numItemsOrdered(3);
	s.set_unitPrice(5.25);

	s.printOrder();


	return 0;
}
