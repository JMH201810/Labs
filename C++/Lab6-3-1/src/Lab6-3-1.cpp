//============================================================================
// Name        : Lab6-3-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Polymorphism: part 1
//============================================================================

#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw (){}
	virtual ~Base(){}
};

class A : public Base {
public:
	void draw() {
		cout << " /\\" << endl;
		cout << "//\\\\" << endl;
	}
};

class B : public Base {
public:
	void draw() {
		cout << " /\\" << endl;
		cout << "/**\\" << endl;
	}
};

class C : public Base {
public:
	void draw() {
		cout << " /\\" << endl;
		cout << "/++\\" << endl;
	}
};

int main() {
	Base* p[3];

	p[0] = new A;
	p[1] = new B;
	p[2] = new C;

	for (int i = 0; i < 3; i++)
	{
		cout << "Drawing " << (i+1) << ":\n";
		p[i]->draw();
	}


	for (int i = 2; i >=0 ; i--)
	{
		delete p[i];
	}

	return 0;
}
