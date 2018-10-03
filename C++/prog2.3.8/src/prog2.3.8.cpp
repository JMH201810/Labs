//============================================================================
// Name        : prog2.3.8.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	// Note: in lab statement example output #1, 5! != 10.
	int n;
	unsigned long long fact;
	cout << "Calculate factorial of n.\n";

	do {
		cout << "Enter n (between 0 and 20): ";
		cin >> n;
	} while (n < 0 || n > 20);

	fact = 1;
	if (n != 0)
	{
		for (int i = 1; i <= n; i++)
		{
			fact = fact * i;
		}
	}
	cout << fact << endl;
	return 0;
}
