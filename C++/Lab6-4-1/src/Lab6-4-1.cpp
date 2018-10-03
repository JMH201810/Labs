//============================================================================
// Name        : Lab6-4-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Interfaces and virtual functions: part 1
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


// Write your code here
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
	DummyValidator dummy;
	printValid(dummy, "hello");
	cout << endl;
	ExactValidator exact("secret");
	printValid(exact, "hello");
	printValid(exact, "secret");
	return 0;
}
