//============================================================================
// Name        : Lab7-1-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: input validation
//============================================================================

#include <iostream>
using namespace std;
int main(void) {
	int a = 8, b = 0, c = 0;
	bool inputOK = true;
	do {
		inputOK = true;
		cout << "Enter b: ";
		cin >> b;
		try {
			//Your code here
			if (b == 0)
			{
				throw string("division by zero.");
			}
			c = a / b;
		}
		catch (string &s)
		{
			cout << "Input invalid: value should be <> 0." << endl;
			inputOK = false;
		}
	} while (!inputOK);
	// Your code here
	cout << c << endl;
	return 0;
}
