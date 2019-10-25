#ifndef __POINTTOR_H
#define __POINTTOR_H

#include "Point.h"

//incharge of the ball's point.

class PointTor:public Point 
{
	int m_top;
public:
	PointTor(int x, int y, int top);//constructor
	int getTop()const;//returning the top coordinate.
};

#endif // __POINTTOR_H