//============================================================================
// Name        : Lab7-2-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: catch block
//============================================================================

#include <iostream>
using namespace std;
//add your own exception class here
class ExBadSquare {
	string msg;
public:
	ExBadSquare(string s):msg(s) {

	}
	string showMsg(){return msg;}
};
class ExBadRectangle {
	string msg;
public:
	ExBadRectangle(string s):msg(s) {

	}
	string showMsg(){return msg;}
};

//add functions code here
float square_area (float a) throw(ExBadSquare)
{
	if (a <= 0.0)
	{
		throw ExBadSquare("bad square dimensions (<=0)");
	}

	return a*a;
}

float rectangle_area (float a, float b) throw(ExBadRectangle)
{
	if (a <= 0.0 || b <= 0.0)
	{
		if (a <= 0.0 && b <= 0.0)
		{
			throw ExBadRectangle("bad rectangle dimensions (a,b <=0)");
		}
		else if (a <= 0.0)
		{
			throw ExBadRectangle("bad rectangle dimensions (a <=0)");
		}
		else
		{
			throw ExBadRectangle("bad rectangle dimensions (b <=0)");
		}
	}

	return a*b;
}


int main(void) {
	float a, b;
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;
	try
	{
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a,b);
		cout << rsquare << endl << rrectangle << endl;
	}
	catch (ExBadSquare &ex)
	{
		cout << "Input error: " << endl;
		cout << ex.showMsg() << endl;
	}
	catch (ExBadRectangle &ex)
	{
		cout << "Input error: " << endl;
		cout << ex.showMsg() << endl;
	}
	//add a suitable catch block here
	return 0;
}
