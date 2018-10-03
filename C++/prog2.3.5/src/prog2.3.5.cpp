//============================================================================
// Name        : prog2.3.5.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Draw a \"square\"" << endl;
	do
	{
		cout << "Enter n (between 2 and 20): ";
		cin >> n;
		if (n > 20)
		{
			cout << "that is too big" << endl;
		}
	} while (n < 2 || n > 20);

	cout << '+';
	for(int i = 0; i < n-2; i++)
		cout << '-';
	cout << '+' << endl;
	for(int i = 0; i < n-2; i++) {
		cout << '|';
		for(int j = 0; j < n-2; j++)
			cout << ' ';
		cout << '|' << endl;
	}
	cout << '+';
	for(int i = 0; i < n-2; i++)
		cout << '-';
	cout << '+' << endl;
	return 0;
}
