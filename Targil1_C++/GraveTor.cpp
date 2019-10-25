#include "GraveTor.h"

GraveTor::GraveTor()
{
	int i;
	for (i = 0; i < SIZE_TOR; i++)
	{
		tor[i] = nullptr;
	}
}

GraveTor & GraveTor::operator=(GraveTor & b)
{
	int i;
	for (i = 0; i < SIZE_TOR; i++)
	{
		delete[] tor[i];
		tor[i] = b.tor[i];
		b.tor[i] = nullptr;
	}
	return *this;
}

void GraveTor::restart()
{
	for (int i = 0; i < SIZE_TOR; i++)
	{
		delete[] tor[i];
		tor[i] = nullptr;
	}
}

void GraveTor::print()const
{
	for (int i = 0; i < SIZE_TOR; i++)
	{
		if (tor[i] != nullptr)
			tor[i]->print();
	}
}

void GraveTor::print(char c)const
{
	for (int i = 0; i < SIZE_TOR; i++)
	{
		if (tor[i] != nullptr)
			tor[i]->print(c);
	}
}

void GraveTor::insertL(Board& brd, int xLoc)
{
	int topY = brd.getTop();
	int i;
	for (i = topY; i < topY + brd.getSize(); i++)
	{
		tor[i - 4] = new PointTor((int)Screen::MIN_X + xLoc, i, topY);
	}
}

void GraveTor::insertR(Board & brd, int xLoc)
{
	int topY = brd.getTop();
	int i;
	for (i = topY; i < topY + brd.getSize(); i++)
	{
		tor[i - 4] = new PointTor((int)Screen::MAX_X - xLoc, i, topY);
	}
}

int GraveTor::isFull()const
{
	int i;
	for (i = 0; i < SIZE_TOR; i++)
	{
		if (tor[i] == nullptr)
			return 0;
	}
	return 1;
}

bool GraveTor::isEmpty() const
{
	int i;
	for (i = 0; i < SIZE_TOR; i++)
	{
		if (tor[i] != nullptr)
			return FALSE;
	}
	return TRUE;
}

GraveTor & GraveTor::getTor()
{
	return *this;
}

const PointTor * GraveTor::getPoint(int place) const
{
	if (place < SIZE_TOR)
		return tor[place];
	return nullptr;
}

int GraveTor::getSize() const
{
	return SIZE_TOR;
}

void GraveTor::pushX(int flag)
{
	int i;
	for (i = 0; i < SIZE_TOR; i++)
	{
		if (tor[i] != nullptr && flag == 0)
			tor[i]->addToX((int)Screen::OppositeDir);
		else if (tor[i] != nullptr && flag == 1)
			tor[i]->addToX((int)Screen::SameDir);
	}
}
void GraveTor::PushBoard(GraveTor & prev, int index, int flag)
{
	for (int i = index; i < index + 3; i++)
	{
		prev.tor[i] = tor[i];
		tor[i] = nullptr;
		if (flag == 0)
			prev.tor[i]->addToX((int)Screen::OppositeDir);
		else
			prev.tor[i]->addToX((int)Screen::SameDir);
	}
}
void GraveTor::Check(GraveTor& prev, int flag)
{
	int count = 0;
	for (int i = 0; i < SIZE_TOR; i++)
	{
		if (tor[i] != nullptr)
		{
			if (tor[i]->getTop() == tor[i]->getY())
			{
				if (prev.IsEmpty(i) == 1)
				{
					if (count == 0)
					{
						print(' ');
						prev.print(' ');
					}
					PushBoard(prev, i, flag);
					count++;
				}
			}
		}
	}
	if (count != 0)
	{
		prev.print();
		print();
	}
}
int GraveTor::IsEmpty(int index)const
{
	for (int i = index; i < index + 3; i++)
	{
		if (tor[i] != nullptr)
			return 0;
	}
	return 1;
}