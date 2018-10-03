//============================================================================
// Name        : prog1.7.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float a = 2.3, b=2.3, c=2.123456, d=2.123456, e=2.123456;

	cout << fixed << setprecision(1) << a << endl;
	cout << fixed << setprecision(2) << b << endl;
	cout << fixed << setprecision(6) << c << endl;
	cout << fixed << setprecision(2) << d << endl;
	cout << fixed << setprecision(0) << e << endl;

	return 0;
}
