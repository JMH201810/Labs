//============================================================================
// Name        : prog2.9.2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	unsigned int amount;
	unsigned int denominations[] = {50, 20, 10, 5, 1};

	cout << "Minimum bills for input amount.\n";

	cout << "Enter non-negative amount: ";
	cin >> amount;

	if (amount > 0)
	{
		cout << "Input amount " << amount << " is composed of: ";

		for (int i = 0; i < 5; i++)
		{
			while (amount >= denominations[i])
			{
				cout << denominations[i] << ' ';
				amount -= denominations[i];
			}
		}
	}
	else
	{
		cout << "Input amount = 0, no output.\n";
	}

	return 0;
}
