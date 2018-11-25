//============================================================================
// Name        : prog4.5.1c.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

string nextWord(string s, unsigned int startSearchPos, unsigned int &foundPos, unsigned int &foundLen)
{
	// Looks for the next word in s, starting the search at startSearchPos.
	// Ends the search when either the end of s is reached or a space is reached.
	// Identifies the start of the word at the first location at or after startSearchPos which is not a space character.
	// This is returned as foundPos.  The number of characters from foundPos to either the end of s or the character before the next
	// space character is returned as foundLen.
	// If no next word is found, the return value is an empty string and foundPos is set equal to string::npos.

	// is s an empty string?
	if (s.length() <= 0)
	{
		// it is
		foundPos = string::npos;
		foundLen = 0;
		return "";
	}

	// At this point, s is a valid string.

	// is startSearchPos negative?
	if (startSearchPos < 0)
	{
		// it is
		foundPos = string::npos;
		foundLen = 0;
		return "";
	}

	// Is startSearchPos beyond the end of s?
	if (startSearchPos >= s.length())
	{
		// it is beyond the end of s.
		foundPos = string::npos;
		foundLen = 0;
		return "";
	}

	// At this point, startSearchPos is valid.

	// Find the beginning of a substring that does not start with a space character.
	foundPos = s.find_first_not_of(" ", startSearchPos);	// reference: http://www.cplusplus.com/reference/string/string/find_first_not_of/

	// Was a non-space character not found?
	if (foundPos == string::npos)
	{
		// no word was found.
		foundLen = 0;
		return "";
	}


	// At this point, the start of a word has been found.


	// Find the end of the word.
	// It will either be the end of s, or it will be the character before the next space character.
	unsigned int endPos = s.find(" ", foundPos);

	// Was a space character not found?
	if (endPos == string::npos)
	{
		// a space character was not found.
		// the end of the word is the end of s.
		endPos = s.length() - 1;
	}
	else
	{
		// a space character was found.
		// change endPos from pointing to the space to point to the character before it.
		endPos = endPos - 1;
	}

	// calculate length of word
	foundLen = endPos - foundPos + 1;

	// Get the string defined by these limits.
	return s.substr(foundPos, foundLen);
}

int main() {
	string sentence;
	cout << "Enter a sentence: ";
	getline(cin, sentence);

	// remove all duplicate words in sentence.

	// The sentence is composed of adjacent word pairs ... A B ...

	// If B is the same word as A, remove B and its leading space from the sentence.

	// Continue until the end of the sentence is reached.

	unsigned int startSearchPos = 0;
	unsigned int foundPos;
	unsigned int foundLen;

	string firstWord = nextWord(sentence, startSearchPos, foundPos, foundLen);

	// Was a first word found?
	if (foundPos != string::npos)
	{
		// Yes a word was found.

		startSearchPos = foundPos+foundLen;	// move forward to search for next word.


		do {
			string secondWord = nextWord(sentence, startSearchPos, foundPos, foundLen);

			// Was the next word found?
			if (foundPos != string::npos)
			{
				// Yes, the next word was found.

				// is the second word the same as the first word?
				if (firstWord.compare(secondWord) == 0)
				{
					// Yes, the two words are the same.
					// remove the second word from the sentence, including the space character that precedes it.
					sentence.erase(foundPos-1, foundLen+1);

					// get a new second word
					// don't move forward, start search in same location.
				}
				else
				{
					// No, the two words are different.
					// Put the second word in place of the first word.  Don't care what goes into the secondWord variable.
					firstWord.swap(secondWord);

					// get a new second word
					startSearchPos = foundPos+foundLen;	// move forward to search for next word.
				}
			}
		} while(foundPos != string::npos);

		// At this point, a second word has not been found, meaning that the end of the sentence is reached.
	}


	cout << sentence << endl;

	return 0;
}
