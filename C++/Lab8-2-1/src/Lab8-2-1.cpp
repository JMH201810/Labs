//============================================================================
// Name        : Lab8-2-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Enums: representing values
//============================================================================

#include <iostream>
#include <stdexcept>
using namespace std;

class Calendar {
	int day;
	int month;
	int year;
public:
	Calendar(int d, int m, int y):day(d),month(m),year(y){
		if (y < 1970) throw string("Input date is before 1-Jan-1970.");
		if (m <= 0 || m > 13) throw domain_error("Invalid month value.");
		if (d <= 0) throw domain_error("Invalid day value.");
		bool isLeapYear = false;
		switch (m)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d > 31) throw domain_error("Invalid day value.");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (d > 30) throw domain_error("Invalid day value.");
			break;
		case 2:
			isLeapYear = (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
			if (isLeapYear && d > 29) throw domain_error("Invalid day value.");
			if (!isLeapYear && d > 28) throw domain_error("Invalid day value.");
			break;
		default:
			 throw domain_error("Invalid month value.");
		}
	}

	void print(){
		enum DayOfWeek {SUNDAY,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY};
		enum Month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
		string sDay[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		string sMonth[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		bool isLeapYear;
		int numDays = 0;
		for (int idxYear = 1970; idxYear < year; idxYear++)	// add total days in whole years.
		{
			isLeapYear = (idxYear % 4 == 0) && (idxYear % 100 != 0 || idxYear % 400 == 0);

			if (isLeapYear){
				numDays += 366;
			}
			else {
				numDays += 365;
			}
		}

		for (int idxMonth = 1; idxMonth < month; idxMonth++)	// add total days in whole months of this year.
		{
			switch (idxMonth)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				numDays += 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				numDays += 30;
				break;
			case 2:
				isLeapYear = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
				if (isLeapYear) numDays += 29;
				else numDays += 28;
				break;
			default:
				 ;
			}
		}

		for (int idxDay = 1; idxDay < day; idxDay++)	// add total days in specified month before specified day.
		{
			numDays++;
		}

		cout << day << " " << sMonth[static_cast<Month>(month-1)] << " " << year << " - ";
		cout << sDay[static_cast<DayOfWeek>((numDays+4) % 7)];
		cout << " - " << numDays << " days since 1st January 1970." << endl;
	}
};

int main() {
	Calendar *c = nullptr;
	int day;
	int month;
	int year;
	cout << "Enter day, month, year: ";
	cin >> day >> month >> year;

	try {
		c = new Calendar(day, month, year);
	} catch (string &s) {
		cout << "Exception: " << s << endl;
	} catch (domain_error &ex) {
		cout << "Exception: " << ex.what() << endl;
	}


	if (c != nullptr) {
		try {
			cout << "\nDate entered:" << endl;
			c->print();
		} catch (string &s) {
			cout << "Exception: " << s << endl;
		}
	}

	delete c;

	cout << "\nDone." << endl;
	return 0;
}
