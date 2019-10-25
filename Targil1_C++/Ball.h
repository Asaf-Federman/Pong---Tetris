#ifndef __BALL_H
#define __BALL_H
#include "PointBall.h"
#include "ballBehavior.h"
#include "Board.h"
#include "GraveYard.h"

//A board class which contains an array of SIZE points that structure the ball itself, and directions for the ball.

class Ball {
	enum { SIZE = 8 };
	enum { UPR = 4, DOWNR = 6, UPL = 1, DOWNL = 3 };
	PointBall m_ball[SIZE];//static array of 8 points.
	int dir_x, dir_y;//directions for the coordinates.
	ballBehavior state;
public:
	enum { RIGHT_X = 1, LEFT_X = -1, UP_Y = -1, DOWN_Y = 1 };
	Ball();	//constructor.
	int Behave(Board * left, Board * right, GraveYard & Yleft, GraveYard & Yright);//incharge of the ball's behavior
	int collision(const GraveYard & left, const GraveYard & right, int & flag);//checks for collision between the ball and the graveyard
	void print(char ch = '0')const;//prints the ball.
	void move();//moves the ball.
	void changeDir(int x, int y);//changes the direction of the ball.
	void restart(int flag = -1);//restart the ball to default position.
	void setBall();//setting the default position of the ball.
	int getY()const;//returns the y value;
	int getY(int pos)const;//returns the y value, in current position.
	int getX(int pos=2)const;//returns the x value in current position.
	int getDirY() const;//returns the direction of the y coordinate.
	int getDirX() const;//returns the direction of the x coordinate
	ballBehavior & getState();//returns the state of the ball by ref.
	void animation(int flag)const;	//animation for the ball.
	int HandleLeftNormal(Board * b);//handle the left collision between the ball and board
	int miss(Board * b, int flag);//checks for a miss.
	int HandleRightNormal(Board * b);//handle the right collision between the ball and board
	friend bool interaction(const Board & b, int dir, const Ball & ball);//checks if the board can move in it's direction.
	friend class Board;
};


#endif // __BALL_H