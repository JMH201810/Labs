//============================================================================
// Name        : prog2.9.3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int vector[] = {0, 1, 7, 1, 1, 7, 6, 0};
	bool ispalindrome = true;
	int n = sizeof(vector) / sizeof(vector[0]);


	// Insert your code here
	ispalindrome = true;	// start true and set false at first mismatch
	for (int i = 0; i < n/2; i++)	// loop over half of the elements in vector
	{
		int lowIndex = i;
		int highIndex = n-1-i;
		if (vector[lowIndex] != vector[highIndex])
		{
			ispalindrome = false;
			break;
		}
	}



	if(ispalindrome)
		cout << "It's a palindrome";
	else
		cout << "It isn't a palindrome";
	cout << endl;


	return 0;
}
