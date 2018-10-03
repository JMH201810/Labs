//============================================================================
// Name        : prog3.4.3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Date {
int year;
int month;
int day;
};

bool isLeap(int year) {
	// The code you've inserted already
	return (year%4==0);
}

int monthLength(int year, int month) {
	// Insert a new code here
	int retval = 0;

	switch(month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		retval = 31;
		break;
	case 2:
		if (isLeap(year))
		{
			retval = 29;
		}
		else
		{
			retval = 28;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		retval = 30;
		break;
	default:
		retval = 0;
	}

	return retval;
}

int dayOfYear(Date date) {
// Insert your code here
	int numDays = 0;
	// Check validity of input
	if (date.month < 1 || date.month > 12)
	{
		// invalid month
		return 0;	// return error flag
	}
	else if (date.day < 1 || date.day > monthLength(date.year,date.month))
	{
		// invalid day of month
		return 0;	// return error flag
	}

	// Number of days in complete months before current one
	for (int i = 1; i < date.month; i++)
	{
		numDays += monthLength(date.year, i);
	}
	// plus number of days in current month
	numDays += date.day;
	return numDays;
}

int main() {
	Date d;
	cout << "Enter year month day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;
	return 0;
}
