//============================================================================
// Name        : Lab3-2-2c.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
//	int matrix[10][10] = { };
	int matrix[10][2] = { };

//	cout << "matrix is:       " << matrix << endl;
//	cout << "(matrix + 1) is: " << (matrix + 1) << endl;

	for (int i = 0; i < 10; i++)	// loop over rows
	{
		//cout << "(matrix + " << i << ") is: " << (matrix + i) << endl;
		for (int j = 0; j < 2; j++)	// loop over columns
		{
			//cout << "*(matrix+i) + j is: " << *(matrix+i) + j << "\t\t";
			*(*(matrix+i) + j) = i + j;
			cout << *(*(matrix+i) + j) << "\t\t";
		}
		cout << endl;
	}


//	// Insert your code here
//	for(int i = 0; i < 10; i++) {	// loop over rows
//		for(int j = 0; j < 10; j++) {	// loop over columns
//			matrix[i][j] = (i+1) * (j+1);	// change this to use pointers
//		}
//	}
//
//
//
//	for(int i = 0; i < 10; i++) {
//		for(int j = 0; j < 10; j++) {
//			cout.width(4);
//			cout << matrix[i][j];
//		}
//		cout << endl;
//	}

	return 0;
}
