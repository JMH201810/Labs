//============================================================================
// Name        : Lab6-3-3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Polymorphism: part 3
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

class IPAddressChecked : public IPAddress {
private:
	bool isCorrect;
public:
	IPAddressChecked():IPAddress(){
		isCorrect = false;
	}
	IPAddressChecked(IPAddressChecked const &a):IPAddress(a){
		isCorrect = a.isCorrect;
	}
	void print(){
		cout << address[0] << "." << address[1] << "." << address[2] << "." << address[3];
		cout << " - " << (isCorrect ? "Correct" : "Not Correct") << endl;
	}

	void setval(unsigned int* a)
	{
		address[0] = a[0];
		address[1] = a[1];
		address[2] = a[2];
		address[3] = a[3];
		isCorrect = true;
		for (int idxSeg = 0; idxSeg < 4; idxSeg++)
		{
			if (a[idxSeg] > 255)
			{
				isCorrect = false;
				break;
			}
		}
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
	IPAddress* p[3];
	p[0] = new IPAddress;
	p[1] = new IPAddressChecked;
	p[2] = new IPAddressChecked;

	unsigned int a[4];
	string input;

	cout << "Enter an IP address: ";
	getline(cin, input);
	parseAddress(input, a);
	p[0]->setval(a);

	cout << "Enter an IP address to be checked: ";
	getline(cin, input);
	parseAddress(input, a);
	//static_cast<IPAddressChecked*>(p[1])->setval(a);
	p[1]->setval(a);

	cout << "Enter an IP address to be checked: ";
	getline(cin, input);
	parseAddress(input, a);
	//static_cast<IPAddressChecked*>(p[2])->setval(a);
	p[2]->setval(a);


	p[0]->print();
//	static_cast<IPAddressChecked*>(p[1])->print();
//	static_cast<IPAddressChecked*>(p[2])->print();
	p[1]->print();
	p[2]->print();



	delete p[2];
	delete p[1];
	delete p[0];
	return 0;
}
