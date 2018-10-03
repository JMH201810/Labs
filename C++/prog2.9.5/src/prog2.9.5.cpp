//============================================================================
// Name        : prog2.9.5.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {


	double matrix[][4] = { { 1, 2, 3, 4 },
	{ 2, 2, 3, 1 },
	{ 3, 3, 3, 2 },
	{ 4, 1, 2, 4 } };
	int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	bool issymmetric = true;
	// Insert your code here

	for (int i = 0; i < side-1; i++)	// loop over rows
	{
		for (int j = i+1; j < side; j++)	// loop over columns
		{
			if (matrix[i][j] != matrix[j][i])
			{
				issymmetric = false;
				break;	// leave inner loop
			}
		}
		if (!issymmetric) break;	// leave outer loop
	}


	if(issymmetric)
	cout << "The matrix is symmetric" << endl;
	else
	cout << "The matrix is not symmetric" << endl;

	return 0;
}
