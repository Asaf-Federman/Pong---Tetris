#include "Ball.h"
#include <ctime>


Ball::Ball()
{
	srand((int)(time(0)));
	int temp = rand() % 2 + 1;
	if (temp == 2)
		dir_x = Screen::OppositeDir;
	else
		dir_x = Screen::SameDir;
	temp = rand() % 2 + 1;
	if (temp == 2)
		dir_y = Screen::OppositeDir;
	else
		dir_y = Screen::SameDir;
	setBall();
}

int Ball::Behave(Board * left, Board * right, GraveYard & Yleft, GraveYard & Yright)
{
	int flag;
	if (ballBehavior::getCounter() == 8)
	{
		ballBehavior::getCounter() = 0;
		state.behaviour(ballBehavior::BOMB);
	}
	else if (ballBehavior::getCounter() == 4 && getX(7) < right->getX() && getX(0) > left->getX() && state.getState() == ballBehavior::BOMB)
	{
		ballBehavior::getCounter() = 0;
		state.behaviour(ballBehavior::REGULAR);
	}
	if (state.getState() == ballBehavior::REGULAR)
	{
		int checkL = HandleLeftNormal(left);
		int checkR = HandleRightNormal(right);
		if (miss(left, Board::LEFT) == TRUE || miss(right, Board::RIGHT) == TRUE)
			return 2;
		else if (checkL == TRUE || checkR == TRUE)
			return TRUE;
		else
			return FALSE;
	}
	else if (state.getState() == ballBehavior::BECOMING)
	{
		ballBehavior::getCounter()++;
		int checkL = HandleLeftNormal(left);
		int checkR = HandleRightNormal(right);
		if (checkL == TRUE || checkR == TRUE)
		{
			state.behaviour(ballBehavior::REGULAR);
			ballBehavior::getCounter() = 0;
			return TRUE;
		}
		if (collision(Yleft, Yright, flag) != -1)
		{
			state.behaviour(ballBehavior::REGULAR);
			ballBehavior::getCounter() = 0;
			return 2;
		}
		else
			return FALSE;
	}
	else if (state.getState() == ballBehavior::BOMB)
	{
		ballBehavior::getCounter()++;
		int col;
		col = collision(Yleft, Yright, flag);
		if (col != -1)
		{
			if (flag == Board::RIGHT)
			{
				ballBehavior::getCounter() = 0;
				if (!Yright.isEmpty())
					right->changePos(1);
				Yright.pushArr(col, flag);
				restart(flag);
				return 1;
			}
			else if (flag == Board::LEFT)
			{
				ballBehavior::getCounter() = 0;
				if (!Yleft.isEmpty())
					left->changePos(-1);
				Yleft.pushArr(col, flag);
				restart(flag);
				return 1;
			}
		}
		if (HandleLeftNormal(left))
		{
			ballBehavior::getCounter() = 0;
			left->changePos(2);
			return 2;
		}
		else if (HandleRightNormal(right))
		{
			ballBehavior::getCounter() = 0;
			right->changePos(-2);
			return 2;
		}
	}
	return 0;
}
int Ball::collision(const GraveYard & left, const GraveYard & right, int & flag)
{
	int i, k, j;
	if (getX() < Board::GameOverL)
	{
		for (k = 0; k < Ball::SIZE; k++)
		{
			for (i = 0; i < left.getSize(); i++)
			{
				for (j = 0; j < left.getTor(i).getSize(); j++)
				{
					if (left.getTor(i).getPoint(j) != nullptr)
					{
						if (m_ball[k].compare(*(left.getTor(i).getPoint(j))))
						{
							flag = Board::LEFT;
							return i;
						}
					}
				}
			}
		}
	}
	else if (getX() > Board::GameOverR)
	{
		for (k = 0; k < Ball::SIZE; k++)
		{
			for (i = 0; i < right.getSize(); i++)
			{
				for (j = 0; j < right.getTor(i).getSize(); j++)
				{
					if (right.getTor(i).getPoint(j) != nullptr)
					{
						if (m_ball[k].compare(*(right.getTor(i).getPoint(j))))
						{
							flag = Board::RIGHT;
							return i;
						}
					}
				}
			}
		}
	}
	if (m_ball[0].getX() == Screen::MIN_X)
	{
		flag = Board::LEFT;
		return 0;
	}
	if (m_ball[7].getX() == Screen::MAX_X)
	{
		flag = Board::RIGHT;
		return 0;
	}
	return -1;
}
void Ball::print(char ch)const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, state.getColor());
	for (int i = 0; i < (int)SIZE; i++)
	{
		if (ch == ' ')
			m_ball[i].print(ch);
		else
			m_ball[i].print();
	}
	SetConsoleTextAttribute(hConsole, Screen::DEFAULT_COLOR);
}
void Ball::move()
{
	print(' ');
	int flagX, flagY;
	int i;
	for (i = 0; i < (int)SIZE; i++)
	{
		flagX = m_ball[i].checkX();
		if (flagX == -1)
			break;
	}
	for (i = 0; i < (int)SIZE; i++)
	{
		flagY = m_ball[i].checkY();
		if (flagY == -1)
			break;
	}
	dir_x *= flagX;
	dir_y *= flagY;
	for (i = 0; i < (int)SIZE; i++)
	{
		m_ball[i].move(dir_x, dir_y);
	}
	print();
}

void Ball::changeDir(int x = 1, int y = 1)
{
	dir_x = dir_x*x;
	dir_y = dir_y*y;
}

void Ball::restart(int flag)
{
	state.behaviour(ballBehavior::REGULAR);
	int temp;
	srand((int)(time(0)));
	if (flag == -1)
	{
		temp = rand() % 2 + 1;
		if (temp == 2)
			dir_x = Screen::OppositeDir;
		else
			dir_x = Screen::SameDir;
	}
	else if (flag == Board::LEFT)
		dir_x = Screen::SameDir;
	else
		dir_x = Screen::OppositeDir;

	temp = rand() % 2 + 1;
	if (temp == 2)
		dir_y = Screen::OppositeDir;
	else
		dir_y = Screen::SameDir;

	print(' ');
	for (int i = 0; i < SIZE; i++)
		m_ball[i].setValue(40, 14);
	setBall();
}


void Ball::setBall()
{
	m_ball[0].move(-1, 0);
	m_ball[1].move(0, -1);
	m_ball[3].move(0, 1);
	m_ball[4].move(1, -1);
	m_ball[5].move(1, 0);
	m_ball[6].move(1, 1);
	m_ball[7].move(2, 0);
}

int Ball::getY()const
{
	return m_ball[2].getY();
}
int Ball::getY(int pos)const
{
	return m_ball[pos].getY();
}
int Ball::getX(int pos) const
{
	return m_ball[pos].getX();
}


int Ball::getDirY() const
{
	return dir_y;
}

int Ball::getDirX() const
{
	return dir_x;
}

ballBehavior & Ball::getState()
{
	return state;
}


void Ball::animation(int flag)const
{
	switch (flag)
	{
	case 1: m_ball[DOWNL].print(' ');
		break;
	case 2: m_ball[UPL].print(' ');
		break;
	case 3: m_ball[DOWNR].print(' ');
		break;
	case 4: m_ball[UPR].print(' ');
		break;
	}
	Sleep(40);
}

int Ball::HandleLeftNormal(Board * b)
{
	if (dir_y == Screen::UP)
	{
		if (m_ball[0].compare(b->m_board[2]) || m_ball[2].compare(b->m_board[2]))
		{
			changeDir(Screen::OppositeDir, Screen::OppositeDir);
			animation(3);
			return TRUE;
		}
		else if (m_ball[4].compare(b->m_board[2]) || m_ball[1].compare(b->m_board[2]))
		{
			changeDir(Screen::SameDir, Screen::OppositeDir);
			animation(3);
			return TRUE;
		}
		else if (m_ball[0].compare(b->m_board[0]))
		{
			changeDir(Screen::OppositeDir, Screen::SameDir);
			return TRUE;
		}
	}
	else if (dir_y == Screen::DOWN)
	{
		if (m_ball[0].compare(b->m_board[0]) == 1 || m_ball[2].compare(b->m_board[0]))
		{
			changeDir(Screen::OppositeDir, Screen::OppositeDir);
			animation(4);
			return TRUE;
		}
		else if (m_ball[3].compare(b->m_board[0]) || m_ball[6].compare(b->m_board[0]))
		{
			changeDir(Screen::SameDir, Screen::OppositeDir);
			animation(4);
			return TRUE;
		}
		else if (m_ball[0].compare(b->m_board[2]))
		{
			changeDir(Screen::OppositeDir, Screen::SameDir);
			return TRUE;
		}
	}
	if (m_ball[0].compare(b->m_board[1]))
	{
		changeDir(Screen::OppositeDir, Screen::SameDir);
		return TRUE;
	}

	return FALSE;
}
int Ball::miss(Board *b, int flag)
{
	if (flag == Board::LEFT)
		if (b->m_board[0].getX() == m_ball[7].getX())
			return TRUE;
	if (flag == Board::RIGHT)
		if (b->m_board[0].getX() == m_ball[0].getX())
			return TRUE;
	return FALSE;
}
int Ball::HandleRightNormal(Board* b)
{
	if (dir_y == Screen::UP)
	{
		if (m_ball[7].compare(b->m_board[2]) || m_ball[5].compare(b->m_board[2]))
		{
			changeDir(Screen::OppositeDir, Screen::OppositeDir);
			animation(1);
			return TRUE;
		}
		else if (m_ball[1].compare(b->m_board[2]) || m_ball[4].compare(b->m_board[2]))
		{
			changeDir(Screen::SameDir, Screen::OppositeDir);
			animation(1);
			return TRUE;
		}
		else if (m_ball[7].compare(b->m_board[0]))
		{
			changeDir(Screen::OppositeDir, Screen::SameDir);
			return TRUE;
		}
	}
	else if (dir_y == Screen::DOWN)
	{
		if (m_ball[7].compare(b->m_board[0]) || m_ball[5].compare(b->m_board[0]))
		{
			changeDir(Screen::OppositeDir, Screen::OppositeDir);
			animation(2);
			return TRUE;
		}
		else if (m_ball[6].compare(b->m_board[0]) || m_ball[3].compare(b->m_board[0]))
		{
			changeDir(Screen::SameDir, Screen::OppositeDir);
			animation(2);
			return TRUE;
		}
		else if (m_ball[7].compare(b->m_board[2]))
		{
			changeDir(Screen::OppositeDir, Screen::SameDir);
			return TRUE;
		}
	}
	if (m_ball[7].compare(b->m_board[1]))
	{
		changeDir(Screen::OppositeDir, Screen::SameDir);
		return TRUE;
	}
	return FALSE;
}
bool interaction(const Board & b, int dir, const Ball & ball)
{
	if (b.getDir() == Screen::UP)
	{
		if (b.getX() == ball.getX(0))
		{
			if (b.getY(0) + dir == ball.getY(0))
				return FALSE;
		}
		else if (b.getX() == ball.getX(3))
		{
			if (b.getY(0) + dir == ball.getY(3))
				return FALSE;
		}
		else if (b.getX() == ball.getX(6))
		{
			if (b.getY(0) + dir == ball.getY(6))
				return FALSE;
		}
		else if (b.getX() == ball.getX(7))
		{
			if (b.getY(0) + dir == ball.getY(7))
				return FALSE;
		}
	}
	if (b.getDir() == Screen::DOWN)
	{
		if (b.getX() == ball.getX(0))
		{
			if (b.getY(2) + dir == ball.getY(0))
				return FALSE;
		}
		else if (b.getX() == ball.getX(1))
		{
			if (b.getY(2) + dir == ball.getY(1))
				return FALSE;
		}
		else if (b.getX() == ball.getX(4))
		{
			if (b.getY(2) + dir == ball.getY(4))
				return FALSE;
		}
		else if (b.getX() == ball.getX(7))
		{
			if (b.getY(2) + dir == ball.getY(7))
				return FALSE;
		}
	}
	return TRUE;
}
