//============================================================================
// Name        : Lab6-4-4.cpp
// Author      : JMH
// Version     :
// Copyright   : Your copyright notice
// Description : Your own game: tic tac toe
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct Position {
	int row;
	int col;
};

//---------------------------------------------------------------

class UIBoard {
private:
public:
	void draw(int* v){
		cout << endl;
		for (int i = 0;i < 3; i++)
		{
			if (i > 0) cout << "-----------"<< endl;
			for (int j = 0; j < 3; j++)
			{
				if (j > 0) cout << '|';

				switch (*(v+3*i+j))
				{
				case 1:
					cout << " O ";
					break;
				case 2:
					cout << " X ";
					break;
				default:
					cout << "   ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
};

class Board {
private:
	int value[3][3] = {};
	UIBoard *uiBoard;
public:
	Board(){
		uiBoard = new UIBoard;
	}
	~Board(){
		delete uiBoard;
	}
	void draw(int* v){uiBoard->draw(v);};
	int getValue(int row, int col){
		return value[row][col];
	}
	void setValue(int row, int col, int value) {
		this->value[row][col] = value;
	}
	void drawBoard(){
		draw(&value[0][0]);
	}
};

//---------------------------------------------------------------

class UIPlayer {
private:
	char mark;
public:
	UIPlayer(int v){
		if (v == 1) mark = 'O';
		else mark = 'X';
	}
	void drawMark(){cout << mark;}
	Position askMove(){
		Position p;
		cout << "For player " << mark << ", enter row, column for next move: ";
		cin >> p.row >> p.col;
		return p;
	}
	void rejectMove() {
		cout << "That position is not available.  Choose another." << endl;
	}
};

class Player {
private:
	int value;
	UIPlayer *uiPlayer;
	Board *board;
public:
	Player(int v, Board *b){
		value = v;
		uiPlayer = new UIPlayer(v);
		board = b;
	}
	~Player(){
		delete uiPlayer;
	}
	void draw(){uiPlayer->drawMark();}

	int makeMove(){
		// if this player wins as a result of making this move, return value
		// otherwise return 0
		int retval = 0;

		bool moveAccepted = false;
		Position trialMove = uiPlayer->askMove();
		do {
			if (checkPosEmpty(trialMove))
			{
				// this trial position is OK: use it
				moveAccepted = true;
				takePosition(trialMove);

				// Check if this player has won.
				if (haveIWon(trialMove))
				{
					retval = value;
				}

				// update the board drawing.
				board->drawBoard();
			}
			else
			{
				// this trial position is already occupied: reject it.
				uiPlayer->rejectMove();
				trialMove = uiPlayer->askMove();
			}
		} while (!moveAccepted);


		return retval;
	}

	bool checkPosEmpty(Position p){
		// check if the board is empty at the trial position.
		if (board->getValue(p.row,p.col)== 0)
		{
			return true;	// board is empty here
		}

		// else
		return false;	// board is occupied here
	}

	void takePosition(Position p){
		board->setValue(p.row,p.col,value);
	}

	bool haveIWon(Position p)
	{
		// return true if this player has won; false otherwise.
		// This checks only runs that involve Position p, since earlier moves,
		// had they resulted in a win, would have been detected earlier.
		bool win = true;

		// win on same row?
		for (int i = 0; i < 3; i++){
			if (board->getValue(p.row, i) != value)
			{
				win = false;
				break;
			}
		}

		if (!win)
		{
			win = true;
			// win on same col?
			for (int i = 0; i < 3; i++){
				if (board->getValue(i, p.col) != value)
				{
					win = false;
					break;
				}
			}
		}

		if (!win)
		{
			// win on NW-SE diagonal?
			if ((p.row == 0 && p.col == 0)
					|| (p.row == 1 && p.col == 1)
					|| (p.row == 2 && p.col == 2)) {
				// p is on NW-SE diagonal
				win = true;
				for (int i = 0; i < 3; i++){
					if (board->getValue(i, i) != value)
					{
						win = false;
						break;
					}
				}
			}
		}

		if (!win)
		{
			// win on NE-SW diagonal?
			if ((p.row == 0 && p.col == 2)
					|| (p.row == 1 && p.col == 1)
					|| (p.row == 2 && p.col == 0)) {
				// p is on NE-SW diagonal
				win = true;
				for (int i = 0; i < 3; i++){
					if (board->getValue(i, 2-i) != value)
					{
						win = false;
						break;
					}
				}
			}
		}

		return win;
	}
};

//---------------------------------------------------------------

class UIGame {
private:
public:
	void announceWinner(Player* p){
		cout << "Player ";
		p->draw();
		cout << " wins."<< endl;
	}
	void announceDraw(){cout << "Game is a draw.";}
};

class Game {
private:
	Board board;
	Player *player[2];
	UIGame *uiGame;
public:
	Game(){
		player[0] = new Player(1, &board);
		player[1] = new Player(2, &board);
		uiGame = new UIGame;
	}

	~Game(){
		delete uiGame;
		delete player[0];
		delete player[1];
	}

	void play(){
		board.drawBoard();

		int winner = 0;	// no winner
		int idxPlayer = -1;
		int moveCounter = 0;	// prevent endless play in a draw.
		do {
			++idxPlayer %= 2;
			winner = player[idxPlayer]->makeMove();
			moveCounter++;
		} while (winner == 0 && moveCounter < 9);

		if (winner == 1)
		{
			uiGame->announceWinner(player[0]);
		}
		else if (winner == 2)
		{
			uiGame->announceWinner(player[1]);
		}
		else
		{
			uiGame->announceDraw();
		}
	}
};

//---------------------------------------------------------------

int main() {
	Game g;
	g.play();

	return 0;
}
