//============================================================================
// Name        : prog5-1-3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Obtaining derived data from an object
//============================================================================

#include <iostream>
using namespace std;

class AdHocSquare
{
public:
	AdHocSquare(double side);
	void set_side(double side);
	double get_area();
	void print();
private:
	double side;
};

class LazySquare
{
public:
	LazySquare(double side);
	void set_side(double side);
	double get_area();
	void print();
private:
	double side;
	double area;
	bool side_changed;
};


AdHocSquare::AdHocSquare(double side)
{
	this->side = side;
}

void AdHocSquare::print()
{
	cout << "Square: side=" << side << " area=" << side*side << endl;
}

void AdHocSquare::set_side(double side)
{
	if (side >= 0.0)
	{
		this->side = side;
	}
}

LazySquare::LazySquare(double side)
{
	this->side = side;
	this->area = side * side;
	this->side_changed = false;
}

void LazySquare::print()
{
	if (side_changed)
	{
		area = side * side;
		side_changed = false;
	}
	cout << "Square: side=" << side << " area=" << area << endl;
}

void LazySquare::set_side(double side)
{
	if (side >= 0.0)
	{
		if (this->side != side)
		{
			side_changed = true;
		}
		this->side = side;
	}
}



int main()
{
	AdHocSquare s(4);
	s.print();
	s.set_side(2.0);
	s.print();
	s.set_side(-33.0);
	s.print();

	LazySquare r(4);
	r.print();
	r.set_side(2.0);
	r.print();
	r.set_side(-33.0);
	r.print();

	return 0;
}
