//============================================================================
// Name        : Lab7-2-1b.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: input validation.  This version catches a 0 input exception
//============================================================================

#include <iostream>
using namespace std;
const int DivideByZero = 111;
using namespace std;
float internaldiv(float arg1, float arg2)
{
	if (0==arg2)
		throw DivideByZero;
	return arg1 / arg2;
}
bool div(float &res, float arg1, float arg2) {
	if(arg2 == 0.0)
		return false;
	internaldiv(arg1, arg2);
	return true;
}
int main(void) {
	float r, a, b;
	while(cin >> a) {
		try{
			cin >> b;
			if (b == 0)
			{
				throw string("Input divisor = 0");
			}
			if(div(r,a,b))
				cout << r << endl;
			else
				cout << "Are you kidding me?" << endl;
		}
		catch (string &s) {
			cout << s << endl;
		}
	}
	return 0;
}
