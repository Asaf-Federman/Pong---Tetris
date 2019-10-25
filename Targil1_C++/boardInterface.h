#ifndef __BOARDINTERFACE_H
#define __BOARDINTERFACE_H

#include "Board.h"
//A board interface class which incharge of an array of boards.
class boardInterface 
{
	enum{NumberOfBoards=2};
	Board brd[NumberOfBoards];
public:
	boardInterface() : brd{ {4,10}, {76,10} } {}//constructor

	void move(char c);//moves the boards according to the user's input
	void print()const;//prints the boards.
	int intersection(Ball & b);//checks the intersection between the ball and the boards.
	void restart();//restarting the boards location.
	Board& getL();//returns the left board.
	Board& getR();//returns the right board.
	int endGame()const;//checks if the game ends.
};

#endif //__BOARDINTERFACE_H