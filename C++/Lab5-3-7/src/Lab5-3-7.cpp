//============================================================================
// Name        : Lab5-3-7.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Modelling fractions: part 3
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Fraction{
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
	// the functions below do not change the object
	// on which they are called, they produce a new object
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);
	// Comparison methods
	bool isGreaterThan(Fraction that);
	bool isLessThan(Fraction that);
	bool isEqual(Fraction that);
private:
	int numerator;
	int denominator;
	void reduce();
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

void Fraction::reduce()
{
	// reduce numerator and denominator to having no common factor.
	// use Euclidean method of finding GCD.
	// reference: https://en.wikipedia.org/wiki/Euclidean_algorithm

	// Subtract the smaller from the larger.  The smaller and the difference still have the same GCD.
	// Repeat the above, until the smaller and the difference are equal.  This is the GCD.

	if (numerator != 0)
	{
		int smaller = abs(numerator) > abs(denominator) ? abs(denominator) : abs(numerator);
		int larger = abs(numerator) > abs(denominator) ? abs(numerator) : abs(denominator);
		while (smaller < larger)	// reduce smaller and larger until they are equal to one another
		{
			int diff = larger - smaller;
			if (smaller < diff)
			{
				larger = diff;
			}
			else
			{
				larger = smaller;
				smaller = diff;
			}
		}

		// GCD === smaller == larger.
		numerator /= smaller;	// reduce both numerator and denominator
		denominator /= smaller;
	}
	else
	{
		// numerator == 0
		denominator = 1;	// simplify
	}
}

Fraction Fraction::plus(Fraction that)
{
	// Create common denominator
	int num1 = this->numerator * that.denominator;
	int num2 = that.numerator * this->denominator;
	int den = this->denominator * that.denominator; 	// common denominator...
	int num = num1 + num2;	// add the fractions
	Fraction result(num, den);
	result.reduce();	// remove GCD in numerator & denominator
	return result;
}

Fraction Fraction::minus(Fraction that)
{
	// Create common denominator
	int num1 = this->numerator * that.denominator;
	int num2 = that.numerator * this->denominator;
	int den = this->denominator * that.denominator; 	// common denominator...
	int num = num1 - num2;	// subtract the fractions
	Fraction result(num, den);
	result.reduce();	// remove GCD in numerator & denominator
	return result;
}

Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();	// remove GCD in numerator & denominator
	return result;
}

Fraction Fraction::by(Fraction that)
{
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;
	Fraction result(num, den);
	result.reduce();	// remove GCD in numerator & denominator
	return result;
}

bool Fraction::isGreaterThan(Fraction that)
{
	Fraction diff = this->minus(that);
	double d = diff.toDouble();
	if (d > 0.0)
	{
		return true;
	}
	return false;
}

bool Fraction::isLessThan(Fraction that)
{
	Fraction diff = this->minus(that);
	double d = diff.toDouble();
	if (d < 0.0)
	{
		return true;
	}
	return false;
}

bool Fraction::isEqual(Fraction that)
{
	Fraction diff = this->minus(that);
	if (diff.numerator == 0)
	{
		return true;
	}
	return false;
}



int main(void) {
	int num, den;

	string input1 = "";
	cout << "Enter fraction 1: ";
	getline(cin, input1);
	// parse input and get numerator and denominator

	unsigned int idx = input1.find("/");
	num = stoi(input1.substr(0,idx));	// reference: http://www.cplusplus.com/reference/string/stoi/
	den = stoi(input1.substr(idx+1));

	Fraction fraction1(num, den);	// first fraction


	string input2 = "";
	cout << "Enter fraction 2: ";
	getline(cin, input2);
	// parse input and get numerator and denominator

	idx = input2.find("/");
	num = stoi(input2.substr(0,idx));	// reference: http://www.cplusplus.com/reference/string/stoi/
	den = stoi(input2.substr(idx+1));

	Fraction fraction2(num, den);	// second fraction


	cout << '\n';
	if (fraction1.isEqual(fraction2))
	{
		cout << fraction1.toString() << " = " << fraction2.toString() << endl;
	}
	else if (fraction1.isGreaterThan(fraction2))
	{
		cout << fraction1.toString() << " > " << fraction2.toString() << endl;
	}
	else
	{
		cout << fraction1.toString() << " < " << fraction2.toString() << endl;
	}


	return 0;
}
