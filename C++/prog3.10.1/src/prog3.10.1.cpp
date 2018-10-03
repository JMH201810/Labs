//============================================================================
// Name        : prog3.10.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void) {
	int maxball;
	int ballsno;
	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
	srand(time(NULL));
	// Insert your code here
	if (ballsno > maxball)
	{
		cout << "Error: number of balls > max ball #.\n";
		return 1;
	}
	int* selection = new int [ballsno];

	for (int i = 0; i < ballsno; i++)
	{
		bool unique;
		int rnd = 0;
		do {
			unique = true;	// set false at first match of rnd and a previously drawn selection
			rnd = rand() % maxball + 1;
			for (int j = 0; j < i; j++)
			{
				if (rnd == selection[j])
				{
					unique = false;
					break;
				}
			}
		} while (!unique);
		selection[i] = rnd;
		cout << rnd << endl;
	}
	cout << "done\n";

	delete [] selection;
	return 0;
}
