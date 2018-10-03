//============================================================================
// Name        : prog2.3.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	long long c0 = 1, steps = 0;
	long long cp = 1, maxsteps = 0, c0maxsteps = 0;
	int dummy;
	cout << "Collatz's hypothesis." << endl;

	/*
	do {
	cout << "Enter the starting number (c0 >= 1): ";
	cin >> c0;
	} while (c0 < 1);
	*/


	for (long long i = 1; i < 100000000; i++)
	{
		cp = c0;
		c0 = i;
		steps = 0;


		while (c0 != 1)
		{
			if (c0 %2 == 0)
			{
				// even
				cp = c0;
				c0 /= 2;
			}
			else
			{
				// odd
				cp = c0;
				c0 = 3 * c0 + 1;
			}

			if (c0 <= 0)
			{
				cout << "c0 <= 0\n";
			}

			steps++;
			if (steps > maxsteps)
			{
				maxsteps = steps;
				c0maxsteps = i;
			}
			if (steps > 10000000)
			{
				cout << "*********************** steps > 1 million, c0 = " << c0 << endl;
				cout << "Press enter to continue:";
				cin >> dummy;
				break;
			}
			//cout << c0 << endl;
		}


		//cout << i << "   steps = " << steps << endl;
	}
	cout << "Maxsteps = " << maxsteps << " for c0 = " << c0maxsteps << endl;
	cout << "Done\n";

	return 0;
}
