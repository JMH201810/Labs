//============================================================================
// Name        : prog3.2.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);
	// Insert your code here

	int *p = vector;
	int idx = 0;	// index of smallest element
	int val = 0x7fffffff;	// smallest value

	for (int i = 0; i < n; i++)
	{
		if (*(p+i) < val)
		{
			idx = i;
			val = *(p+i);
		}
	}

	cout << "Smallest value in vector is " << *(p+idx) << " at index " << idx << endl;


	return 0;
}
