//============================================================================
// Name        : Lab5-3-3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Flight booking system: part 3
//============================================================================

#include <iostream>
using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	FlightBooking();
	void printStatus();
	bool createFlight(int id, int capacity);
	bool deleteFlight();
	bool reserveSeats(int number_ob_seats);
	bool canceReservations(int number_ob_seats);
	int getId() { return id; }
private:
	int id;
	int capacity;
	int reserved;
};


FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	// Save data to members according to limits
	// Prevent # reservations < 0 and > 105% of capacity
	if (reserved < 0)
	{
		reserved = 0;
	}
	else if (reserved > 105 * capacity / 100)
	{
		reserved = 105 * capacity / 100;
	}

	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}

FlightBooking::FlightBooking()
{
	id = 0; capacity = 0; reserved = 0;
}
void FlightBooking::printStatus()
{
	// print report here
	cout << "Flight " << id << " : " << reserved << "/" << capacity << "(" << 100*reserved/capacity << "%) seats reserved" << endl;
}


bool FlightBooking::createFlight(int id, int capacity)
{
	// Try to create a new empty flight.
	bool retval = false;

	if (id > 0 && capacity > 0)
	{
		this->id = id;
		this->capacity = capacity;
		this->reserved = 0;
		retval = true;
	}

	return retval;
}


bool FlightBooking::deleteFlight()
{
	// Try to remove a flight
	bool retval = false;

	if (id > 0)
	{
		this->id = 0;
		this->capacity = 0;
		this->reserved = 0;
		retval = true;
	}

	return retval;
}


bool FlightBooking::reserveSeats(int number_ob_seats)
{
	// try to add reservations and return 'true' on success
	// keep the limits in mind
	bool retval = false;

	if (reserved+number_ob_seats < 0)
	{
		retval = false;
	}
	else if (reserved+number_ob_seats > 105 * capacity / 100)
	{
		retval = false;
	}
	else
	{
		reserved += number_ob_seats;
		retval = true;
	}

	return retval;
}

bool FlightBooking::canceReservations(int number_ob_seats)
{
	// try to cancel reservations and return 'true' on success
	// keep the limits in mind
	bool retval = false;

	if (reserved-number_ob_seats < 0)
	{
		retval = false;
	}
	else if (reserved-number_ob_seats > 105 * capacity / 100)
	{
		retval = false;
	}
	else
	{
		reserved -= number_ob_seats;
		retval = true;
	}

	return retval;
}



int main() {

	FlightBooking* pBooking = new FlightBooking [10];	// create an array of 10 booking objects.

	string command = "";
	while (command != "quit")
	{


		// Print the status
		bool noFlightsInSystem = true;	// set false is some flight is found.
		for (unsigned int idx = 0; idx < 10; idx++)	// loop over booking objects
		{
			if ((pBooking+idx)->getId() > 0)
			{
				noFlightsInSystem = false;	// found a flight
				(pBooking+idx)->printStatus();
			}
		}
		if (noFlightsInSystem)
		{
			cout << "No flights in the system" << endl;
		}



		cout << "\nWhat would you like to do?: ";

		cin >> command;
		if (command.compare("add") == 0)
		{
			int id,val;
			cin >> id >> val;


			// Find which booking has this id.
			unsigned int idx;
			for (idx = 0; idx < 10; idx++)
			{
				if ((pBooking+idx)->getId() == id)
				{
					break;
				}
			}
			if (idx >= 10)
			{
				cout << "Cannot perform this operation: flight " << id << " not found" << endl;
			}


			if (idx < 10)
			{
				// a matching flight was found
				bool result = (pBooking+idx)->reserveSeats(val);
				if (!result)
				{
					cout << "Cannot perform this operation" << endl;
				}
			}
		}
		else if (command.compare("cancel") == 0)
		{
			int id,val;
			cin >> id >> val;


			// Find which booking has this id.
			unsigned int idx;
			for (idx = 0; idx < 10; idx++)
			{
				if ((pBooking+idx)->getId() == id)
				{
					break;
				}
			}
			if (idx >= 10)
			{
				cout << "Cannot perform this operation: flight " << id << " not found" << endl;
			}


			if (idx < 10)
			{
				// a matching flight was found
				bool result = (pBooking+idx)->canceReservations(val);
				if (!result)
				{
					cout << "Cannot perform this operation" << endl;
				}
			}
		}
		else if (command.compare("create") == 0)
		{
			int id,val;
			cin >> id >> val;


			// Find which booking is available.
			unsigned int idx;
			for (idx = 0; idx < 10; idx++)
			{
				if ((pBooking+idx)->getId() == 0)
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
				bool result = (pBooking+idx)->createFlight(id, val);
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


			// Find which booking has this id.
			unsigned int idx;
			for (idx = 0; idx < 10; idx++)
			{
				if ((pBooking+idx)->getId() == id)
				{
					break;
				}
			}
			if (idx >= 10)
			{
				cout << "Cannot perform this operation: flight " << id << " not found" << endl;
			}


			if (idx < 10)
			{
				// a matching flight was found
				bool result = (pBooking+idx)->deleteFlight();
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

	delete [] pBooking;

	return 0;
}
