//============================================================================
// Name        : Lab5-3-4.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Gym membership management system
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Membership {
private:
	int id;			// membership id
	string name;	// member's name
	int months;		// membership duration, in months
public:
	Membership();
	void printStatus();
	bool createMember(int id, string name);	// create a new member
	bool deleteMember();				// delete member
	bool extendMembership(int delta);	// extend membership duration by delta months
	bool cancelMembership();			// set membership duration to 0 months
	int getId() {return id;}	// get the value of member's id
};

Membership::Membership()
{
	id = 0;
	name = "";
	months = 0;
}

void Membership::printStatus()
{
	// print report here
	cout << "Member " << id << " : " << name << ", subscription valid for " << months << " months" << endl;
}

bool Membership::createMember(int id, string name)
{
	bool retval = false;

	if (id > 0 && name.length() > 0)
	{
		this->id = id;
		this->name = name;
		this->months = 0;
		retval = true;
	}

	return retval;
}

bool Membership::deleteMember()
{
	bool retval = false;

	if (id > 0)
	{
		id = 0;
		name = "";
		months = 0;
		retval = true;
	}

	return retval;
}

bool Membership::extendMembership(int delta)
{
	bool retval = false;

	if (delta >= 0)
	{
		months += delta;
		retval = true;
	}

	return retval;
}

bool Membership::cancelMembership()
{
	bool retval = false;

	if (months > 0)
	{
		months = 0;
		retval = true;
	}

	return retval;
}

int main() {
	Membership* pMembership = new Membership [10];	// create an array of 10 membership objects.

	string command = "";
	while (command != "quit")
	{


		// Print the status
		bool noMembersInSystem = true;	// set false is some member is found.
		for (unsigned int idx = 0; idx < 10; idx++)	// loop over membership objects
		{
			if ((pMembership+idx)->getId() > 0)
			{
				noMembersInSystem = false;	// found a member
				(pMembership+idx)->printStatus();
			}
		}
		if (noMembersInSystem)
		{
			cout << "No members in the system" << endl;
		}



		cout << "\nWhat would you like to do?: ";

		cin >> command;

		if (command.compare("create") == 0)
		{
			int id;
			string name;
			cin >> id;
			getline(cin, name);	// may have embedded spaces


			// Find which membership is available.
			unsigned int idx;
			for (idx = 0; idx < 10; idx++)
			{
				if ((pMembership+idx)->getId() == 0)
				{
					break;
				}
			}
			if (idx >= 10)
			{
				cout << "Cannot perform this operation: no available space in queue." << endl;
			}


			if (idx < 10)
			{
				// an available queue space was found
				bool result = (pMembership+idx)->createMember(id, name);
				if (!result)
				{
					cout << "Cannot perform this operation" << endl;
				}
			}
		}
		else if (command.compare("delete") == 0)
		{
			int id;
			cin >> id;


			// Find which membership has this id.
			unsigned int idx;
			for (idx = 0; idx < 10; idx++)
			{
				if ((pMembership+idx)->getId() == id)
				{
					break;
				}
			}
			if (idx >= 10)
			{
				cout << "Cannot perform this operation: member " << id << " not found" << endl;
			}


			if (idx < 10)
			{
				// a matching membership was found
				bool result = (pMembership+idx)->deleteMember();
				if (!result)
				{
					cout << "Cannot perform this operation" << endl;
				}
			}
		}
		else if (command.compare("extend") == 0)
		{
			int id,val;
			cin >> id >> val;


			// Find which membership has this id.
			unsigned int idx;
			for (idx = 0; idx < 10; idx++)
			{
				if ((pMembership+idx)->getId() == id)
				{
					break;
				}
			}
			if (idx >= 10)
			{
				cout << "Cannot perform this operation: membership " << id << " not found" << endl;
			}


			if (idx < 10)
			{
				// a matching membership was found
				bool result = (pMembership+idx)->extendMembership(val);
				if (!result)
				{
					cout << "Cannot perform this operation" << endl;
				}
			}
		}
		else if (command.compare("cancel") == 0)
		{
			int id;
			cin >> id;


			// Find which membership has this id.
			unsigned int idx;
			for (idx = 0; idx < 10; idx++)
			{
				if ((pMembership+idx)->getId() == id)
				{
					break;
				}
			}
			if (idx >= 10)
			{
				cout << "Cannot perform this operation: membership " << id << " not found" << endl;
			}


			if (idx < 10)
			{
				// a matching flight was found
				bool result = (pMembership+idx)->cancelMembership();
				if (!result)
				{
					cout << "Cannot perform this operation" << endl;
				}
			}
		}
		else if (command.compare("quit")==0)
		{
			// do nothing here.
		}
		else
		{
			// invalid command.
			cout << "Invalid command." << endl;
		}

	}

	delete [] pMembership;

	return 0;
}
