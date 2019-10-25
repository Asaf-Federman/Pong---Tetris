#include "GraveYard.h"

int GraveYard::getSize() const
{
	return SIZE_YARD;
}

const GraveTor & GraveYard::getTor(int place) const
{
	if (place < SIZE_YARD)
		return arr[place];
	return arr[SIZE_YARD-1];
}

void GraveYard::insert(Board & brd, int flag)
{
	print(' ');
	if (flag == 1)
	{
		int right = Screen::MAX_X - brd.getX();
		arr[right].insertR(brd, right);

	}
	else if (flag == 0)
	{
		int left = brd.getX() - 1;
		arr[left].insertL(brd, left);
	}
	print();
}

void GraveYard::print()const
{
	int i;
	for (i = 0; i < SIZE_YARD; i++)
	{
		arr[i].print();
	}
}

void GraveYard::print(char c)const
{
	int i;
	for (i = 0; i < SIZE_YARD; i++)
	{
		arr[i].print(c);
	}
}

int GraveYard::isFull()const
{
	int i;
	for (i = 0; i < SIZE_YARD; i++)
	{
		if (arr[i].isFull())
			return i;
	}
	return -1;
}
void GraveYard::check(int flag)
{
	int i;
	for (i = 1; i < SIZE_YARD; i++)
	{
		arr[i].Check(arr[i - 1].getTor(), flag);
	}
}
bool GraveYard::isEmpty() const
{
	return (arr[0].isEmpty());
}
void GraveYard::pushArr(int index, int flag)
{
	int i;
	for (i = index; i < SIZE_YARD - 1; i++)
	{
		print(' ');
		arr[i] = arr[i + 1];
		arr[i].pushX(flag);
		print();
	}
}


void GraveYard::restart()
{
	int i;
	for (i = 0; i < SIZE_YARD; i++)
	{
		arr[i].restart();
	}
}
