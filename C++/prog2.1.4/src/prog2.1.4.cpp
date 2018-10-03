//============================================================================
// Name        : prog2.1.4.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int year, month, day;
	int dayOfWeek; // (0 = Sunday, 1 = Monday,...)
	bool isLeapYear;

	// Input year, month, day
	cout << "Enter date, year-month-day" << endl;

	// Input year
	do {
	cout << "Year (1900 - 2099): ";
	cin >> year;
	} while (year < 1900 || year > 2099);

	// Input month
	do {
		cout << "Month (1 - 12): ";
		cin >> month;
	} while (month < 1 || month > 12);

	// Input day
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		// 31-day months
		do {
			cout << "Day (1 - 31) : ";
			cin >> day;
		} while (day < 1 || day > 31);
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		// 30-day months
		do {
			cout << "Day (1 - 30) : ";
			cin >> day;
		} while (day < 1 || day > 30);
		break;

	case 2:
		// February
		// is it a leap year or not?
		if (year %4 != 0)
		{
			isLeapYear = false;
		}
		else
		{
			if (year % 100 != 0)
			{
				isLeapYear = true;
			}
			else
			{
				if (year % 400 != 0)
				{
					isLeapYear = false;
				}
				else
				{
					isLeapYear = true;
				}
			}
		}

		if (isLeapYear)
		{
			// 29-day month
			do {
				cout << "Day (1 - 29) : ";
				cin >> day;
			} while (day < 1 || day > 29);
		}
		else
		{
			// 28-day month
			do {
				cout << "Day (1 - 28) : ";
				cin >> day;
			} while (day < 1 || day > 28);
		}
		break;

	default:
		cout << "Invalid month value.\n";
	}



	// Calculate day of week via Zeller's congruence.
	month -= 2;	// decrease month number by 2

	// if month number becomes less than or equal to 0, increment it by 12 and decrement year by 1
	// NOTE: the lab assignment incorrectly states if month < 0, not month <= 0.  Notify students accordingly.
	if (month <= 0)
	{
		month += 12;
		year--;
	}

	// take month number and multiply it by 83 and divide it by 32
	month *= 83;
	month /= 32;

	// add day number to month
	month += day;

	// add year number to month
	month += year;

	// add year/4 to month
	month += year/4;

	// subtract year/100 from month
	month -= year/100;

	// add year/400 to month
	month += year/400;

	// find the remainder of dividing month by 7
	dayOfWeek = month % 7;

	cout << "Day of week: " << dayOfWeek << endl;





	return 0;
}
