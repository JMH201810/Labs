//============================================================================
// Name        : Lab7-2-4.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: simple checks
//============================================================================

#include <iostream>
using namespace std;

class GuardInt {
private:
	int value;
	const int upperlimit;
	const int lowerlimit;
public:
	GuardInt(int v): upperlimit(1000), lowerlimit(-1000) {
		set_Value(v);
	}

	void set_Value(int v) throw (string){
		if (v > upperlimit) throw string ("Attempting to set value above upper limit.");
		if (v < lowerlimit) throw string ("Attempting to set value below lower limit.");

		value = v;
	}

	int get_Value() const {
		return value;
	}

	void add(GuardInt &g) throw (string){
		// Add the input value v to the object value value.
		if (g.value > upperlimit) throw string ("Attempting to use value above upper limit.");
		if (g.value < lowerlimit) throw string ("Attempting to use value below lower limit.");
		if (g.value+value > upperlimit) throw string ("Attempting to calculate sum above upper limit.");
		if (g.value+value < lowerlimit) throw string ("Attempting to calculate sum below lower limit.");

		value += g.value;
	}

	void subtract(GuardInt &g) throw (string){
		// Subtract the input value v from the object value value.
		if (g.value > upperlimit) throw string ("Attempting to use value above upper limit.");
		if (g.value < lowerlimit) throw string ("Attempting to use value below lower limit.");
		if (value-g.value > upperlimit) throw string ("Attempting to calculate difference above upper limit.");
		if (value-g.value < lowerlimit) throw string ("Attempting to calculate difference below lower limit.");

		value -= g.value;
	}
};




int main() {
	cout << "Enter two integers: " << endl;

	GuardInt *A, *B;
	int a;

	bool valueOK;
	do {
		valueOK = true;
		try {
			cout << "Enter the first integer:" << endl;
			cin >> a;
			A = new GuardInt(a);
		}
		catch (string &s) {
			cout << "Exception while creating GuardInt object: " << s << endl;
			valueOK = false;
			cout << "Re-enter the integer." << endl;
		}
	} while (!valueOK);



	do {
		valueOK = true;
		try {
			cout << "Enter the second integer:" << endl;
			cin >> a;
			B = new GuardInt(a);
		}
		catch (string &s) {
			cout << "Exception while creating GuardInt object: " << s << endl;
			valueOK = false;
			cout << "Re-enter the integer." << endl;
		}
	} while (!valueOK);




	// Add the values
	try {
		A->add(*B);
		cout << "Result of addition: " << A->get_Value() << endl;
		A->subtract(*B);	// return to original value of A
	}
	catch (string &s)
	{
		cout << "Exception while adding GuardInt values: " << s << endl;
	}




	// Subtract the values
	try {
		A->subtract(*B);
		cout << "Result of subtraction: " << A->get_Value() << endl;
	}
	catch (string &s)
	{
		cout << "Exception while subtracting GuardInt values: " << s << endl;
	}


	if (A != nullptr) delete A;
	if (B != nullptr) delete B;

	return 0;
}
