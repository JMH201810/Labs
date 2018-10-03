//============================================================================
// Name        : Lab8-4-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Operators: complex classes
//============================================================================

#include <iostream>
#include <stdexcept>
using namespace std;

class ListNode
{
public:
	ListNode(int val);
	~ListNode();
	int value;
	ListNode* next;
	ListNode* prev;		//******** new (1)
};
ListNode::ListNode(int val) : value(val), next(nullptr)
, prev(nullptr)	//******** new (5)
{
	//cout << "+Node" << endl;
}
ListNode::~ListNode()
{
	//cout << "-Node" << endl;
}

class List
{
private:
	ListNode* head;
	ListNode* tail;
public:
	List();
	List(List &other);
	~List();
	void push_front(int value);
	bool pop_front(int &value);	// add & for passing by reference
	void push_back(int value);
	bool pop_back(int &value);	// change " to & in starter code
	int at(int index) const;
	void insert_at(int index, int value);
	void remove_at(int index);
	int size() const;
	friend ostream& operator<<(ostream &os, const List &list);
};

int List::at(int index) const
{
	// Unchanged in conversion from singly to doubly linked list.

	// return the value of the element at index
	ListNode* n = head;
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
		ListNode* n = head;
		ListNode* p = nullptr;

		while (count < index)
		{
			count++;
			p = n;
			n = n->next;
		}

		ListNode* new_node = new ListNode(value);
		p->next = new_node;
		new_node->next = n;
		new_node->prev = p;	// ************ new (2)
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
		ListNode* n = head;
		ListNode* p = nullptr;

		while (count < index)
		{
			count++;
			p = n;
			n = n->next;
		}

		p->next = n->next;
		p->next->prev = p;	// ********** new (3)
		delete n;
	}

}

List::List() : head(nullptr), tail(nullptr)
{
	// Unchanged in conversion from singly to doubly linked list.

}

List::List(List &other) : head(nullptr), tail(nullptr)
{
	// Unchanged in conversion from singly to doubly linked list.


	ListNode* n = other.head;

	while (n != nullptr)
	{
		int value = n->value;
		push_back(value);
		n = n->next;
	}

}

List::~List()
{
	// Unchanged in conversion from singly to doubly linked list.

	int value = 0;
	while (pop_front(value))
	{
		;
	}

}

bool List::pop_back(int &value)
{
	// Remove an element from the back of the list and return its value

	if (tail != nullptr)
	{
		// there is something in the list.
		ListNode* popped = tail;	// get the tail

		// special case: head == tail: only one element in list and it's popped
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			// move the tail to the previous node in the list
			//			Node* probe = head;
			//			while (probe->next != tail)	// loop until element preceding the tail is found.
			//			{
			//				probe = probe->next;
			//			}
			//			tail = probe;
			tail = tail->prev;	// ************ new (4)
			tail->next = nullptr;
		}

		value = popped->value;	// get the value to return.
		delete popped;
		return true;
	}
	return false;
}

int List::size() const{
	// Unchanged in conversion from singly to doubly linked list.

	// traverse the list.
	ListNode *p = head;
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
	// Add an element to the front of the list.

	ListNode* new_head = new ListNode(value);
	new_head->next = head;
	//******************************************
	if (head == nullptr)
	{
		// first element is being added.
		tail = new_head;
	}
	else	// *********** new (7)
	{
		head->prev = new_head;
	}
	//******************************************
	head=new_head;
	head->prev = nullptr;	// ********** new (6)
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
	// Remove an element from the front of the list.

	if (head != nullptr)
	{
		// there is something in the list.
		ListNode* popped = head;	// get the head
		head = head->next;		// move the head to the next node in the list
		if (head != nullptr)		// ************ new (8)
		{
			head->prev = nullptr;	// ************ new (8)
		}
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
	// Add an element to the back of the list

	ListNode* new_tail = new ListNode(value);	// step 1

	if (tail == nullptr)
	{
		// first element is being added.
		head = new_tail;
	}
	else
	{
		tail->next = new_tail;			// step 2
	}

	new_tail->prev = tail;		// ************ new (9)
	tail=new_tail;						// step 3

}

class Node {
	// class of a node in a binary tree.
private:
	int *data;		// pointer to data associated with this node
	Node *left;		// pointer to the left child node
	Node *right;	// pointer to the right child node
public:
	Node(int *d) :
		data (d),
		left(nullptr),
		right(nullptr)
{}

	int* get_DataPtr() const {return data;}

	Node* get_LeftPtr() const {return left;}
	Node* get_RightPtr() const {return right;}
	Node** get_AddressLeftPtr() {return &left;}
	Node** get_AddressRightPtr() {return &right;}
	void set_LeftPtr( Node* p) {left = p;}
	void set_RightPtr( Node* p) {right = p;}
};



class BTree {
	// class of a binary tree.
private:
	int size;
	Node* root;
public:
	BTree() : size(0), root(nullptr) {}
	virtual ~BTree(){}

	int get_Size(){return size;}

	Node* get_RootPtr() const {return root;}

	Node* AddChildLeft(Node *parentNode, int *data){
		// Add a left child node.
		// Returns a pointer to the created child node.
		Node *new_node;
		Node **position;	// Pointer to the node pointer on the tree where the new node will be

		// Determine where to add the new node.
		if (parentNode == nullptr)
		{
			// Trying to add node at the root.
			// Allow addition at the root, only for an empty tree.
			if (size > 0)
			{
				throw string("Trying to add a node at the root of a non-empty tree.");
			}

			position = &root;
		}
		else
		{
			// Trying to add a node below the root.
			// Allow addition only at the end of a branch.
			if (parentNode->get_LeftPtr() != nullptr)
			{
				// The input node is not at the end of a branch, on the left.
				throw string("Trying to add a left child not at end of branch.");
			}

			position = parentNode->get_AddressLeftPtr();
		}


		// Allocate storage for the node
		try {
			new_node = new Node(data);
			*position = new_node;	// attach the node to the tree.
			size++;
		}
		catch (bad_alloc &ex) {
			cout << "Exception during left child node allocation: " << ex.what() << endl;
		}

		return new_node;
	}

	Node* AddChildRight(Node *parentNode, int *data){
		// Add a right child node.
		// Returns a pointer to the created child node.
		Node *new_node;
		Node **position;	// Pointer to the node pointer on the tree where the new node will be

		// Determine where to add the new node.
		if (parentNode == nullptr)
		{
			// Trying to add node at the root.
			// Allow addition at the root, only for an empty tree.
			if (size > 0)
			{
				throw string("Trying to add a node at the root of a non-empty tree.");
			}

			position = &root;
		}
		else
		{
			// Trying to add a node below the root.
			// Allow addition only at the end of a branch.
			if (parentNode->get_RightPtr() != nullptr)
			{
				// The input node is not at the end of a branch, on the right.
				throw string("Trying to add a right child not at end of branch.");
			}

			position = parentNode->get_AddressRightPtr();
		}


		// Allocate storage for the node
		try {
			new_node = new Node(data);
			*position = new_node;	// attach the node to the tree.
			size++;
		}
		catch (bad_alloc &ex) {
			cout << "Exception during left child node allocation: " << ex.what() << endl;
		}

		return new_node;
	}


//	int Inorder(Node* node, List* list)
//	{
//		// Traverse the binary tree inorder.
//		if (node != nullptr)
//		{
//			// Not at the end of a branch
//
//			if (node->get_LeftPtr() != nullptr)
//			{
//				// Left child is not end of branch.
//				if (this->Inorder(node->get_LeftPtr(), list) != 0)	// call this method recursively
//				{
//					return -1;
//				}
//			}
//
//			list->push_back(*(node->get_DataPtr()));
//
//			if (node->get_RightPtr() != nullptr)
//			{
//				// Right child is not end of branch.
//				if (this->Inorder(node->get_RightPtr(), list) != 0)	// call this method recursively
//				{
//					return -1;
//				}
//			}
//		}
//
//		return 0;
//	}
	virtual int Traverse (Node* node) = 0;
};

class Inorder : public BTree {
private:
	List list;

public:
	int Traverse (Node* node)
	{
		// Traverse the binary tree inorder.
		if (node != nullptr)
		{
			// Not at the end of a branch

			if (node->get_LeftPtr() != nullptr)
			{
				// Left child is not end of branch.
				if (this->Traverse(node->get_LeftPtr()) != 0)	// call this method recursively
				{
					return -1;
				}
			}

			list.push_back(*(node->get_DataPtr()));

			if (node->get_RightPtr() != nullptr)
			{
				// Right child is not end of branch.
				if (this->Traverse(node->get_RightPtr()) != 0)	// call this method recursively
				{
					return -1;
				}
			}
		}

		return 0;
	}
	friend ostream& operator<<(ostream & os, const Inorder& t);

	int operator[](int idx){
		if (idx < 0 || idx > list.size()) throw out_of_range("Index out of bounds.");
		return list.at(idx);
	}
};


class Postorder : public BTree {
private:
	List list;

public:
	int Traverse (Node* node)
	{
		// Traverse the binary tree postorder.
		if (node != nullptr)
		{
			// Not at the end of a branch

			if (node->get_LeftPtr() != nullptr)
			{
				// Left child is not end of branch.
				if (this->Traverse(node->get_LeftPtr()) != 0)	// call this method recursively
				{
					return -1;
				}
			}

			if (node->get_RightPtr() != nullptr)
			{
				// Right child is not end of branch.
				if (this->Traverse(node->get_RightPtr()) != 0)	// call this method recursively
				{
					return -1;
				}
			}

			list.push_back(*(node->get_DataPtr()));
		}

		return 0;
	}

	friend ostream& operator<<(ostream & os, const Postorder& t);

	int operator[](int idx){
		if (idx < 0 || idx > list.size()) throw out_of_range("Index out of bounds.");
		return list.at(idx);
	}
};


class Preorder : public BTree {
private:
	List list;

public:
	int Traverse (Node* node)
	{
		// Traverse the binary tree preorder.
		if (node != nullptr)
		{
			// Not at the end of a branch

			list.push_back(*(node->get_DataPtr()));

			if (node->get_LeftPtr() != nullptr)
			{
				// Left child is not end of branch.
				if (this->Traverse(node->get_LeftPtr()) != 0)	// call this method recursively
				{
					return -1;
				}
			}

			if (node->get_RightPtr() != nullptr)
			{
				// Right child is not end of branch.
				if (this->Traverse(node->get_RightPtr()) != 0)	// call this method recursively
				{
					return -1;
				}
			}
		}

		return 0;
	}

	friend ostream& operator<<(ostream & os, const Preorder& t);

	int operator[](int idx){
		if (idx < 0 || idx > list.size()) throw out_of_range("Index out of bounds.");
		return list.at(idx);
	}
};




//void printList(List &list)
//{
//	for (int i = 0; i < list.size(); i++)
//	{
//		cout << "list[" << i << "] == " << list.at(i) << endl;
//	}
//}

ostream& operator<<(ostream &os, const List &list) {	// overloaded insertion operator
	//printList(list);
	for (int i = 0; i < list.size(); i++)
	{
		os << "list[" << i << "] == " << list.at(i) << endl;
	}

	return os;
}


ostream& operator<<(ostream& os, const Inorder& t)
{
	cout << t.list;
	return os;
}


ostream& operator<<(ostream& os, const Postorder& t)
{
	cout << t.list;
	return os;
}


ostream& operator<<(ostream& os, const Preorder& t)
{
	cout << t.list;
	return os;
}




struct BTreeInput {
	Node* 	node;
	int		value;
};



int main() {
	Inorder tree1;
	Preorder tree2;
	Postorder tree3;

	BTreeInput input[3];

	input[0].value = 3;
	input[1].value = 2;
	input[2].value = 5;

	// Inorder
	cout << "\nTraversing Inorder:" << endl;
	input[0].node = tree1.AddChildLeft(nullptr, &(input[0].value));			// root
	input[1].node = tree1.AddChildLeft(input[0].node, &(input[1].value));	// left child
	input[2].node = tree1.AddChildRight(input[0].node, &(input[2].value));	// right child
	tree1.Traverse(tree1.get_RootPtr());
	cout << "Output using insertion operator:" << endl;
	cout << tree1;
	cout << "Output using subscript operator:" << endl;
	for (int i = 0; i < tree1.get_Size(); i++) {
		cout << tree1[i] << endl;
	}

	// Preorder
	cout << "\nTraversing Preorder:" << endl;
	input[0].node = tree2.AddChildLeft(nullptr, &(input[0].value));			// root
	input[1].node = tree2.AddChildLeft(input[0].node, &(input[1].value));	// left child
	input[2].node = tree2.AddChildRight(input[0].node, &(input[2].value));	// right child
	tree2.Traverse(tree2.get_RootPtr());
	cout << "Output using insertion operator:" << endl;
	cout << tree2;
	cout << "Output using subscript operator:" << endl;
	for (int i = 0; i < tree1.get_Size(); i++) {
		cout << tree2[i] << endl;
	}
	// Postorder
	cout << "\nTraversing Postorder:" << endl;
	input[0].node = tree3.AddChildLeft(nullptr, &(input[0].value));			// root
	input[1].node = tree3.AddChildLeft(input[0].node, &(input[1].value));	// left child
	input[2].node = tree3.AddChildRight(input[0].node, &(input[2].value));	// right child
	tree3.Traverse(tree3.get_RootPtr());
	cout << "Output using insertion operator:" << endl;
	cout << tree3;
	cout << "Output using subscript operator:" << endl;
	for (int i = 0; i < tree1.get_Size(); i++) {
		cout << tree3[i] << endl;
	}
	return 0;
}
