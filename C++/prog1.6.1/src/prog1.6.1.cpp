//============================================================================
// Name        : prog1.6.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	bool answer;
	int value;
	cout << "Enter a value: ";
	cin >> value;
	answer = (value >= 0 && value < 10) ||
			((2*value < 20) && (value-2 > -2)) ||
			((value-1)>1 && (value/2) < 10) ||
			(value == 111) ;
	cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
	return 0;
}
