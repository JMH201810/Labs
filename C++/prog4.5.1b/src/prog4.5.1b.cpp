//============================================================================
// Name        : prog4.5.1b.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence;
	cout << "Enter a sentence: ";
	getline(cin, sentence);

	// remove all duplicate white space in sentence.

	// repeatedly scan the sentence, replacing pairs of space characters with single space characters.
	int len = sentence.length();	// number of characters in input sentence.
	int pos = 0;	// starting position for looking for double-space characters.

	pos = sentence.find("  ", pos);	// find the position of the first double space in the sentence.
	while (pos != (int)string::npos && pos < len)
	{
		sentence.replace(pos,2," ",0,1);	// replace a double space with a single space.
		pos = sentence.find("  ", pos);		// find the position of the next double space in the sentence, starting at the current position.
	}

	cout << sentence << endl;

	return 0;
}
