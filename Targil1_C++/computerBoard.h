#ifndef __COMPUTERBOARD_H
#define __COMPUTERBOARD_H

#include "Board.h"
#include "Ball.h"

class computerBoard : public Board
{
	int level;

public:
	computerBoard(int x, int y, int lvl) : Board(x, y), level(lvl) {}
	enum { BEST = 0, GOOD = 40, NOVICE = 10 };
	enum { RIGHT = 1, LEFT = 0 };
	void moveLeft(const Ball &b);//incharges of the left board.
	void moveRight(const Ball &b);//incharges of the right board
	int computeMoveLeft(const Ball &b);//calculate the needed position.
	int computeMoveRight(const Ball &b);//calculate the needed position.
	virtual ~computerBoard()//dtor
	{

	}
};



#endif // __COMPUTERBOARD_H