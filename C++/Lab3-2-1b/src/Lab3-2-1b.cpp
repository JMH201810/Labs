//============================================================================
// Name        : Lab3-2-1b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13, 52, 40 };
	int n = sizeof(vector) / sizeof(vector[0]);
	// Insert your code here


	// What is sizeof?
	//cout << sizeof(vector[0]) << endl;
	//cout << sizeof(vector) << endl;

//	// How to find the smallest element?
//	int idxSmallest = 0;
//
//	for (int iCompare = idxSmallest+1; iCompare < n; iCompare++)
//	{
//		if (vector[iCompare] < vector[idxSmallest])
//		{
//			idxSmallest = iCompare;
//		}
//	}
//
//	cout << "Smallest element = " << vector[idxSmallest] << endl;

	int *p = vector;

//	cout << "p is:     " << p << endl;
//	cout << "p + 1 is: " << p+1 << endl;
//	cout << "p + 2 is: " << p+2 << endl;

//	for (int i = 0; i < n; i++)
//	{
//		cout << "p + " << i << " is: " << p+i << endl;
//	}

	cout << "*p is:     " << *p << endl;
	cout << "*(p+1) is: " << *(p+1) << endl;
	cout << "*p+1 is: " << *p+1 << endl;

	return 0;
}
