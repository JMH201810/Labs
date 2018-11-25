//============================================================================
// Name        : prog4.5.6.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Text manipulation: plain-text formatting
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence;
	do {
		cout << "Enter sentence: ";
		getline(cin, sentence);
	} while (sentence.length() < 0);


	// search for special characters and if/when found, save index of this character as location to start special formatting after.

	// do this as a state machine
	int state = 0;	// reading general character

	string specFormattedStr = "";	// special formatted output string
	bool firstDoubleSpace = true;	// flag, set false after appending first double-spaced character to specFormattedStr.
	unsigned int idxOpenSpecial = 0;	// index of character that opens special formatting, either a * or a _. Used for mop up at the end.

	for (unsigned int idx = 0; idx < sentence.length(); idx++)	// loop over characters of sentence
	{
		switch (state)
		{
		case 0:	// general character handling
			if (sentence[idx] == '*')
			{
				// this is opening *
				state = 1;
				// prepare to start a new specially formatted string
				specFormattedStr = "";	// special formatted output string
				idxOpenSpecial = idx;
			}
			else if (sentence[idx] == '_')
			{
				// this is opening _
				state = 2;
				// prepare to start a new specially formatted string
				specFormattedStr = "";	// special formatted output string
				firstDoubleSpace = true;
				idxOpenSpecial = idx;
			}
			else
			{
				// normal character: output it as is.
				cout << sentence[idx];
			}
			break;

		case 1:	// have detected opening *
			if (sentence[idx] == '*')
			{
				// this is closing *
				state = 0;
				cout << specFormattedStr;	// output the specially formatted string
			}
			else if (sentence[idx] == '_')
			{
				// this is opening _.  Will disregard the opening *
				state = 2;
				// prepare to start a new specially formatted string
				specFormattedStr = "";	// special formatted output string
				firstDoubleSpace = true;
				idxOpenSpecial = idx;
			}
			else
			{
				// normal character: append an upper case version of the character to the specially formatted string
				if (sentence[idx] >= 'a' && sentence[idx] <= 'z')
				{
					// convert lower case to upper case character and append
					string add;
					add = sentence[idx]+'A'-'a';
					specFormattedStr.append(add);
				}
				else
				{
					// append non-upper case character
					specFormattedStr.append(sentence.substr(idx,1));
				}
			}
			break;

		case 2: // have detected opening _
			if (sentence[idx] == '*')
			{
				// this is opening *.  Will disregard opening _
				state = 1;
				// prepare to start a new specially formatted string
				specFormattedStr = "";	// special formatted output string
				idxOpenSpecial = idx;
			}
			else if (sentence[idx] == '_')
			{
				// this is closing _.
				state = 0;
				cout << specFormattedStr;	// output the specially formatted string
			}
			else
			{
				// normal character: output a leading space and the character.
				if (firstDoubleSpace)
				{
					// this is the first character of the double spaced string.  Don't prepend a space.
				}
				else
				{
					// this is after the first double spaced character.  Prepend a space.
					specFormattedStr.append(" ");
				}
				// in any case, clear the flag
				firstDoubleSpace = false;

				// append the character itself.
				specFormattedStr.append(sentence.substr(idx,1));
			}
			break;
		}
	}

	// If the loop ends and state = 1 or 2, there was a hanging format.  Need to just output the rest of the sentence without any special formatting.
	if (state == 1 || state == 2)
	{
		if (idxOpenSpecial < sentence.length()-1)
		{
			cout << sentence.substr(idxOpenSpecial+1);
		}
	}

	return 0;
}
