#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H

#include "Ball.h"
#include "playerBoard.h"
#include "GraveYard.h"
#include "computerBoard.h"

// the function controls the game 

class screenManager {
	Board * brd[2];//array of balls.
	Ball ball;//game ball
	GraveYard yardR, yardL;//right player and left player's tetris
	enum { RSCREEN = 60, LSCREEN = 20 };
public:
	screenManager();//ctor
	void print();//prints
	void sleepFunc();//set the value of sleep
	void consoleManage();//managing the menu
	void consoleManage(char k);//overloading
	void startGame();//starting a new game
	void getLevelMenu(int numOfPlayers);//level for the computer player
	void instruction(char c = '0');//instructions for the game
	void restart();//restarting the game
	void printMenu(char k = '0');//printing the starting menu
	int interSection();//if one player misses the ball
	void printLimits();//printing the screen limits
};
#endif //__SCREENMANAGER_H
