//============================================================================
// Name        : prog4.4.1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int letterCount[26] = { };

	// Input the string.
	string inputLine;
	cout << "Enter the string:" << endl;
	getline(cin, inputLine);

	// Convert any upper case characters to lower case.
	int length = inputLine.length();
	for (int i = 0; i < length; i++)
	{
		if (inputLine[i] >= 'A' && inputLine[i] <= 'Z')
		{
			inputLine[i] += 'a' - 'A';
		}
	}


	// Identify characters
	for (int i = 0; i < length; i++)
	{
		char ch = inputLine[i];
		if (ch >= 'a' && ch <= 'z')
		{
			letterCount[ch-'a']++;
		}
	}

	// is it a pangram?
	bool isPangram = true;
	for (int i = 0; i < 26; i++)
	{
		if (letterCount[i] == 0)
		{
			isPangram = false;
			break;
		}
	}


	// output results
	cout << (isPangram?"Pangram":"Not pangram") << endl;
	char outCh;
	for (int i = 0; i < 26; i++)
	{
		outCh = (char) i + 'a';
		cout << outCh << "-" << letterCount[i] << endl;
	}

	return 0;
}
