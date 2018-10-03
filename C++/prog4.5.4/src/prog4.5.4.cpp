//============================================================================
// Name        : prog4.5.4.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Text manipulation: anagrams
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "Enter two words: ";
	string word1, word2;
	cin >> word1 >> word2;

	// Determine if word1 and word2 have the same letters.  Assume all lower case letters.

	// Alphabetize characters in both words and then check whether strings are the same.

	// Bubble sort word1.
	unsigned int lenWord1 = word1.length();
	if (lenWord1 > 1)
	{
		for (unsigned int ulim = lenWord1-1; ulim > 0; ulim--)	// loop over upper limit index
		{
			for (unsigned int j = 1; j <= ulim; j++)	// loop over compared character
			{
				if (word1[j-1] > word1[j])
				{
					// swap characters
					char temp = word1[j-1];
					word1[j-1] = word1[j];
					word1[j] = temp;
				}
			}
		}
	}

	cout << "First word alphabetized: " << word1 << endl;


	// Bubble sort word2.
	unsigned int lenWord2 = word2.length();
	if (lenWord2 > 1)
	{
		for (unsigned int ulim = lenWord2-1; ulim > 0; ulim--)	// loop over upper limit index
		{
			for (unsigned int j = 1; j <= ulim; j++)	// loop over compared character
			{
				if (word2[j-1] > word2[j])
				{
					// swap characters
					char temp = word2[j-1];
					word2[j-1] = word2[j];
					word2[j] = temp;
				}
			}
		}
	}

	cout << "Second word alphabetized: " << word2 << endl;

	// compare the two alphabetized words.
	if (word1.compare(word2) == 0)
	{
		// They are the same
		cout << "\nanagrams" << endl;
	}
	else
	{
		// They are not the same
		cout << "\nnot anagrams" << endl;
	}


	return 0;
}
