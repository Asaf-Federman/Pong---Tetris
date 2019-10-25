#include "PointBoard.h"

PointBoard::PointBoard(int x, int y) : Point(x,y,'#')
{
}

int PointBoard::checkY()const
{
	if (getY() == ((int)Screen::MAX_Y))
	{
		return TopBorder;
	}
	if (getY() == ((int)Screen::MIN_Y))
	{
		return BottomBorder;
	}
	return FALSE;
}


