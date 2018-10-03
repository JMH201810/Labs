//============================================================================
// Name        : Lab5-3-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Flight booking system: part 2
//============================================================================

#include <iostream>
using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool canceReservations(int number_ob_seats);
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

void FlightBooking::printStatus()
{
	// print report here
	cout << "Flight " << id << " : " << reserved << "/" << capacity << "(" << 100*reserved/capacity << "%) seats reserved" << endl;
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
	int reserved = 0,
			capacity = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	string command = "";
	while (command != "quit")
	{
		booking.printStatus();
		cout << "\nWhat would you like to do?: ";
//		getline(cin,command);
		// handle the command

		cin >> command;	// using cin is simpler.
		if (command.compare("add") == 0)
		{
			int arg;
			cin >> arg;
			bool result = booking.reserveSeats(arg);
			if (!result)
			{
				cout << "Cannot perform this operation" << endl;
			}
		}
		else if (command.compare("cancel") == 0)
		{
			int arg;
			cin >> arg;
			bool result = booking.canceReservations(arg);
			if (!result)
			{
				cout << "Cannot perform this operation" << endl;
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

	return 0;
}
