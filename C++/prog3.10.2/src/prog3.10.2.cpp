//============================================================================
// Name        : prog3.10.2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Collection {
	int elno;
	int *elements;
};

void AddToCollection(Collection &col, int element) {
	// Insert your code here
	if (col.elno == 0)
	{
		// Allocate a one-element vector and store a new value in it.
		col.elements = new int[1];
		col.elements[0] = element;
		col.elno = 1;
	}
	else
	{
		// Allocate a new vector with a length greater by one than the current vector,
		// then copy all elements from the old vector to the new one,
		// append a new value to the new vector
		// and finally free up the old vector.
		int *A = new int[col.elno+1];
		for (int i = 0; i < col.elno; i++)
		{
			A[i] = col.elements[i];
		}
		A[col.elno] = element;
		col.elno++;

		delete[] col.elements;

		col.elements = A;
	}
}

void PrintCollection(Collection col) {
	cout << "[ ";
	for(int i = 0; i < col.elno; i++)
		cout << col.elements[i] << " ";
	cout << "]" << endl;
}

int main(void) {
	Collection collection = { 0, NULL };
	int elems;
	cout << "How many elements? ";
	cin >> elems;
	srand(time(NULL));
	for(int i = 0; i < elems; i++){
		AddToCollection(collection, rand() % 100 + 1);
	PrintCollection(collection);}
	delete[] collection.elements;
	return 0;
}
