//============================================================================
// Name        : Lab6-5-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Composition: part 2
//============================================================================

#include <iostream>
using namespace std;

class Component{
protected:
	string attribValue;
public:
	Component(string a):attribValue(a){}
	virtual ~Component(){}
	virtual void print()=0;
};

class Engine : public Component {
public:
	Engine(string a):Component(a){}
	void print(){cout << "Engine: " << attribValue << endl;}
};

class Wheel : public Component {
public:
	Wheel(string a):Component(a){}
	void print(){cout << "Wheel: " << attribValue << endl;}
};

class Chassis : public Component {
public:
	Chassis(string a):Component(a){}
	void print(){cout << "Chassis: " << attribValue << endl;}
};

class Light : public Component {
public:
	Light(string a):Component(a){}
	void print(){cout << "Light: " << attribValue << endl;}
};

class Body : public Component {
public:
	Body(string a):Component(a){}
	void print(){cout << "Body: " << attribValue << endl;}
};

class Car {
private:
	Engine *engine;
	Wheel *wheel[4];
	Chassis *chassis;
	Light *light[10];
	Body *body;
public:
	Car(){
		engine = new Engine("1.0");
		wheel[0] = new Wheel("16 inches");
		wheel[1] = new Wheel("16 inches");
		wheel[2] = new Wheel("16 inches");
		wheel[3] = new Wheel("16 inches");
		chassis = new Chassis("Normal");
		light[0] = new Light("Type 1");
		light[1] = new Light("Type 1");
		light[2] = new Light("Type 2");
		light[3] = new Light("Type 2");
		light[4] = new Light("Type 3");
		light[5] = new Light("Type 3");
		light[6] = new Light("Type 4");
		light[7] = new Light("Type 4");
		light[8] = new Light("Type 5");
		light[9] = new Light("Type 5");
		body = new Body("Black");
	}
	~Car(){
		delete engine;
		for (int i = 0; i < 4; i++) delete wheel[i];
		delete chassis;
		for (int i = 0; i < 10; i++) delete light[i];
		delete body;
	}
	void print(){
		engine->print();
		for (int i = 0; i < 4; i++) wheel[i]->print();
		chassis->print();
		for (int i = 0; i < 10; i++) light[i]->print();
		body->print();
	}
};

int main() {
	Car c;
	c.print();
	return 0;
}
