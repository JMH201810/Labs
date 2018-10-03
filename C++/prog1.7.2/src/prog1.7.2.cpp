//============================================================================
// Name        : prog1.7.2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int a,b;
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;

	float x = 1.0 / (float)a;
	float y = 1.0 / (float)b;
	float z = fabs(x-y);

	if (z > 0.000001)
	{
		cout << "Results are not equal (by 0.000001 epsilon)." << endl;
	}
	else
	{
		cout << "Results are equal (by 0.000001 epsilon)." << endl;
	}

	return 0;
}
