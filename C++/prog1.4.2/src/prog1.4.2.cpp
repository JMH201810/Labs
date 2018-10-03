//============================================================================
// Name        : prog1.4.2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	float pi = 3.14159265359;
	float x,y;
	cout << "Enter value for x: ";
	cin >> x;
	// put your code here
	y = 1 +(x * x / (pi * pi * (x * x - 0.5)*(x * x - 0.5)));
	y *= x * x / (pi * pi * (x*x+0.5));
	cout << "y = " << y << endl;
	return 0;
}
