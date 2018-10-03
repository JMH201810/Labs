//============================================================================
// Name        : prog2.11.1.cpp
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

	unsigned int duration = 0;

	do {
		cout << "Enter start time as hours (0-23) and minutes (0-59): ";
		cin >> startTime.hour >> startTime.minute;
	} while (startTime.hour > 23 || startTime.minute > 59);

	cout << "Enter duration in minutes (>=0): ";
	cin >> duration;

	endTime.hour = startTime.hour;
	endTime.minute = startTime.minute + duration;

	while (endTime.minute > 59)
	{
		endTime.minute -= 60;
		endTime.hour++;
	}

	while (endTime.hour > 23)
	{
		endTime.hour -= 24;
	}

	cout << "\nEnd time: " << endTime.hour << ':';
	if (endTime.minute < 10) cout << '0';
	cout << endTime.minute << endl;

	return 0;
}
