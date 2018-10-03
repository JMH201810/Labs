//============================================================================
// Name        : Lab5-3-9.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Points in 2D: part 2
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class Point2D{
public:
	Point2D(double x, double y);
	//string toString();	// ignore this and assume that non-numerical characters are not embedded in the input
	//double toDouble();	// the input is just the coordinates.
	double get_x(){return x;}
	double get_y(){return y;}
	// ...
	double distanceTo(Point2D that);
private:
	double x;
	double y;
};

class Line2D{
public:
	Line2D(double slope, double y_intercept);
	Line2D(Point2D pointA, Point2D pointB);
	//string toString();	// ignore this
	double get_slope(){return slope;}
	double get_y_intercept(){return y_intercept;}
	// ...
private:
	double slope;
	double y_intercept;
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

// implement Point2D and Line2D methods
Line2D::Line2D(double slope, double y_intercept)
{
	this->slope = slope;
	this->y_intercept = y_intercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB)
{
	slope = (pointB.get_y() - pointA.get_y()) / (pointB.get_x() - pointA.get_x());
	y_intercept = pointA.get_y() - slope * pointA.get_x();
}


int main() {
	double x,y;

	cout << "Enter coordinates of first point: ";
	cin >> x >> y;
	Point2D p1(x,y);

	cout << "Enter coordinates of second point: ";
	cin >> x >> y;
	Point2D p2(x,y);

	Line2D L(p1, p2);

	cout << "Line: y = ";
	if (L.get_slope() == 0 && L.get_y_intercept() == 0)
	{
		cout << "0" << endl;
	}
	else
	{
		if (L.get_slope() != 0)
		{
			cout << L.get_slope() << "x ";
		}

		if (L.get_y_intercept() < 0)
		{
			cout << "- " << -L.get_y_intercept() << endl;
		}
		else if (L.get_y_intercept() > 0)
		{
			cout << "+ " << L.get_y_intercept() << endl;
		}
		else
		{
			// y-intercept is zero, so don't output anything.
		}
	}


	return 0;
}
