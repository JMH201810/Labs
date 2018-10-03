//============================================================================
// Name        : Lab8-1-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Operators: non-natural way of using
//============================================================================

#include <iostream>
using namespace std;

// An empty list:
//
// Node*
// +------+
// | head |-->nullptr
// +------+
//
//
//
// A list with two elements:
//
// Node* Node Node
// +------+   +-----+      +-----+
// | head |-->|value|  +-->|value|
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//

class Node
{
public:
	Node(int val);
	int value;
	Node* next;
};
Node::Node(int val) : value(val), next(nullptr)
{
}

class Stack
{
public:
	Stack();
	void push_front(int value);
	bool pop_front(int &value);	// add & for passing by reference
	int top () throw (string) {
		// return the top value of the stack, without removing it from the stack.
		int value;
		if (!pop_front(value))
		{
			// There is nothing on the stack.
			// throw an exception with an informative message.
			throw string("No top element on stack; stack is empty.");
		}
		else
		{
			push_front(value);
		}
		return value;
	}

	// Overloaded insertion operator
	Stack& operator<<(int value){
		// push value onto the stack.
		push_front(value);
		return *this;
	}

	// Overloaded extraction operator
	Stack& operator>>(int &value)
	{
		// pop value off of the stack
		if (!pop_front(value)) throw string ("stack is empty.");

		return *this;
	}

private:
	Node* head;
};
Stack::Stack() : head(nullptr)
{
}
void Stack::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = head;
	head=new_head;
}
// START
// +------+   +-----+      +-----+
// | head |-->| X   |  +-->| Y   |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 1
//
// +------+
// |popped|
// +------+
// |
// V
// +------+   +-----+      +-----+
// | head |-->| X   |  +-->| Y   |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 2
// +------+
// | head |-------------------+
// +------+                   |
//                            V
// +------+   +-----+      +-----+
// |popped|-->| X   |  +-->| Y   |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 3
// returned = popped->value;
// delete popped;
// +------+   +-----+
// | head |-->| Y   |
// +------+   +-----+
//            |next |-->nullptr
//            +-----+

bool Stack::pop_front(int &value)
{
	// implement the pop
	// don't forget to delete the popped node!
	// and fix the return value
	if (head != nullptr)
	{
		// there is something in the list.
		Node* popped = head;	// get the head
		head = head->next;		// move the head to the next node in the list
		value = popped->value;	// get the value to return.
		delete popped;
		return true;
	}
	return false;
}

int main() {
	Stack stack;
	int sizeStack, numPop;
	int value;

	do {
		cout << "Enter number of integers (>=0) to push onto the stack: ";
		cin >> sizeStack;
	} while (sizeStack < 0);


	cout << endl;
	for (int i = 0; i < sizeStack; i++)
	{
		cout << "Enter integer #" << i+1 << ": ";
		cin >> value;
		//stack.push_front(value);
		stack << value;
	}

	// Read the top of the stack (without removing it).
	try {
		value = stack.top();
		cout << "\nTop value on stack: " << value << endl;
	} catch (string &s) {
		cout << "\nException: " << s << endl;
	}

	// Pop specified # values from the stack.
	do {
		cout << "\nEnter number of integers (<=" << sizeStack << ") to pop from the stack: ";
		cin >> numPop;
	} while (numPop < 0);

	if (numPop > 0) cout << "\nPopped values:" << endl;
	for (int i = 0; i < numPop; i++)
	{
		try {
			//stack.pop_front(value);
			stack >> value;
			cout << value << endl;
		} catch (string &s) {
			cout << "Exception: " << s << endl;
		}

	}

	cout << "\nDone." << endl;

	return 0;
}
