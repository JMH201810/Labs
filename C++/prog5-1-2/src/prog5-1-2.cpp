//============================================================================
// Name        : prog5-1-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Restricting access to object data
//============================================================================

#include <iostream>
#include <string>
using namespace std;
class Square
{
private:
	double side;
	double area;

public:
	Square(double side);
	// Your code here
	void print();
	void set_side(double side);
};

Square::Square(double side)
{
	this->side = side;
	this->area = side * side;
}

void Square::print()
{
	cout << "Square: side=" << side << " area=" << area << endl;
}

void Square::set_side(double side)
{
	if (side >= 0.0)
	{
		this->side = side;
		this->area = side * side;
	}
}

int main()
{
	Square s(4);
	s.print();
	s.set_side(2.0);
	s.print();
	s.set_side(-33.0);
	s.print();

	return 0;
}
