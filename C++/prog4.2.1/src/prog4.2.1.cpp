//============================================================================
// Name        : 1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int uLim = 0;
	__int64 sum = 0;
	do {
		cout << "Enter upper limit (1-100,000): ";
		cin >> uLim;
	} while (uLim < 1 || uLim > 100000);

	for (int i = 1; i <= uLim; i++)
	{
		sum += i;
	}

	cout << sum << endl;

	return 0;
}
