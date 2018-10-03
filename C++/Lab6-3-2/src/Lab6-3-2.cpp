//============================================================================
// Name        : Lab6-3-2.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Polymorphism: part 2
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct Point2D {
	int x;
	int y;
};

class Piece {
public:
	virtual bool checkMove(string startPos, string endPos){return false;}
	virtual ~Piece(){}
};

class Man : public Piece {
public:
	bool checkMove(string startPos, string endPos){
		Point2D start, end;

		start.x = startPos.substr(0,1)[0] - 'a';	// assumes that startPos is of the form a1 (lower case letter, numeral)
		start.y = stoi(startPos.substr(1,1));	// ref: http://www.cplusplus.com/reference/string/stoi/

		end.x = endPos.substr(0,1)[0] - 'a';
		end.y = stoi(endPos.substr(1,1));

		int dx = end.x - start.x;
		int dy = end.y - start.y;

		if (abs(dx) == 1 && dy == 1)
		{
			return true;
		}

		// else:
		return false;
	}
};

class King : public Piece {
public:
	bool checkMove(string startPos, string endPos){
		Point2D start, end;

		start.x = startPos.substr(0,1)[0] - 'a';	// assumes that startPos is of the form a1 (lower case letter, numeral)
		start.y = stoi(startPos.substr(1,1));	// ref: http://www.cplusplus.com/reference/string/stoi/

		end.x = endPos.substr(0,1)[0] - 'a';
		end.y = stoi(endPos.substr(1,1));

		int dx = end.x - start.x;
		int dy = end.y - start.y;

		if (abs(dx) == dy)
		{
			return true;
		}

		// else:
		return false;
	}
};

int main() {
	Piece* p[2];
	p[0] = new Man;
	p[1] = new King;

	// Can man move from b1 to c2?
	if (p[0]->checkMove("b1", "c2"))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	// Can king move from b1 to d3?
	if (p[1]->checkMove("b1", "d3"))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	// Can man move from b1 to d3?
	if (p[0]->checkMove("b1", "d3"))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}


	delete p[1];
	delete p[0];

	return 0;
}
