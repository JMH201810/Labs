//============================================================================
// Name        : prog2.1.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int year;
	cout << "Enter a year: ";
	cin >> year;
	// Insert your code here
	if (year >= 1582)
	{
		if (year %4 != 0)
		{
			cout << "Common year\n";
		}
		else
		{
			if (year % 100 != 0)
			{
				cout << "Leap year\n";
			}
			else
			{
				if (year % 400 != 0)
				{
					cout << "Common year\n";
				}
				else
				{
					cout << "Leap year\n";
				}
			}
		}
	}
	else
	{
		cout << "Invalid year\n";
	}
	return 0;
}
