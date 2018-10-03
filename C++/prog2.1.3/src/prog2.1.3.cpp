//============================================================================
// Name        : prog2.1.3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int sys;
	float m, ft, in;
	// Insert your code here
	do {
	cout << "Choose input system: 0 = metric, 1 = imperial: ";
	cin >> sys;
	} while (sys != 0 && sys != 1);

	if (sys == 0)
	{
		// metric input, imperial output
		do {
		cout << "Enter distance in meters (>= 0): ";
		cin >> m;	// input distance in meters
		} while (m < 0);

		in = m * 100.0 / 2.54;
		ft = (float)(int)(in/12.0);
		in -= 12.0 * ft;

		cout << '\n' << setprecision(0) << ft << "'" << setprecision(6) << in << "\"" << endl;
	}
	else
	{
		// imperial input, metric output
		cout << "Enter distance in feet and inches (>= 0)" << endl;
		do {
		cout << "Feet: ";
		cin >> ft;
		cout << "Inches: ";
		cin >> in;
		} while (ft < 0 || in < 0);

		m = (12.0 * ft + in)*2.54/100.0;
		cout << '\n' << m << "m" << endl;
	}

	return 0;
}
