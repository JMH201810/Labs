//============================================================================
// Name        : 2.11.2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	struct time_s {
		unsigned int hour;
		unsigned int minute;
	};
	time_s startTime = {0,0};
	time_s endTime = {0,0};
	time_s duration = {0,0};


	do {
		cout << "Enter start time as hours (0-23) and minutes (0-59): ";
		cin >> startTime.hour >> startTime.minute;
	} while (startTime.hour > 23 || startTime.minute > 59);

	bool notLater = true;
	do {
		do {
			cout << "Enter later end time as hours (0-23) and minutes (0-59): ";
			cin >> endTime.hour >> endTime.minute;
		} while (endTime.hour > 23 || endTime.minute > 59);

		if (endTime.hour > startTime.hour)
		{
			notLater = false;

			duration.minute = 60 * (endTime.hour - startTime.hour);
			duration.minute += (endTime.minute - startTime.minute);	// may be negative (e.g. 11:59 to 12:01)
		}
		else if (endTime.hour == startTime.hour && endTime.minute > startTime.minute)
		{
			notLater = false;

			duration.minute = endTime.minute - startTime.minute;
		}
	} while (notLater);



	while (duration.minute > 59)
	{
		duration.minute -= 60;
		duration.hour++;
	}

	cout << "\nDuration: " << duration.hour << ':';
	if (duration.minute < 10) cout << '0';
	cout << duration.minute << endl;

	return 0;
}
