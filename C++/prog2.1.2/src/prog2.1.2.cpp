//============================================================================
// Name        : prog2.1.2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	float grossprice, taxrate, netprice, taxvalue;
	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;
	// Insert you code here
	if (grossprice > 0 && taxrate > 0 && taxrate < 100)
	{
		netprice = grossprice / (1.0 + taxrate/100.);
		taxvalue = grossprice-netprice;

		cout << "Net price: " << netprice << endl;
		cout << "Tax value: " << taxvalue << endl;
	}
	else
	{
		cout << "Invalid input.\n";
	}
	return 0;
}
