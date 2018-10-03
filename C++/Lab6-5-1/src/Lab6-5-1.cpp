//============================================================================
// Name        : Lab6-5-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Composition: part 1
//============================================================================

#include <iostream>
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

bool parseAddress(string input, unsigned int* a)
{
	for (int i = 0; i < 3; i++){
		unsigned int idx = input.find('.');
		if (idx == string::npos) return false;
		string seg = input.substr(0,idx);
		input.erase(0,idx+1);
		a[i] = stoi(seg);
	}
	a[3] = stoi(input);
	return true;
}


int main() {
	unsigned int a[4];
	string input;

	IPAddress* p[5];
	p[0] = new IPAddress;
	p[1] = new IPAddress;
	p[2] = new IPAddress;
	p[3] = new IPAddress;
	p[4] = new IPAddress;

	for (int i = 0; i < 5; i++){
		cout << "Enter an IP address: ";
		getline(cin, input);
		parseAddress(input, a);
		p[i]->setval(a);
	}

	Network* n[2];
	n[0] = new Network;
	n[1] = new Network;

	n[0]->push_back(*p[0]);
	n[0]->push_back(*p[1]);
	n[0]->push_back(*p[2]);

	n[1]->push_back(*p[2]);
	n[1]->push_back(*p[3]);
	n[1]->push_back(*p[4]);

	n[0]->printNetwork("1");
	n[1]->printNetwork("2");



	delete n[1];
	delete n[0];
	delete p[4];
	delete p[3];
	delete p[2];
	delete p[1];
	delete p[0];

	return 0;
}
