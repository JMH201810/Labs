//============================================================================
// Name        : prog4.5.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Input the IP address
	string address;
	cout << "Enter the IP address: ";
	getline(cin, address);


	// Separate the IP address into its parts
	string part[4];
	int lenAddress = address.length();	// number of characters in input address
	int idxChar = 0;	// index of character in input address
	int idxPart = 0;	// index of the part to create
	do {	// loop over characters in input
		if (address.compare(idxChar,1,".") == 0)	// check whether character at idxChar is a "."
		{
			// the character at position idxChar in address is "."
			idxPart++;	// advance to the next part
		}
		else
		{
			// Append the given character at position idxChar to the part[] string.
			part[idxPart].append(address,idxChar,1);
		}

		idxChar++;	// advance to the next character
	} while (idxChar < lenAddress && idxPart < 4);



	// Check for a counting error
	if (idxChar > lenAddress)	// should exit above do loop with idxChar == lenAddress.
	{
		cout << "Error in counting.\n";
		return 1;
	}


	// Should exit above do loop with idxPart == 3.
	// Check for too many parts
	if (idxPart >= 4)
	{
		// too many parts
		cout << "Too many parts." << endl;
		return 0;
	}

	// Check for too few parts
	if (idxPart < 3)
	{
		// too few parts
		cout << "Too few parts." << endl;
		return 0;
	}



	// At this point, the address is confirmed to have exactly four parts.



	// Check the length of each part
	for (idxPart = 0; idxPart < 4; idxPart++)	// loop over parts
	{
		if (part[idxPart].length() > 3)
		{
			// Too many characters in part.
			cout << "Too many characters in part" << endl;
			return 0;
		}
		else if (part[idxPart].length() < 1)
		{
			// Too few characters in part.
			cout << "Too few characters in part" << endl;
			return 0;
		}
	}



	// At this point, each of the four parts is confirmed to consist of one, two or three characters.



	// Check that each part is composed only of numerals.
	for (idxPart = 0; idxPart < 4; idxPart++)	// loop over parts
	{
		for (idxChar = 0; idxChar < (int)part[idxPart].length(); idxChar++)	// loop over characters within this part
		{
			if ((part[idxPart].compare(idxChar,1,"0") >= 0) && (part[idxPart].compare(idxChar,1,"9") <= 0))
			{
				// this character is between 0 and 9.
			}
			else
			{
				// this character is not a numeral.
				cout << "Only digits and dots allowed" << endl;
				return 0;
			}
		}
	}


	// At this point, each of the four parts is confirmed to consist of one, two or three numerals.


	// Check the numerical value of each part.
	for (idxPart = 0; idxPart < 4; idxPart++)	// loop over parts
	{
		int numValue = 0;	// numerical value of given part.

		for (idxChar = 0; idxChar < (int)part[idxPart].length(); idxChar++)	// loop over characters within this part
		{
			numValue *= 10;	// shift to the left one digit.

			if (part[idxPart].compare(idxChar,1,"0") == 0)
			{
				numValue += 0;
			}
			else if (part[idxPart].compare(idxChar,1,"1") == 0)
			{
				numValue += 1;
			}
			else if (part[idxPart].compare(idxChar,1,"2") == 0)
			{
				numValue += 2;
			}
			else if (part[idxPart].compare(idxChar,1,"3") == 0)
			{
				numValue += 3;
			}
			else if (part[idxPart].compare(idxChar,1,"4") == 0)
			{
				numValue += 4;
			}
			else if (part[idxPart].compare(idxChar,1,"5") == 0)
			{
				numValue += 5;
			}
			else if (part[idxPart].compare(idxChar,1,"6") == 0)
			{
				numValue += 6;
			}
			else if (part[idxPart].compare(idxChar,1,"7") == 0)
			{
				numValue += 7;
			}
			else if (part[idxPart].compare(idxChar,1,"8") == 0)
			{
				numValue += 8;
			}
			else if (part[idxPart].compare(idxChar,1,"9") == 0)
			{
				numValue += 9;
			}
			else
			{
				// some kind of error.
				cout << "Only digits and dots allowed" << endl;
				return 0;
			}
		}

		if (numValue >= 0 && numValue <= 255)
		{
			// This part is OK.
		}
		else
		{
			cout << "Too big a value of a part" << endl;
			return 0;
		}

	}


	// At this point, each of the four parts is confirmed to consist of
	// one, two or three numerals and to represent numbers in the range [0, 255].

	cout << "Correct IP" << endl;


	return 0;
}
