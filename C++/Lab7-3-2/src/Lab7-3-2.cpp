//============================================================================
// Name        : Lab7-3-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: checking strings
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


class Node : public IPAddress {
private:
public:
	Node* next;
	Node(IPAddress const &a):IPAddress(a){next = nullptr;}
	~Node(){}
};




class Network {
private:
	Node* tail;
	Node* head;
public:
	Network(){
		head = nullptr;
		tail = nullptr;
	}
	~Network(){	while (pop_front());}

	void printNetwork(string id){
		cout << "Network " << id << endl;

		Node* p = head;
		while (p != nullptr)
		{
			p->print();
			p = p->next;
		}
	}


	void push_back(IPAddress const &a)
	{
		Node* new_tail = new Node(a);	// step 1

		if (tail == nullptr)
		{
			// first element is being added.
			head = new_tail;
		}
		else
		{
			tail->next = new_tail;			// step 2
		}

		tail=new_tail;						// step 3

	}

	bool pop_front()
	{
		if (head != nullptr)
		{
			// there is something in the list.
			Node* popped = head;	// get the head
			head = head->next;		// move the head to the next node in the list
			delete popped;
			return true;
		}
		return false;
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
	unsigned int a[4];
	string input;
	int range;


	IPAddress *inputAddress = nullptr, *subnetMask = nullptr, *address = nullptr;


	bool rangeOK;
	bool addressOK;



	do {
		rangeOK = true;
		addressOK = true;
		cout << "Enter an IP address and a range (2-256): ";
		getline(cin, input);

		try{
			unsigned int idxSeparator = input.find(" ");

			if (idxSeparator != string::npos)
			{
				string sRange = input.substr(idxSeparator);
				range = stoi(sRange);
				if (range != 2 && range != 4 && range != 8 && range != 16 && range != 32 && range != 64 && range != 128 && range != 256)
				{
					rangeOK = false;
					throw domain_error("Invalid range value.");
				}
			}
			input.erase(idxSeparator);
		}
		catch(domain_error(&s)){
			cout << "Exception while inputting range.  " << s.what() << endl;
		}


		if (rangeOK) {
			try{
				parseAddress(input, a);
				inputAddress = new IPAddress;
				inputAddress->setval(a);
			}
			catch (domain_error &s){
				cout << "Invalid IP address: " << s.what() << endl;
				if (inputAddress != nullptr)
				{
					delete inputAddress;
					inputAddress = nullptr;
				}
				addressOK = false;
			}
		}
	} while (!rangeOK || !addressOK);


	// Make a subnet mask based on the range.
	subnetMask = new IPAddress();
	a[0] = a[1] = a[2] = 255;
	switch (range)
	{
	case 256:
		a[3] = (255 << 1) & 255;
	case 128:
		a[3] = (255 << 1) & 255;
	case 64:
		a[3] = (255 << 1) & 255;
	case 32:
		a[3] = (255 << 1) & 255;
	case 16:
		a[3] = (255 << 1) & 255;
	case 8:
		a[3] = (255 << 1) & 255;
	case 4:
		a[3] = (255 << 1) & 255;
	case 2:
		a[3] = (255 << 1) & 255;
		break;
	}

	subnetMask->setval(a);


	Network* n;
	n = new Network;

	address = new IPAddress(*inputAddress);
	address->maskAnd(*subnetMask);	// form the first address of the subnet

	n->push_back(*address);

	for (int i = 1; i < range; i++){
		address->makeNextAddress();
		n->push_back(*address);
	}

	n->printNetwork("subnet");


	delete address;
	delete n;
	delete inputAddress;

	return 0;
}
