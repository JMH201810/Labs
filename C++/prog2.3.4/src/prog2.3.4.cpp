//============================================================================
// Name        : prog2.3.4.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double product;
	int n;
	cout << "Calculate 2^-n" << endl;
	do {
		cout << "Enter n (between 0 and 63): ";
		cin >> n;
	} while (n < 0 || n > 63);

	product = 1.0;

	for (int i = 0; i < n; i++)
	{
		product *= 0.5;
	}

	cout << "2 ^ " << -n << " = " << setprecision(20) << product << endl;


	return 0;
}
