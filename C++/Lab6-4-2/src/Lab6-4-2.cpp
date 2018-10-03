//============================================================================
// Name        : Lab6-4-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Interfaces and virtual functions: part 2
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};


class ExactValidator : public StringValidator {
private:
	string secret;
public:
	ExactValidator(string s){secret = s;}

	bool isValid(std::string input);
};


bool ExactValidator::isValid(std::string input)
{
	if (secret.compare(input) == 0)
	{
		return true;
	}

	// else
	return false;
}

class MinLengthValidator : public StringValidator {
private:
	int reqMinLength;
public:
	MinLengthValidator(int length){reqMinLength = length;}

	bool isValid(std::string input){
		if (input.length() >= (unsigned int) reqMinLength)
		{
			return true;
		}

		// else
		return false;
	}

};

class MaxLengthValidator : public StringValidator {
private:
	int reqMaxLength;
public:
	MaxLengthValidator(int length){reqMaxLength = length;}

	bool isValid(std::string input){
		if (input.length() <= (unsigned int) reqMaxLength)
		{
			return true;
		}

		// else
		return false;
	}

};

class PatternValidator : public StringValidator {
private:
	string pattern;
public:
	PatternValidator(string pattern){this->pattern = pattern;}

	bool isValid(std::string sentence){
		bool foundMatch = true;	// set false at first mismatch
//--------------------------------------------------------
		for (unsigned int idxSenChar = 0; idxSenChar < sentence.length()-pattern.length()+1; idxSenChar++)	// loop over characters in the sentence
		{
			foundMatch = true;	// set false at first mismatch
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
//				cout << matchStr << endl;	// output matching substring.
				return true;	// at least one match is found
			}
		}
//----------------------------------------------------------
		// else
		return false;
	}

};

class DummyValidator : public StringValidator {
public:
	virtual bool isValid(std::string input);
};


bool DummyValidator::isValid(std::string input)
{
	return true;
}

void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is "
			<< (validator.isValid(input) ? "valid" : "invalid") << endl;
}


int main()
{
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	printValid(min, "hello");
	printValid(min, "welcome");
	cout << endl;
	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	printValid(max, "hello");
	printValid(max, "welcome");
	cout << endl;
	cout << "PatternValidator" << endl;
	PatternValidator digit("D");
	printValid(digit, "there are 2 types of sentences in the world");
	printValid(digit, "valid and invalid ones");
	cout << endl;	return 0;
}
