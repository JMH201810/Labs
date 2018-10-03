//============================================================================
// Name        : rog3.4.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool isLeap(int year) {
// Insert your code here
	return (year%4==0);
}

int main() {

	for(int yr = 1995; yr < 2017; yr++)
	cout << yr << " -> " << isLeap(yr) << endl;


	return 0;
}
