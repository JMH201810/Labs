//============================================================================
// Name        : prog4.5.5.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Text manipulation: pattern matching
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	string pattern;
	string sentence;

	do {
		cout << "Enter the pattern: ";
		getline(cin,pattern);
	} while (pattern.length() < 1);

	do {
		cout << "Enter the sentence: ";
		getline(cin, sentence);
	} while (sentence.length() < 1);


	for (unsigned int idxSenChar = 0; idxSenChar < sentence.length()-pattern.length()+1; idxSenChar++)	// loop over characters in the sentence
	{
		bool foundMatch = true;	// set false at first mismatch
		string matchStr = "";	// accumulator for matching characters from sentence.  Init as empty string.

		for (unsigned int idxPatChar = 0; idxPatChar < pattern.length(); idxPatChar++)	// loop over characters in the pattern
		{

			if (pattern[idxPatChar] == 'D')	// look for a numerical digit
			{
				if (sentence[idxSenChar+idxPatChar] >= '0' && sentence[idxSenChar+idxPatChar] <= '9')
				{
					// sentence character is a numerical digit
					matchStr.append(sentence.substr(idxSenChar+idxPatChar,1));
				}
				else
				{
					// sentence character is not a numerical digit
					foundMatch = false;
					break;	// leave loop over pattern characters and advance to next character in sentence.
				}
			}
			else if (pattern[idxPatChar] == 'A') // look for any character of the alphabet
			{
				if ((sentence[idxSenChar+idxPatChar] >= 'A' && sentence[idxSenChar+idxPatChar] <= 'Z')
						|| (sentence[idxSenChar+idxPatChar] >= 'a' && sentence[idxSenChar+idxPatChar] <= 'z'))
				{
					// sentence character is letter of the alphabet
					matchStr.append(sentence.substr(idxSenChar+idxPatChar,1));
				}
				else
				{
					// sentence character is not a letter of the alphabet
					foundMatch = false;
					break;	// leave loop over pattern characters and advance to next character in sentence.
				}
			}
			else if (pattern[idxPatChar] >= 'a' && pattern[idxPatChar] <= 'z')	// look for this character of the alphabet
			{
				if ((sentence[idxSenChar+idxPatChar] == pattern[idxPatChar])
						|| (sentence[idxSenChar+idxPatChar] == pattern[idxPatChar] + 'A' -'a'))
				{
					// sentence character is this letter of the alphabet
					matchStr.append(sentence.substr(idxSenChar+idxPatChar,1));
				}
				else
				{
					// sentence character is not this letter of the alphabet
					foundMatch = false;
					break;	// leave loop over pattern characters and advance to next character in sentence.
				}
			}
			else if (pattern[idxPatChar] == '?')	// look for any single character
			{
				if ((sentence[idxSenChar+idxPatChar] >= ' ')
						&& (sentence[idxSenChar+idxPatChar] <= '~'))
				{
					// sentence character is any single character
					matchStr.append(sentence.substr(idxSenChar+idxPatChar,1));
				}
				else
				{
					// sentence character is not any single character
					foundMatch = false;
					break;	// leave loop over pattern characters and advance to next character in sentence.
				}
			}
			else if ((pattern[idxPatChar] >= '!' && pattern[idxPatChar] <= '/')
					|| (pattern[idxPatChar] >= ':' && pattern[idxPatChar] <= '>')
					|| (pattern[idxPatChar] == '@')
					|| (pattern[idxPatChar] >= '[' && pattern[idxPatChar] <= '`')
					|| (pattern[idxPatChar] >= '{' && pattern[idxPatChar] <= '~'))	// look for any punctuation character
			{
				if (sentence[idxSenChar+idxPatChar] == pattern[idxPatChar])
				{
					// sentence character is any punctuation character
					matchStr.append(sentence.substr(idxSenChar+idxPatChar,1));
				}
				else
				{
					// sentence character is not any punctuation character
					foundMatch = false;
					break;	// leave loop over pattern characters and advance to next character in sentence.
				}
			}
			else
			{
				// Invalid pattern character.
				foundMatch = false;
				break;	// leave loop over pattern characters and advance to next character in sentence.
			}
		}


		if (foundMatch)
		{
			// have exited pattern loop having found a match.
			cout << matchStr << endl;	// output matching substring.
		}
	}



	return 0;
}
