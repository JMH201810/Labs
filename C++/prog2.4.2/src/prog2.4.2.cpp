//============================================================================
// Name        : prog2.4.2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	unsigned short int val;
	bool ispalindrome = false;
	int count = 0;	// count of total number of palindromes.
	for (unsigned long i = 0; i < 65536; i++)
	{
		val = (unsigned short) i;
		//	cout << "value = ";
		//	cin >> val;
		// Insert your code here
		unsigned short highMask = 0x8000;
		unsigned short lowMask = 0x1;
		unsigned short valShiftLeft = val;	// this copy is shifted left one bit at a time
		unsigned short valShiftRight = val;	// this one goes right...
		ispalindrome = true;	// start true and set false at first mismatch
		for (int i = 0; i < 8; i++)	// loop over half of the bits in val
		{
			bool hasHighOne = valShiftLeft & highMask;
			bool hasLowOne = valShiftRight & lowMask;
			if ((hasHighOne && !hasLowOne) || (!hasHighOne && hasLowOne))
			{
				ispalindrome = false;
				break;
			}
			valShiftLeft <<= 1;
			valShiftRight >>= 1;
		}


		if(ispalindrome)
		{
			//cout << val << " is a bitwise palindrome" << endl;
			count++;
		}
		else
		{
			//cout << val << " is not a bitwise palindrome" << endl;
		}
	}

	cout << "Total number of 16-bit palindromes: " << count << endl;


	return 0;
}
