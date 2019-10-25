#include "ballBehavior.h"

int ballBehavior::count = 0;

ballBehavior::ballBehavior(int state, int color) : state(state), color(color)
{

}

int & ballBehavior::getCounter()
{
	return count;
}

int ballBehavior::getState() const
{
	return state;
}

void ballBehavior::setState(int newState)
{
	state = newState;
}

int ballBehavior::getColor() const
{
	return color;
}

void ballBehavior::setColor(int newColor)
{
	color = newColor;
}

void ballBehavior::behaviour(int flag)
{
	if (flag == REGULAR)
	{
		state = color = REGULAR;
	}
	else if (flag == BECOMING)
	{
		state = color = BECOMING;
	}
	else
		state = color = BOMB;
}
