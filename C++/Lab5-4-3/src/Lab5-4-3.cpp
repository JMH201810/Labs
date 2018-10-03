//============================================================================
// Name        : Lab5-4-3.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Singly linked list: part 3
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
	~Node();
	int value;
	Node* next;
};
Node::Node(int val) : value(val), next(nullptr)
{
	cout << "+Node" << endl;
}
Node::~Node()
{
	cout << "-Node" << endl;
}

class List
{
public:
	List();
	~List();
	void push_front(int value);
	bool pop_front(int &value);	// add & for passing by reference
	int size();
private:
	Node* head;
};
List::List() : head(nullptr)
{
}

List::~List()
{
	int value = 0;
	while (pop_front(value))
	{
		;
	}

}

int List::size(){
	// traverse the list.
	Node *p = head;
	int count = 0;
	while (p != nullptr)
	{
		count++;
		p = p->next;
	}

	return count;
}

void List::push_front(int value)
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

bool List::pop_front(int &value)
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
	List list;
	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i);
		cout << "pushed " << i << ", size: " << list.size() << endl;
	}
	cout << endl;
	for (int i = 0; i <= 3; i++)
	{
		int value;
		list.pop_front(value);
		cout << "popped " << value << ", size: " << list.size() << endl;
	}
	return 0;
}
