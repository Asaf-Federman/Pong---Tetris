#ifndef __POINTBOARD_H
#define __POINTBOARD_H

#include"Point.h"
//class of points for the board.

class PointBoard :public Point
{

public:
	enum { TopBorder = -1, BottomBorder = -2 };
	PointBoard(int x, int y);//constructor
	int checkY()const;//checks if the point reached screen limitations.
};


#endif // __POINTBOARD_H