//============================================================================
// Name        : Lab3-2-2b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int matrix[10][2] = { };// an array of 10 pointers.
	// Each one points to an array of 10 integers.


	cout << "*matrix:     "<< *matrix << endl;
	cout << "matrix[0]:   " << matrix[0] << endl;
	cout << endl;
	cout << "*(matrix+1): "<< *(matrix+1) << endl;
	cout << "matrix[1]:   " << matrix[1] << endl;
	cout << endl;
	cout << "*(matrix+1) - *matrix: " << *(matrix+1) - *matrix << endl;
	cout << "matrix[1] - matrix[0]: " << matrix[1] - matrix[0] << endl;
	cout << endl;
	//int r = **matrix;
	int* s[10] = {*matrix, *(matrix+1), *(matrix+2), *(matrix+3), *(matrix+4),
			*(matrix+5), *(matrix+6), *(matrix+7), *(matrix+8), *(matrix+9)};
	//cout << "r :  " << r << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "s["<<i<<"]: " << s[i] << endl;
	}


//	// Insert your code here
//	for (int i = 0; i < 10; i++)
//	{
//
//		for (int j = 0; j < 10; j++)
//		{
//			matrix[i][j] = (i+1) * (j+1);
//		}
//	}
//
//
//	for(int i = 0; i < 10; i++) {
//		for(int j = 0; j < 10; j++) {
//			cout.width(4);
//			cout << *(s[i]+j);
//		}
//		cout << endl;
//	}

	return 0;
}
