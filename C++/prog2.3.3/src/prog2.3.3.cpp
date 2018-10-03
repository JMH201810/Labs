//============================================================================
// Name        : prog2.3.3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	unsigned long long product;
	int n;
	cout << "Calculate 2^n" << endl;
	do {
		cout << "Enter n (between 0 and 63): ";
		cin >> n;
	} while (n < 0 || n > 63);

	product = 1;

	for (int i = 0; i < n; i++)
	{
		product *= 2;
	}

	cout << "2 ^ " << n << " = " << product << endl;


	return 0;
}
