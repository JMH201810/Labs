//============================================================================
// Name        : Lab5-3-5.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Modelling fractions: part 1
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Fraction{
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};

// implement Fraction methods
Fraction::Fraction(int numerator, int denominator)
{
	// Make sure any negative sign is in the numerator.
	if (denominator < 0)
	{
		// change sign of both
		numerator = -numerator;
		denominator = -denominator;
	}

	this->numerator = numerator;
	this->denominator = denominator;
}

string Fraction::toString()
{
	string retstr = "";

	string integ = "", num = "", den = "";	// integer, numerator and denominator strings: e.g. 1 3/4

	int integNum = 0, numNum = 0, denNum = 0;	// numerical values

	integNum = numerator / denominator;	// whole number part

	numNum = numerator % denominator;	// remainder
	if (integNum < 0 && numNum < 0)
	{
		numNum = -numNum;	// single negative sign in mixed fraction
	}

	denNum = denominator;	// unchanged.

	if (integNum == 0 && numNum == 0)
	{
		// number is zero
		retstr = "0";
	}
	else
	{
		// number is not zero
		if (integNum != 0)
		{
			retstr.append(to_string(integNum));	// reference: http://www.cplusplus.com/reference/string/to_string/
		}

		if (numNum != 0)
		{
			retstr.append(" ");
			retstr.append(to_string(numNum));
			retstr.append("/");
			retstr.append(to_string(denNum));
		}
	}

	return retstr;
}

double Fraction::toDouble()
{
	double retval = 0.0;

	retval = (double) numerator / (double) denominator;

	return retval;
}



int main(void) {
	int num, den;
	string input = "";
	cout << "Enter fraction: ";
	getline(cin, input);
	// parse input and get numerator and denominator

	unsigned int idx = input.find("/");
	num = stoi(input.substr(0,idx));	// reference: http://www.cplusplus.com/reference/string/stoi/
	den = stoi(input.substr(idx+1));

	Fraction fraction(num, den);
	cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
	return 0;
}
