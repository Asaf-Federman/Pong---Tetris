#include "Point.h"

Point::Point(int x, int y,char ch):m_x(x),m_y(y),ch(ch)
{
}
void Point::move(int x, int y)
{
	m_x += x;
	m_y += y;
}
void Point::print(char c)const
{
	gotoxy(m_x, m_y);
	cout << c;
}
void Point::print()const
{
	print(ch);
}
int Point::compare(const Point & p)const
{
	if (m_x == p.m_x && m_y == p.m_y)
		return TRUE;
	return FALSE;
}
int Point::checkX()const
{
	if (m_x == ((int)Screen::MAX_X) || m_x == ((int)Screen::MIN_X))
	{
		return -1;
	}
	return 1;
}
int Point::checkY()const
{
	if (m_y == ((int)Screen::MAX_Y) || m_y == ((int)Screen::MIN_Y))
	{
		return -1;
	}
	return 1;
}

int Point::getX() const
{
	return m_x;
}

int Point::getY() const
{
	return m_y;
}

int & Point::getY()
{
	return m_y;
}

int & Point::getX()
{
	return m_x;
}

void Point::setX(int x)
{
	m_x=x;
}

void Point::setY(int y)
{
	m_y = y;
}

void Point::addToX(int x)
{
	m_x+=x;
}

void Point::addToY(int y)
{
	m_y += y;
}

void Point::setValue(int x, int y)
{
	m_x = x;
	m_y = y;
}