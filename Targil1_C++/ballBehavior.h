#ifndef __BALLBEHAVIOR_H
#define __BALLBEHAVIOR_H

#include "Screen.h"

class ballBehavior
{
	int state;
	int color;
	static int count;
public:
	enum { REGULAR = 15, BECOMING = 14, BOMB = 12 };
	ballBehavior(int state = 15, int color = 15);//ctor
	static int & getCounter();//returns the counter by ref
	int getState()const;//returns the value of state.
	void setState(int newState);//sets the value of state.
	int getColor()const;//returns the value of color
	void setColor(int newColor);//sets the value of color
	void behaviour(int flag);//sets the behavior.
};


#endif // __BALLBEHAVIOR_H