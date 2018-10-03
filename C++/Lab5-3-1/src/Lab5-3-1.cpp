//============================================================================
// Name        : Lab5-3-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Flight booking system: part 1
//============================================================================

#include <iostream>
using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
private:
	int id;
	int capacity;
	int reserved;
};

void FlightBooking::printStatus()
{
	// print report here
	cout << "Flight " << id << " : " << reserved << "/" << capacity << "(" << 100*reserved/capacity << "%) seats reserved" << endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	// Save data to members
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}

int main() {
	int reserved = 0,
			capacity = 0;
	std::cout << "Provide flight capacity: ";
	std::cin >> capacity;
	std::cout << "Provide number of reserved seats: ";
	std::cin >> reserved;
	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
	return 0;
}
