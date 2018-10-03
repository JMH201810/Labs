//============================================================================
// Name        : Lab5-3-8.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Points in 2D: part 1
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class Point2D{
public:
	Point2D(double x, double y);
	//string toString();	// ignore this and assume that non-numerical characters are not embedded in the input
	//double toDouble();	// the input is just the coordinates.
	// ...
	double distanceTo(Point2D that);
private:
	double x;
	double y;
};

// implement Point2D methods
Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point2D::distanceTo(Point2D that)
{
	double dist = 0.0;

	dist = pow(x-that.x,2) + pow(y-that.y,2);
	dist = sqrt(dist);

	return dist;
}

int main() {
	double x,y;

	cout << "Enter coordinates of first point: ";
	cin >> x >> y;
	Point2D p1(x,y);

	cout << "Enter coordinates of second point: ";
	cin >> x >> y;
	Point2D p2(x,y);

	cout << "Distance = " << p1.distanceTo(p2) << endl;

	return 0;
}
