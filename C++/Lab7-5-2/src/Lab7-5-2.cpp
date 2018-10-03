//============================================================================
// Name        : Lab7-5-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Exceptions: using in program
//============================================================================

#include <iostream>
using namespace std;


class Disk
{
public:
	Disk(int val);
	int value;
	Disk* next;
};
Disk::Disk(int val) : value(val), next(nullptr)
{
}

class Tower
{
public:
	Tower(unsigned int index) : head(nullptr) {
		if (index > 3) throw out_of_range("Index out of range in Tower constructor.");
		this->index = index;
	}
	void push_front(int value);
	bool pop_front(int &value);	// add & for passing by reference
	unsigned int get_Index() const {return index;}
	void printTower();
private:
	Disk* head;
	unsigned int index;
};
void Tower::push_front(int value)
{
	Disk* new_head = new Disk(value);
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

bool Tower::pop_front(int &value)
{
	// implement the pop
	// don't forget to delete the popped node!
	// and fix the return value
	if (head != nullptr)
	{
		// there is something in the list.
		Disk* popped = head;	// get the head
		head = head->next;		// move the head to the next node in the list
		value = popped->value;	// get the value to return.
		delete popped;
		return true;
	}
	return false;
}

class Game {
private:
	Tower *tower[3];
public:
	Game(){
		tower[0] = new Tower(0);
		tower[1] = new Tower(1);
		tower[2] = new Tower(2);
	}

	~Game(){
		delete tower[2];
		delete tower[1];
		delete tower[0];
	}

	void Initialize()
	{
		// load up the first tower with large to small disks
		tower[0]->push_front(3);
		tower[0]->push_front(2);
		tower[0]->push_front(1);

		// Empty the other two towers (if anything's there)
		int value;
		while (tower[1]->pop_front(value)) ;
		while (tower[2]->pop_front(value)) ;
	}


	void Play()
	{
		int input = 0;
		bool done = false;	// true when game is completed.
		cout << "START." << endl;
		tower[0]->printTower();
		tower[1]->printTower();
		tower[2]->printTower();
		do {
			cout << "\nEnter your move (0 to quit): ";
			cin >> input;
			if (input != 0)
			{
				int idxSrcTower = (input / 10)-1;	// decode input.
				int idxDstTower = (input % 10)-1;	// both should end up in the range [0,2].

				try {
					Move(idxSrcTower, idxDstTower);
				} catch (string &s) {
					cout << "Exception during move: " << s << endl;
				} catch (range_error &ex) {
					cout << "Exception during move: " << ex.what() << endl;
				}


				tower[0]->printTower();
				tower[1]->printTower();
				tower[2]->printTower();


				done = CheckDone();
				if (done)
				{
					cout << "\nDONE!" << endl;
				}

			}
		} while (input != 0 && !done);

		if (input == 0)
		{
			cout << "QUIT." << endl;
		}
	}

	bool CheckDone()
	{
		// Return true when all disks are on tower #3.
		bool done = true;

		// Make a temporary tower to hold input tower's contents
		Tower *temp = new Tower(3);	// tower with index 3 is the temporary tower.

		int value;
		int numMoved = 0;

		// Move disks from given tower to temporary tower, in reverse order.
		while (tower[2]->pop_front(value)) {
			temp->push_front(value);
			numMoved++;
		}

		if (numMoved > 0)
		{
			// Now put them back.
			while (temp->pop_front(value)) {
				tower[2]->push_front(value);
			}
		}

		delete temp;

		if (numMoved != 3)
		{
			// Must have exactly three disks on the tower to be done.
			done = false;
		}


		return done;
	}

	void Move(int idxSrc, int idxDst)
	{
		// Attempt to move from source to destination tower.
		if (idxSrc < 0 || idxSrc > 2) throw range_error ("Invalid source tower specified during move.  No action taken.");
		if (idxDst < 0 || idxDst > 2) throw range_error ("Invalid destination tower specified during move.  No action taken.");


		int srcValue;
		if (!this->tower[idxSrc]->pop_front(srcValue))
		{
			// there was nothing on the source tower
			throw string("Attempted to remove disk from empty tower.  No action taken.");
		}
		else
		{
			if (idxSrc == idxDst)
			{
				// Legal move: disk is picked up and placed back on the same tower.  Nothing changes.
				tower[idxSrc]->push_front(srcValue);	// put this back where it was.
				return;
			}

			// value is the disk possibly being moved
			int dstValue;	// disk presently on the destination tower
			if (tower[idxDst]->pop_front(dstValue))
			{
				// there was something on the destination tower.
				// check whether it was larger or smaller than the source disk.
				if (dstValue >= srcValue)
				{
					// this move is allowed
					// go ahead an place the source disk
					tower[idxDst]->push_front(dstValue);	// first, put this one back where it belongs
					tower[idxDst]->push_front(srcValue);
				}
				else
				{
					// trying to put a larger disk on top of a smaller disk
					// this is not allowed.
					// put the disks back and throw an exception.
					tower[idxDst]->push_front(dstValue);	// first, put this one back where it belongs
					tower[idxSrc]->push_front(srcValue);
					throw string ("Attempted to place a larger disk on a smaller disk.  No action taken.");
				}
			}
			else
			{
				// there was nothing on the destination tower
				// go ahead an place the source disk
				tower[idxDst]->push_front(srcValue);
			}
		}
	}
};

void Tower::printTower()
{
	// print the contents of specified tower
	cout << "tower_" << get_Index()+1 << ":";

	// Make a temporary tower to hold input tower's contents
	Tower *temp = new Tower(3);	// tower with index 3 is the temporary tower.

	int value;
	int numMoved = 0;

	// Move disks from given tower to temporary tower, in reverse order.
	while (pop_front(value)) {
		temp->push_front(value);
		numMoved++;
	}

	if (numMoved > 0)
	{
		// Now put them back.
		while (temp->pop_front(value)) {
			cout << " " << value;
			push_front(value);
		}
	}
	else
	{
		// None were moved.  Therefore the tower must have been empty.
		cout << " empty";
	}
	cout << ";" << endl;

	delete temp;
}

int main() {
	bool allOK = true;
	Game *game = nullptr;

	try {
		game = new Game();
	}
	catch (out_of_range &ex)
	{
		cout << "Exception during Game construction: " << ex.what() << endl;
		allOK = false;
	}



	if (allOK){
		game->Initialize();	// put three disks on the first tower.

		game->Play();
	}



	if (game != nullptr) delete game;

	return 0;
}
