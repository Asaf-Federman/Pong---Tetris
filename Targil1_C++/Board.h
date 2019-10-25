#ifndef __BOARD_H
#define __BOARD_H

#include "PointBoard.h"
#include "Screen.h"
#include "utils.h"

//A board class which contains an array of SIZE points that structure the board, and direction for the board.
class Ball;//forward declaration.
class Board
{
	enum { SIZE_BOARD = 3 };
	enum { GameOverR = 60, GameOverL = 20 };
	PointBoard m_board[SIZE_BOARD];//array of points.
	int dir_y;//direction of the y coordinate.

public:
	enum { RIGHT = 1, LEFT = 0 };
	Board(int x, int y);//constructor
	void print(char ch = '#')const;//prints the board
	void move(int dir, const Ball & b);//moves the board.
	int getYMid()const;//gets the y coordinate in the middle of the board
	int getY(int pos)const;//gets the y coordinate in current pos.
	void setDir(int y);//sets new y direction.
	void restart(int x, int y);//restarts the board to default position.
	int getTop()const;//return the Y coordinate of the top of the board.
	int getDir()const;//gets the direction.
	int getSize()const;//returns the size of the board.
	void changePos(int x);//Adding to substracting from the current X coordinate.
	int endGame(int flag)const;//checks if any of the players reached the "GameOver" position.
	int getX()const;//returns the X coordinate of the board.
	friend class Ball;
	virtual ~Board()
	{

	}
};
bool interaction(const Board & b, int dir, const Ball & ball);//declaration to the function.


#endif // __BOARD_H
