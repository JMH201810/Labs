//============================================================================
// Name        : Lab3-4-1b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool isLeap(int year) {
	// Insert your code here
	bool retval = false;

	if (year >= 1582)
	{
		if (year %4 != 0)
		{
			// change this to setting retval cout << "Common year\n";
		}
		else
		{
			if (year % 100 != 0)
			{
				// change this to setting retval   cout << "Leap year\n";
			}
			else
			{
				if (year % 400 != 0)
				{
					// change this to setting retval   cout << "Common year\n";
				}
				else
				{
					// change this to setting retval   cout << "Leap year\n";
				}
			}
		}
	}
	else
	{
		//cout << "Invalid year\n";
		// set retval accordingly.
	}


	return retval;
}


int main(void) {
	for(int yr = 1995; yr < 2017; yr++)
		cout << yr << " -> " << isLeap(yr) << endl;
	return 0;
}
