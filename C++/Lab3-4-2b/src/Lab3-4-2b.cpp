//============================================================================
// Name        : Lab3-4-2b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool isLeap(int year) {
	// The code you've inserted already
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


int monthLength(int year, int month) {
	// Insert a new code here
	int retval = 0;

	switch(month)
	{
	case 1:
	case 3:
	case 5:
		// 31-day months
		// set number of days for January, March
		// put code here...
		break;
	case 2:
		// special Feb.
		// set number of days for February
		// if it's a leap year....(call isLeap function)
		if (isLeap(year))
		{
			// set number of days for Feb on a leap year.
		}
		else
		{
			// otherwise...
			// set number of days for Feb on non-leap year.
		}
		break;
	case 4:
	case 6:
		// 30-day months
		// set number of days for April
		break;
	}

	// go here after executing a break...

	return retval;
}


int main(void) {
	for(int yr = 2000; yr < 2002; yr++) {
		for(int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr,mo) << " ";
		cout << endl;
	}
	return 0;
}
