//============================================================================
// Name        : prog2.5.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int choice = 0;
	double a, b;
	do {
		// draw menu
		cout << "\nMENU:\n0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nYour choice? ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			break;	// exit
		case 1:
			// add
			cout << "\nEnter two double values to add: ";
			cin >> a >> b;
			cout << a << " + " << b << " = " << (a+b) << endl;
			break;

		case 2:
			// subtract
			cout << "\nEnter two double values to subtract: ";
			cin >> a >> b;
			cout << a << " - " << b << " = " << (a-b) << endl;
			break;

		case 3:
			// multiply
			cout << "\nEnter two double values to multiply: ";
			cin >> a >> b;
			cout << a << " * " << b << " = " << (a*b) << endl;
			break;

		case 4:
			// divide
			cout << "\nEnter two double values to divide: ";
			cin >> a >> b;
			if (b != 0.0)
			{
				cout << a << " / " << b << " = " << (a/b) << endl;
			}
			else
			{
				cout << "\nCannot divide by zero.\n";
			}
			break;

		default:
			cout << "\nInvalid choice.\n";
		}
	} while (choice != 0);

	return 0;
}
