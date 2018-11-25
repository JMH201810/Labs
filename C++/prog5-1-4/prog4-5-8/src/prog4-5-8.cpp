//============================================================================
// Name        : prog4-5-8.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Text manipulation: templates: 2-days
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct _entry {
	string key;
	string value;
};

int main() {
	string values;	// a list of name value pairs separated by commas. Each pair should be in the following form: "name=value".
	string templ;	// a template that should be filled with the values from the first line. A placeholder should have the form "[name]" and should be replaced by an appropriate value.

	// If this program encounters a placeholder with an unknown name, the placeholder should be left unprocessed in the output text.

	do {
		cout << "Enter values string: ";
		getline(cin, values);
	} while (values.length() < 1);

	do {
		cout << "Enter template string: ";
		getline(cin, templ);
	} while (templ.length() < 1);








	// Declare a pointer to an _entry object
	_entry* pDictionary = NULL;

	// Find out how many key-value pairs are in the values string.
	unsigned int numKeyValPairs = 0;
	for (unsigned int idx = 0; idx < values.length(); idx++)
	{
		if (values[idx] == '=')
		{
			numKeyValPairs++;
		}
	}

	if (numKeyValPairs > 0)
	{
		// Allocate the dictionary
		pDictionary = new _entry[numKeyValPairs];
	}





	// Use a state machine to input key-value pairs from values string.
	int state = 0;
	int idxEntry = 0;	// index into dictionary array
	for (unsigned int idx = 0; idx < values.length(); idx++)
	{
		switch (state)
		{
		case 0:	// inputting key
			if (values[idx] == '=')
			{
				// done inputting key.  Switch state to inputting value.
				state = 1;
			}
			else
			{
				// This character is appended to the current key string.
				pDictionary[idxEntry].key.append(values.substr(idx,1));
			}
			break;

		case 1:	// inputting value
			if (values[idx] == ',')
			{
				// done inputting value.  Switch state to inputting key.
				state = 0;
				// Advance the index into the dictionary array.
				idxEntry++;
			}
			else
			{
				// This character is appended to the current value string.
				pDictionary[idxEntry].value.append(values.substr(idx,1));
			}
			break;
		}

	}




	// Process the template, using a state machine
	state = 0;
	string key = "";
	for (unsigned int idx = 0; idx < templ.length(); idx++)
	{
		switch (state)
		{
		case 0:	// inputting general text.
			if (templ[idx] == '[')
			{
				// switch to inputting key
				state = 1;
			}
			else
			{
				// general text input: output it.
				cout << templ[idx];
			}
			break;

		case 1:	// inputting key
			if (templ[idx] == ']')
			{
				// done inputting key: switch to general text input and process the key.
				state = 0;



				// find a match for the current key in the dictionary.
				bool foundMatch = false;	// set true if a matching key is found in the dictionary
				if (pDictionary != NULL)
				{
					for (unsigned idxEntry = 0; idxEntry < numKeyValPairs; idxEntry++)
					{
						if (pDictionary[idxEntry].key.compare(key) == 0)
						{
							// A match is found: output the corresponding value.
							cout << pDictionary[idxEntry].value;
							foundMatch = true;	// flag that a match is found.
							break;	// leave this loop over dictionary elements.
						}
					}
				}

				if (!foundMatch)
				{
					// no matching key was found in the dictionary
					// output the key with square brackets.
					cout << '[' << key << ']';
				}

				// Empty the key string.
				key.erase();
			}
			else
			{
				// append this character to the currently building key
				key.append(templ.substr(idx,1));
			}
			break;
		}
	}




	if (pDictionary != NULL)
	{
		delete [] pDictionary;
		pDictionary = NULL;
	}

	return 0;
}
