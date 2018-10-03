//============================================================================
// Name        : prog2.3.9.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	unsigned int n;

	cout << "Find number in lower right corner of square (n x n) spiral.\n";

	do {
		cout << "Enter n (odd, between 1 and 20001): ";
		cin >> n;
	} while (n % 2 == 0 || n < 1 || n > 20001);

	int ans;
	if (n == 1)
	{
		ans = 1;
	}
	else
	{
		// central square of size (n-2)^2,
		// plus n-2 across top going straight up from last tile in central square
		// over to 1 tile to the left of the right edge
		// plus n down the right side.
		ans = (n-2)*(n-2) + 2 * (n - 1);
	}

	cout << ans << endl;

	return 0;
}
