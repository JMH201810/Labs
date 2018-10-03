//============================================================================
// Name        : prog2.1.5.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int year;

	cout << "Calculate the date of Easter for a given year\n";
	cout << "Enter year: ";
	cin >> year;

	// 1. 	Divide year by 19 and find the remainder – assign it to a;
	int a = year % 19;

	// 2.	divide year by 4 and find the remainder – assign it to b;
	int b = year % 4;

	// 3.	divide year by 7 and find the remainder – assign it to c;
	int c = year % 7;

	// 4.	take a, multiply it by 19, add 24, divide by 30 and find the remainder – assign it to d
	int d = (a * 19 + 24) % 30;

	// 5.	divide	(2b + 4c + 6d + 5) by 7 and find the remainder - assign it to e;
	int e = (2 * b + 4 * c + 6 * d + 5) % 7;

	// 6.	check the value of d + e;
	if ((d+e) < 10)
	{
		// 7.	if it's less than 10, Easter falls on the (d + e + 22) day of March;
		cout << "March " << (d + e + 22) << endl;
	}
	else
	{
		// 8.	otherwise it falls on the (d + e – 9) day of April;
		cout << "April " << (d + e - 9) << endl;
	}

	return 0;
}
