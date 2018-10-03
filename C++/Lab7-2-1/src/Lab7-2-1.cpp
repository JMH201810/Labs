//============================================================================
// Name        : Lab7-2-1.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: input validation.  This version catches a div by 0 exception
//============================================================================

#include <iostream>
using namespace std;
const int DivideByZero = 111;

float internaldiv(float arg1, float arg2) throw(int)
		{
	if (0==arg2)
		throw DivideByZero;
	return arg1 / arg2;
		}

float div(float arg1, float arg2) throw(int){
	//	if(arg2 == 0.0)
	//		return false;

	float r = internaldiv(arg1, arg2);

	return r;
}

int main(void) {
	float r, a, b;
	while(cin >> a) {
		cin >> b;

		try{
			r = div(a,b);
			cout << r << endl;
		}
		catch (int &iex)
		{
			cout << "Are you kidding me?" << endl;
		}


	}
	return 0;
}
