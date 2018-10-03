//============================================================================
// Name        : Lab7-1-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: divide by zero
//============================================================================

#include <iostream>
using namespace std;
int main(void) {
	int a = 0, b = 0, c = 0;
	bool OK;
	do {
		OK = true;
		try {
			cout << "Enter b: "; cin >> b;
			if (b == 0)
			{
				throw string("b == 0");
			}
			cout << "Enter a: "; cin >> a;
		}
		catch (string &s)
		{
			cout << s << endl;
			cout << "divisor b must be <> 0." << endl;
			OK = false;
		}
	} while (!OK);
	c = a / b;
	cout << "b / a = " << c << endl;
	cin >> a;
	return 0;
}
