//============================================================================
// Name        : prog4.5.2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Text manipulation: find and replace
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Input three lines of text.
	// In last line, replace all occurrences of the first line with the contents of the second line.

	//---------------------------------------------------
	// Input three lines of text.
	cout << "Enter fromString: ";
	string fromString;
	getline(cin, fromString);

	cout << "Enter toString: ";
	string toString;
	getline(cin, toString);

	cout << "Enter sentence: ";
	string sentence;
	getline(cin, sentence);


	//---------------------------------------------------
	// Change all occurrences of fromString in sentence to toString.

	unsigned int idx = sentence.find(fromString);	// find the first (if any) occurrence of fromString in sentence
	while (idx != string::npos)
	{
		// an occurrence of fromString has been located at idx, in sentence.
		sentence.replace(idx, fromString.length(), toString);	// replace the found occurrence of fromString with toString.

		// update the position to commence the next search, after the end of the substring just added.
		idx += toString.length();

		// find the next (if any) occurrence of fromString in sentence.
		idx = sentence.find(fromString, idx);
	}


	cout << '\n' << sentence << endl;


	return 0;
}
