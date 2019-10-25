#include "playerBoard.h"

int playerBoard::countL = -1;
int playerBoard::countR = -1;

char move(playerBoard *brdL, Ball &b, playerBoard *brdR)
{
	if (playerBoard::countL >= 0)
		if (b.getX() == 40)
			playerBoard::countL++;
	if (playerBoard::countL == 4)
		playerBoard::countL = -1;
	if (playerBoard::countR >= 0)
		if (b.getX() == 40)
			playerBoard::countR++;
	if (playerBoard::countR == 4)
		playerBoard::countR = -1;
	char k;
	for (int i = 0; i < 10; i++)
	{
		if (_kbhit())
		{
			k = tolower(_getch());
			if (k == Screen::EXIT)
			{
				return k;
			}
			if (brdR != nullptr)
				((playerBoard*)brdR)->moveRight(k, b, playerBoard::countR);
			((playerBoard*)brdL)->moveLeft(k, b, playerBoard::countL);
		}
	}
	return TRUE;
}
void playerBoard::moveLeft(char c, Ball & b, int & count)
{
	switch (c) {
	case 'q':
		move(Screen::UP, b);
		break;
	case 'a':
		move(Screen::DOWN, b);
		break;
	case 's':
		if (count == -1 && b.getState().getState() == ballBehavior::REGULAR)
		{
			count++;
			b.getState().behaviour(ballBehavior::BECOMING);
		}
		break;
	default:
		break;
	}
}

void playerBoard::moveRight(char c, Ball & b, int & count)
{
	switch (c) {
	case 'p':
		move(Screen::UP, b);
		break;
	case 'l':
		move(Screen::DOWN, b);
		break;
	case 'k':
		if (count == -1 && b.getState().getState() == ballBehavior::REGULAR)
		{
			count++;
			b.getState().behaviour(ballBehavior::BECOMING);
		}
		break;
	default:
		break;
	}
}

int & playerBoard::getCountL()
{
	return countL;
}
int & playerBoard::getCountR()
{
	return countR;
}