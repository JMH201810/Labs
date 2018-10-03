//============================================================================
// Name        : Lab7-5-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: including information in exceptions
//============================================================================

#include <iostream>
#include <stdexcept>
using namespace std;

class IPAddress {
protected:
	unsigned int address [4];
public:
	IPAddress(){
		address[0] = 0;
		address[1] = 0;
		address[2] = 0;
		address[3] = 0;
	}
	IPAddress(IPAddress const &a){
		address[0] = a.address[0];
		address[1] = a.address[1];
		address[2] = a.address[2];
		address[3] = a.address[3];
	}
	virtual ~IPAddress(){}
	virtual void print(){
		cout << address[0] << "." << address[1] << "." << address[2] << "." << address[3];
		cout << endl;
	}
	virtual void setval(unsigned int* a){
		address[0] = a[0];
		address[1] = a[1];
		address[2] = a[2];
		address[3] = a[3];
	}
	void maskAnd(IPAddress const &a)
	{
		address[0] = address[0] & a.address[0];
		address[1] = address[1] & a.address[1];
		address[2] = address[2] & a.address[2];
		address[3] = address[3] & a.address[3];
	}
	void makeNextAddress()
	{
		if (address[3] < 255)
		{
			address[3]++;
		}
		else if (address[2] < 255)
		{
			address[3] = 0;
			address[2]++;
		}
		else if (address[1] < 255)
		{
			address[3] = 0;
			address[2] = 0;
			address[1]++;
		}
		else if (address[0] < 255)
		{
			address[3] = 0;
			address[2] = 0;
			address[1] = 0;
			address[0]++;
		}
		else
		{
			throw range_error("Cannot make next address.");
		}
	}
};

void parseAddress(string input, unsigned int* a);

class IPHeader {
private:
	IPAddress *sourceAddress, *destinationAddress;

public:
	IPHeader(const string &sSource, const string &sDestination){
		unsigned int a[4];
		sourceAddress = nullptr;
		destinationAddress = nullptr;

		try {
			parseAddress(sSource, a);
			sourceAddress = new IPAddress;
			sourceAddress->setval(a);
		} catch (domain_error &ex) {
			if (sourceAddress != nullptr) {delete sourceAddress; sourceAddress = nullptr;}
			cout << "Invalid IP Header - Source IP address is invalid.  " << ex.what() << endl;
			throw;
		}

		try {
			parseAddress(sDestination, a);
			destinationAddress = new IPAddress;
			destinationAddress->setval(a);
		} catch (domain_error &ex) {
			if (sourceAddress != nullptr) {delete sourceAddress; sourceAddress = nullptr;}
			if (destinationAddress != nullptr) {delete destinationAddress; destinationAddress = nullptr;}
			cout << "Invalid IP Header - Destination IP address is invalid.  " << ex.what() << endl;
			throw;
		}

	}
};

void parseAddress(string input, unsigned int* a)
{
	for (int i = 0; i < 3; i++){
		unsigned int idx = input.find('.');
		if (idx == string::npos) throw domain_error("Octet separator not found while parsing address.");
		string seg = input.substr(0,idx);
		input.erase(0,idx+1);
		a[i] = stoi(seg);
		if (a[i] > 255) throw domain_error("Octet out of range (0-255).");
	}
	a[3] = stoi(input);
	if (a[3] > 255) throw domain_error("Octet out of range (0-255).");
	return;
}


int main() {
	string input,sSource, sDestination;


	cout << "Enter source IP address, destination IP address: ";
	getline(cin, input);

	unsigned int idxSpace = input.find(" ");
	unsigned int idxComma = input.find(",");

	if (idxComma == string::npos)
	{
		if (idxSpace == string::npos)
		{
			// trouble: no separation between source and destination values found.
		}
		else
		{
			// There is no comma, but there is a space
			sSource = input.substr(0,idxSpace);
			sDestination = input.substr(idxSpace+1);
		}
	}
	else
	{
		// There is a comma separator
		sSource = input.substr(0,idxComma);
		sDestination = input.substr(idxComma+1);
	}



	// Construct an IPHeader object.
	IPHeader *ipHeader = nullptr;
	try {
		ipHeader = new IPHeader(sSource, sDestination);

		cout << "Valid IP header." << endl;

		// Possibly use ipHeader for some purpose...

	} catch (domain_error &ex)
	{
		cout << "Ending operation without using IPHeader object." << endl;
	}

	if (ipHeader != nullptr) {delete ipHeader; ipHeader = nullptr;}

	return 0;
}
