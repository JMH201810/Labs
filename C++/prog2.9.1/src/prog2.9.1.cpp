//============================================================================
// Name        : prog2.9.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int vector1[7] = {4, 7, 2, 8, 1, 3, 0};
	int vector2[7];
	// Insert your code here

	for (int i = 0; i < 6; i++)
	{
		// rotate right first 6 values (move to a higher index).
		vector2[i+1] = vector1[i];
	}
	vector2[0] = vector1[6];	// get the final one

	for(int i = 0; i < 7; i++)
	cout << vector2[i] << ' ';
	cout << endl;
	return 0;
}
