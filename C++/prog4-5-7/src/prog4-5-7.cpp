//============================================================================
// Name        : prog4-5-7.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Text manipulation: password validation: 1 day
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "Password requirements:\n1. Must be eight characters long\n2. Must have at least one upper-case letter\n"
			<< "3. Must have at least one lower-case letter\n4. Must have at least one digit\n"
			<<"5. Must have at least one special character (!\"#$%&'()*+-./:;<=>?@[\\]^_`{|}~\n\n";

	string password;
	do {
		cout << "Enter the password: ";
		getline(cin, password);
	} while(password.length() < 1);


	// Requirements pass flags
	bool pass8CharsLong = false;	// must be eight characters long
	bool passUCLetter = false;		// must have at least one upper-case letter
	bool passLCLetter = false;		// must have at least one lower-case letter
	bool pass1Digit = false;		// must have at least one digit
	bool pass1SpecChar = false;		// must have at least one special character

	// Test if at least eight characters long
	if (password.length() >= 8)
	{
		pass8CharsLong = true;	// passes requirement to be at least 8 chars long
	}

	// Test if at least one char is upper-case letter
	for (unsigned int idx = 0; idx < password.length(); idx++)
	{
		if (password[idx] >= 'A' && password[idx] <= 'Z')
		{
			passUCLetter = true;	// passes requirement to have at least one upper-case letter.
			break;	// no need to look farther.
		}
	}

	// Test if at least one char is lower-case letter
	for (unsigned int idx = 0; idx < password.length(); idx++)
	{
		if (password[idx] >= 'a' && password[idx] <= 'z')
		{
			passLCLetter = true;	// passes requirement to have at least one lower-case letter.
			break;	// no need to look farther.
		}
	}

	// Test if at least one char is digit
	for (unsigned int idx = 0; idx < password.length(); idx++)
	{
		if (password[idx] >= '0' && password[idx] <= '9')
		{
			pass1Digit = true;	// passes requirement to have at least one digit.
			break;	// no need to look farther.
		}
	}

	// Test if at least one char is special
	for (unsigned int idx = 0; idx < password.length(); idx++)
	{
		if ((password[idx] >= '!' && password[idx] <= '/')
				|| (password[idx] >= ':' && password[idx] <= '>')
				|| (password[idx] == '@')
				|| (password[idx] >= '[' && password[idx] <= '`')
				|| (password[idx] >= '{' && password[idx] <= '~'))
		{
			pass1SpecChar = true;	// passes requirement to have at least one special char.
			break;	// no need to look farther.
		}
	}


	// Test flags and output result.
	cout << '\n';
	if (pass8CharsLong && passUCLetter && passLCLetter && pass1Digit && pass1SpecChar)
	{
		cout << "The password is valid" << endl;
	}
	else
	{
		if (!pass8CharsLong)
		{
			cout << "The password must be at least 8 characters long" << endl;
		}
		if (!passUCLetter)
		{
			cout << "The password must have at least one upper-case letter" << endl;
		}
		if (!passLCLetter)
		{
			cout << "The password must have at least one lower-case letter" << endl;
		}
		if (!pass1Digit)
		{
			cout << "The password must have at least one digit" << endl;
		}
		if (!pass1SpecChar)
		{
			cout << "The password must have at least one special character" << endl;
		}
	}



	return 0;
}
