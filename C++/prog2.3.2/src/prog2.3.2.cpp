//============================================================================
// Name        : prog2.3.2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Calculate PI using Liebnitz's method" << endl;

	double pi4 = 0.;
	long n;
	cout << "Number of iterations? ";
	cin >> n;
	// Insert your code here
	long den = 1;
	long mul = 1;
	for (long i = 0; i < n; i++)
	{
		pi4 += mul / (double) den;
		den += 2;
		mul = -mul;
	}

	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;

	return 0;
}
