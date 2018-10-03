//============================================================================
// Name        : prog1.7.3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int a,b,c,d;
	cout << "Enter four integers:" << endl;
	cin >>a;
	cin >> b;
	cin >> c;
	cin >> d;
	if (a > 0 && a < 256 && b > 0 && b < 256 && c > 0 && c < 256 && d > 0 && d < 256) {
		cout << a << "."<< b << "."<< c << "."<< d << endl;
	} else {
		cout << "Invalid input.\n";
	}
	return 0;
}
