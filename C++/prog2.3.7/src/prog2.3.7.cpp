//============================================================================
// Name        : prog2.3.7.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n;
	unsigned long long f1, f2=1, f3= 1;

	cout << "Fibonacci series element value at index n.\n";

	do {
		cout << "Enter n (between 3 and 60): ";
		cin >> n;
	} while (n < 3 || n > 60);

	int i = 2;

	while (i < n)
	{
		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
		i++;	// increment element index
		//cout << i << "  " << f3 << endl;
	}

	cout << f3 << endl;

	return 0;
}
