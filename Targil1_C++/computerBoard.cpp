#include "computerBoard.h"
#include <ctime>



void computerBoard::moveLeft(const Ball &b)
{
	static int location;
	int temp;
	temp = computeMoveLeft(b);
	if (temp != -1)
	{
		location = temp;
	}
	int bMid = getYMid();
	if (bMid < location)
		move(Screen::DOWN, b);

	else if (bMid > location)
		move(Screen::UP, b);
	else
	{
		if (getDir() != 0)
			move(Screen::CONSTANT, b);
	}
}

void computerBoard::moveRight(const Ball & b)
{
	static int location;
	int temp;
	temp = computeMoveRight(b);
	if (temp != -1)
	{
		location = temp;
	}
	int bMid = getYMid();
	if (bMid < location)
		move(Screen::DOWN, b);
	else if (bMid > location)
		move(Screen::UP, b);
	else
	{
		if (getDir() != 0)
			move(Screen::CONSTANT, b);
	}
}

int computerBoard::computeMoveLeft(const Ball &b)
{
	int curr_loc = -1;
	int miss, temp;
	if ((b.getX() - getX()) == 15 && b.getDirX() == Ball::LEFT_X)
	{
		srand((int)(time(0)));
		switch (level)
		{
		case BEST: miss = 0;
			break;
		case GOOD: miss = rand() % GOOD + 1;
			break;
		case NOVICE: miss = rand() % NOVICE + 1;
		}
		int i, curr_dir = b.getDirY();
		curr_loc = b.getY();
		if (curr_dir == Ball::UP_Y)
		{
			curr_loc--;
		}
		else
		{
			curr_loc++;
		}
		for (i = 0; i < 14; i++)
		{
			if (curr_loc == Screen::MIN_Y)
			{
				curr_dir = curr_dir*Screen::OppositeDir;
				curr_loc = curr_loc + 2;
			}
			else if (curr_loc == Screen::MAX_Y)
			{
				curr_dir = curr_dir*Screen::OppositeDir;
				curr_loc = curr_loc - 2;
			}
			if (curr_dir == Ball::UP_Y)
			{
				curr_loc--;
			}
			else
			{
				curr_loc++;
			}
		}
		if (curr_dir == Ball::UP_Y)
			curr_loc++;
		else
			curr_loc--;
		if (miss == 1)
		{
			if (curr_loc <= Screen::MIN_Y + 5)
				curr_loc += 3;
			else if (curr_loc >= Screen::MAX_Y - 5)
				curr_loc -= 3;
			else
			{
				srand((int)(time(0)));
				temp = rand() % 2 + 1;
				if (temp == 1)
					curr_loc += 3;
				else
					curr_loc -= 3;
			}
		}
		else
		{
			srand((int)(time(0)));
			temp = rand() % 3;
			if (temp == 2)
				curr_loc = curr_loc + Screen::OppositeDir;
			else
				curr_loc = curr_loc + temp;
		}
	}
	else if ((b.getX() - getX()) >= 10 && b.getDirX() == Ball::RIGHT_X)
		curr_loc = (Screen::MIN_Y + Screen::MAX_Y) / 2;
	else if ((b.getX() - getX()) > 15)
		curr_loc = (Screen::MIN_Y + Screen::MAX_Y) / 2;
	return curr_loc;
}

int computerBoard::computeMoveRight(const Ball &b)
{
	int curr_loc = -1;
	int temp, miss;
	if ((getX() - b.getX()) == 15 && b.getDirX() == Ball::RIGHT_X)
	{
		srand((int)(time(0)));
		switch (level)
		{
		case BEST: miss = 0;
			break;
		case GOOD: miss = rand() % GOOD + 1;
			break;
		case NOVICE: miss = rand() % NOVICE + 1;
		}
		int i, curr_dir = b.getDirY();
		curr_loc = b.getY();
		if (curr_dir == Ball::UP_Y)
		{
			curr_loc--;
		}
		else
		{
			curr_loc++;
		}
		for (i = 0; i < 13; i++)
		{
			if (curr_loc == Screen::MIN_Y)
			{
				curr_dir = curr_dir*Screen::OppositeDir;
				curr_loc = curr_loc + 2;
			}
			else if (curr_loc == Screen::MAX_Y)
			{
				curr_dir = curr_dir*Screen::OppositeDir;
				curr_loc = curr_loc - 2;
			}
			if (curr_dir == Ball::UP_Y)
			{
				curr_loc--;
			}
			else
			{
				curr_loc++;
			}
		}
		if (curr_dir == Ball::UP_Y)
			curr_loc++;
		else
			curr_loc--;
		if (miss == 1)
		{
			if (curr_loc <= Screen::MIN_Y + 5)
				curr_loc += 3;
			else if (curr_loc >= Screen::MAX_Y - 5)
				curr_loc -= 3;
			else
			{
				srand((int)(time(0)));
				temp = rand() % 2 + 1;
				if (temp == 1)
					curr_loc += 3;
				else
					curr_loc -= 3;
			}
		}
		else
		{
			srand((int)(time(0)));
			int temp = rand() % 3;
			if (temp == 2)
				curr_loc = curr_loc + Screen::OppositeDir;
			else
				curr_loc = curr_loc + temp;
		}
	}
	else if ((getX() - b.getX()) >= 10 && b.getDirX() == Ball::LEFT_X)
		curr_loc = (Screen::MIN_Y + Screen::MAX_Y) / 2;
	else if ((getX() - b.getX()) > 15)
		curr_loc = (Screen::MIN_Y + Screen::MAX_Y) / 2;
	return curr_loc;
}
