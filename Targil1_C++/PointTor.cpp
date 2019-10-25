#include "PointTor.h"

PointTor::PointTor(int x, int y, int top) : Point(x,y,'#'),m_top(top) {}

int PointTor::getTop() const
{
	return m_top;
}

