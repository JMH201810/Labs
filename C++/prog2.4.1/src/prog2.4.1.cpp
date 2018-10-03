//============================================================================
// Name        : prog2.4.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Count number of 1 bits in input number.\n";

	unsigned long c=0, n, u = ~0;
	cout << "Enter a non-negative integer (between 0 and " << u << "): ";
	cin >> n;
	cout << "The input value is: " << n;

	while (n > 0)
	{
		if ((n & 1) == 1)
		{
			c++;
		}
		n >>= 1;
	}
	cout << " which has " << c << " ones." << endl;


	return 0;
}
