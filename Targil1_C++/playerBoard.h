#ifndef __PLAYERBOARD_H
#define __PLAYERBOARD_H
#include "Board.h"
#include <conio.h>
#include "Ball.h"
class playerBoard :public Board
{
	static int countL;
	static int countR;
public:
	playerBoard(int x, int y) :Board(x, y) {}//ctor
	enum { RIGHT = 1, LEFT = 0 };
	void moveLeft(char c, Ball & b, int & count);//incharge of the left player board.
	void moveRight(char c, Ball & b, int & count);//incharge of the right player board.
	friend char move(playerBoard *brdL, Ball &b, playerBoard *brdR = nullptr);//incharge of both boards.
	static int & getCountL();//returns the countL by ref
	static int & getCountR();//returns the countR by ref.
	virtual ~playerBoard()//dtor
	{

	}
};
#endif //__PLAYERBOARD_H
