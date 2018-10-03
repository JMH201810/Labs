//============================================================================
// Name        : Lab5-4-6.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Singly linked list: part 6
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
// Node*
// +------+
// | tail |-->nullptr
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
//                             ^
// +------+                    |
// | tail |--------------------+
// +------+
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
	//cout << "+Node" << endl;
}
Node::~Node()
{
	//cout << "-Node" << endl;
}

class List
{
public:
	List();
	~List();
	void push_front(int value);
	bool pop_front(int &value);	// add & for passing by reference
	void push_back(int value);
	bool pop_back(int &value);	// change " to & in starter code
	int at(int index);
	void insert_at(int index, int value);
	void remove_at(int index);
	int size();
private:
	Node* head;
	Node* tail;
};

int List::at(int index)
{
	// return the value of the element at index
	Node* n = head;
	int count = 0;
	while (count < index && n != nullptr)
	{
		n = n->next;
		count++;
	}

	if (n == nullptr)
	{
		return -1;	// error: index exceeds list.
	}
	return n->value;
}

void List::insert_at(int index, int value)
{
	// insert the value at the desired index

	if (head == nullptr)
	{
		// list is empty, so push onto the front of the list
		push_front(value);
	}
	else if (index == 0)
	{	// push onto the front of the list
		push_front(value);
	}
	else if (index == size())
	{
		// inserting at the end of the list, so push onto the back of the list
		push_back(value);
	}
	else if (index > size())
	{
		// This is an error: index is too large.
		cout << "Error inserting node: index = " << index << " > size() of list = " << size() << endl;
	}
	else
	{
		// there's at least one element in list to begin with
		// and not inserting at the front or at the back.

		int count = 0;
		Node* n = head;
		Node* p = nullptr;

		while (count < index)
		{
			count++;
			p = n;
			n = n->next;
		}

		Node* new_node = new Node(value);
		p->next = new_node;
		new_node->next = n;
	}

}

void List::remove_at(int index)
{
	if (head == nullptr)
	{
		// list is empty, so this is an error
		cout << "Error: cannot remove a node from an empty list." << endl;
	}
	else if (index == 0)
	{	// removing from the start of the list.
		int value;
		pop_front(value);
	}
	else if (index == size()-1)
	{
		// removing from the end of the list.
		int value;
		pop_back(value);
	}
	else if (index >= size())
	{
		// This is an error: index is too large.
		cout << "Error removing node: index = " << index << " >= size() of list = " << size() << endl;
	}
	else
	{
		// there's at least one element in list to begin with
		// and not removing from the front or at the back.

		int count = 0;
		Node* n = head;
		Node* p = nullptr;

		while (count < index)
		{
			count++;
			p = n;
			n = n->next;
		}

		p->next = n->next;
		delete n;
	}

}



List::List() : head(nullptr), tail(nullptr)
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

bool List::pop_back(int &value)
{
	// implement me!
	// implement the pop
	// don't forget to delete the popped node!
	// and fix the return value
	if (tail != nullptr)
	{
		// there is something in the list.
		Node* popped = tail;	// get the tail

		// special case: head == tail: only one element in list and it's popped
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			// move the tail to the previous node in the list
			Node* probe = head;
			while (probe->next != tail)	// loop until element preceding the tail is found.
			{
				probe = probe->next;
			}
			tail = probe;
			tail->next = nullptr;
		}

		value = popped->value;	// get the value to return.
		delete popped;
		return true;
	}
	return false;
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
	// You need to fix this part!
	// The tail pointer needs to be modified only when the first element is added
	Node* new_head = new Node(value);
	new_head->next = head;
	//******************************************
	if (head == nullptr)
	{
		// first element is being added.
		tail = new_head;
	}
	//******************************************
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


// All of your previously written methods may require a little fixing
// START
// +------+   +-----+      +-----+
// | head |-->| X   |  +-->| Y   |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
//
// STEP 1
// new Node
// +------+   +-----+      +-----+           +-----+
// | head |-->| X   |  +-->| Y   |           | Z   |
// +------+   +-----+  |   +-----+           +-----+
//            |next |--+   |next |-->nullptr |next |-->nullptr
//            +-----+      +-----+           +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
//
// STEP 2
//
// +------+   +-----+      +-----+      +-----+
// | head |-->| X   |  +-->| Y   |  +-->| Z   |
// +------+   +-----+  |   +-----+  |   +-----+
//            |next |--+   |next |--+   |next |-->nullptr
//            +-----+      +-----+      +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
//
// STEP 3
// +------+   +-----+      +-----+      +-----+
// | head |-->| X   |  +-->| Y   |  +-->| Z   |
// +------+   +-----+  |   +-----+  |   +-----+
//            |next |--+   |next |--+   |next |-->nullptr
//            +-----+      +-----+      +-----+
//                                          ^
// +------+                                 |
// | tail |---------------------------------+
// +------+

void List::push_back(int value)
{
	// implement me!
	Node* new_tail = new Node(value);	// step 1

	if (tail == nullptr)
	{
		// first element is being added.
		head = new_tail;
	}
	else
	{
		tail->next = new_tail;			// step 2
	}

	tail=new_tail;						// step 3

}


void printList(List &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == " << list.at(i) << endl;
	}
}

int main() {
	List list;
	//
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	printList(list);
	cout << endl;
	list.remove_at(2);
	printList(list);
	cout << endl;
	list.insert_at(1, 6);
	printList(list);
	return 0;
}
