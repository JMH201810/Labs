//============================================================================
// Name        : prog2.3.6.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Draw pyramids\n";

	do {
		cout << "Enter pyramid height, n (between 1 and 30): ";
		cin >> n;
	} while (n < 1 || n > 30);

	for (int h = n; h > 0; h--)	// loop over height, starting at top
	{
		for (int p = 0; p < 3; p++)	// loop over pyramid (0 on left, 2 on right)
		{
			int startPos = h;	// horizontal starting position
//			int startPos = 15+h;	// horizontal starting position
			for (int w = 0; w < startPos; w++)
			{
				// print leading spaces at given height.
				cout << ' ';
			}
			cout << '*';	// print character on left wall
			if (h < n)
			{
				// Not at peak, so print gap between left and right wall
				for (int w = 0; w < 2*(n-h)-1; w++)
				{
					if (h > 1)
					{
						cout << ' ';
					}
					else
					{
						cout << '*';
					}
				}
				cout << '*';	// print character on right wall
			}
			for (int w = 0; w < startPos; w++)
			{
				// print trailing spaces at given height.
				cout << ' ';
			}

			cout << ' ';	// space between pyramids
		}
		cout << endl;	// go to next line
	}

	return 0;
}
