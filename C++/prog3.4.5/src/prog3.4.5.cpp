//============================================================================
// Name        : prog3.4.5.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};
Date today(void) {
	// Insert your code here

	Date retDate = { };

	time_t t = time(NULL);
	tm tl = *localtime(&t);

	retDate.year = tl.tm_year + 1900;
	retDate.month = tl.tm_mon + 1;
	retDate.day = tl.tm_mday;

	return retDate;
}
int main(void) {
	Date t = today();
	cout << t.year << "-" << t.month << "-" << t.day << endl;
	return 0;
}
