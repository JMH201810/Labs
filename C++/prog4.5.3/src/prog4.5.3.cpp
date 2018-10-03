//============================================================================
// Name        : prog4.5.3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Remove stop words from input text.
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Input a comma-delimited list of stop words.
	string stop_words;
	cout << "Enter a comma-delimited list of stop words: ";
	getline(cin, stop_words);

	// Input a sentence to process.
	string sentence;
	cout << "Enter a sentence to process: ";
	getline(cin, sentence);


	// Remove all white space from the stop word list.
	unsigned int idx = stop_words.find(" ");	// find the first occurrence, if any, of white space.
	while (idx != string::npos)
	{
		// white space found at position idx.
		// remove it
		stop_words.erase(idx,1);

		// find the next occurrence of white space, if any.
		idx = stop_words.find(" ", idx);
	}

	// Set up an array of strings to hold the stop words.
	// Find out how many stop words are in list.  It will be 1 more than the number of commas.
	// (Assuming that there are any non-comma characters in the list).
	int numCommas = 0;	// find the number of commas.
	idx = stop_words.find(",");
	while (idx != string::npos)
	{
		// a comma was found.
		// increment count
		numCommas++;

		// find the next occurrence of a comma, if any.
		idx = stop_words.find(",", idx+1);
	}

	// Set up the array of stop words
	string *arrayStopWords = new string [numCommas+1];

	int idxStopWord = 0;	// initialize index of arrayStopWords.

	// Copy stop words into this array.
	unsigned int idxStart = stop_words.find_first_not_of(",");	// find the location of the first character that is not a comma.

	// Were any non-comma characters found?
	if (idxStart != string::npos)
	{
		// at least one non-comma character was found.

		unsigned int idxEnd = 0;
		do {
			// Find the next comma
			idxEnd = stop_words.find(",", idxStart);
			int numChar = 0;	// number of characters in this stop word.

			// Get the length of the next stop word.
			// Was a comma found?
			if (idxEnd != string::npos)
			{
				// a comma was found
				numChar = idxEnd - idxStart;	// number of characters in the delimited stop word.
			}
			else
			{
				// A comma was not found.
				numChar = stop_words.length() - idxStart;	// number of characters in the last delimited word.
			}

			// Save the located stop word into the array
			if (numChar > 0 && idxStart < stop_words.length() && idxStopWord < numCommas+1)	// arguments of substr and array index must be valid.
			{
				arrayStopWords[idxStopWord] = stop_words.substr(idxStart, numChar);
				idxStopWord++;	// increment the index
			}

			// move idxStart ahead for the next stop word
			if (idxEnd != string::npos)
			{
				idxStart = idxEnd+1;
			}
		} while (idxEnd != string::npos);	// continue so long as there are more characters in stop_words.

		// At this point idxStopWord equals the actual number of stop words extracted into the array.

		int numStopWords = idxStopWord;	// just to be clear.


//		// output stop words
//		for (int i = 0; i < numStopWords; i++)
//		{
//			cout << "Stop word #" << i << ": " << arrayStopWords[i] << endl;
//		}


		// Find and remove each of the stop words from sentence.

		// First, make a copy of sentence and make all its characters lower case.  Use this for searching.
		string searchSentence = sentence;
		for (idx = 0; idx < searchSentence.length(); idx++)
		{
			if (searchSentence[idx] >= 'A' && searchSentence[idx] <= 'Z')
			{
				searchSentence[idx] += 'a' - 'A';
			}
		}



		for (idxStopWord = 0; idxStopWord < numStopWords; idxStopWord++)
		{
			idxStart = -1;
			do {	// repeatedly look for occurrences of given stop word, until none are left in sentence.
				idxStart = searchSentence.find(arrayStopWords[idxStopWord],idxStart+1);	// look in the sentence with all lower case characters

				if (idxStart != string::npos)
				{
					// Check whether this is actually a stand-alone word (as compared to a sequence of chars within another word).
					// Check the preceding character
					if (idxStart > 0 && searchSentence[idxStart-1] != ' ')
					{
						// Preceding character is not a space, so this cannot be a stop word.
						continue;	// proceed to the next cycle.
					}
					idxEnd = idxStart+arrayStopWords[idxStopWord].length()-1;
					if (idxEnd < searchSentence.length()-1 && searchSentence[idxEnd + 1] != ' ')
					{
						// Following character is not a space, so this cannot be a stop word.
						continue;	// proceed to the next cycle.
					}
					sentence.erase(idxStart, arrayStopWords[idxStopWord].length());	// remove the stop word, from both sentences.
					searchSentence.erase(idxStart, arrayStopWords[idxStopWord].length());
				}

			} while (idxStart != string::npos);
		}

		// All stop words have been removed from sentence.
		// However, there may be residual double spaces.
		// Remove them now.

		do {
			idxStart = sentence.find("  ");	// find double space
			if (idxStart != string::npos)
			{
				sentence.replace(idxStart, 2, " ");	// replace double space with single space
			}
		} while (idxStart != string::npos);


		// If there's a leading space in sentence, remove it.
		if (sentence.find(" ") == 0)
		{
			sentence.erase(0,1);	// remove first character, which is a space
		}


	}



	cout << '\n' << sentence << endl;

	delete [] arrayStopWords;

	return 0;
}
