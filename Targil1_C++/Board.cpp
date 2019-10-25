#include "Board.h"


Board::Board(int x, int y) : m_board{ { x,y },{ x,y + 1 },{ x,y + 2 } }, dir_y(1)
{
}
void Board::print(char ch)const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	for (int i = 0; i < (int)SIZE_BOARD; i++)
	{
		if (ch == ' ')
			m_board[i].print(ch);
		else
			m_board[i].print();
	}
	SetConsoleTextAttribute(hConsole, Screen::DEFAULT_COLOR);
}
void Board::move(int dir, const Ball & b)
{
	print(' ');
	int flagY;
	int i;
	for (i = 0; i < (int)SIZE_BOARD; i++)
	{
		flagY = m_board[i].checkY();
		if (flagY == PointBoard::TopBorder || flagY == PointBoard::BottomBorder)
			break;
	}
	if (flagY == PointBoard::BottomBorder && dir == Screen::DOWN)
		dir_y = Screen::SameDir;
	else if (flagY == PointBoard::TopBorder && dir == Screen::UP)
		dir_y = Screen::OppositeDir;
	else if (flagY == -1 || flagY == -2)
		dir_y = Screen::CONSTANT;
	else if (interaction(*this, dir, b) == FALSE)
		dir_y = Screen::CONSTANT;
	else
		dir_y = dir;
	for (i = 0; i < (int)SIZE_BOARD; i++)
	{
		m_board[i].addToY(dir_y);
	}
	print();
}

int Board::getYMid() const
{
	return m_board[1].getY();
}

int Board::getY(int pos)const
{
	return m_board[pos].getY();
}

void Board::setDir(int y)
{
	dir_y = y;
}

void Board::restart(int x, int y)
{
	for (int i = 0; i < 3; i++)
	{
		m_board[i].setValue(x, y + i);
	}
}

int Board::getTop() const
{
	return m_board[0].getY();
}

int Board::getDir() const
{
	return dir_y;
}

int Board::getSize() const
{
	return SIZE_BOARD;
}


void Board::changePos(int x)
{
	int i;
	for (i = 0; i < SIZE_BOARD; i++)
	{
		print(' ');
		m_board[i].addToX(x);
		print();
	}

}

int Board::endGame(int flag)const
{
	if (m_board[0].getX() >= GameOverL && flag == Board::LEFT)
		return 1;
	else if (m_board[0].getX() <= GameOverR && flag == Board::RIGHT)
		return 1;

	return 0;
}

int Board::getX() const
{
	return m_board[0].getX();
}
