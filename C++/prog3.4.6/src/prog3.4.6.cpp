//============================================================================
// Name        : prog.3.4.6.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num) {
	// Insert your code here
	bool itIsPrime = true;

	if (num >= 2)
	{
		int uLim = (int)sqrt((double)num);	// upper limit of possible divisors.
		for (int i = 2; i <= uLim; i++)
		{
			if (isPrime(i))
			{
				if (num % i == 0)
				{
					itIsPrime = false;
					break;
				}
			}
		}
	}
	else
	{
		itIsPrime = false;
	}

	return itIsPrime;
}

int main(void) {
	for(int i = 0; i <= 21; i++)
	if(isPrime(i))
	cout << i << " ";
	cout << endl;
	return 0;
}
