#ifndef __GRAVETOR_H
#define __GRAVETOR_H

#include "Board.h"
#include "PointTor.h"
//A grave line class which contains an array of points which builds the morgue of boards.
class GraveTor
{
	enum { SIZE_TOR = 21 };
	PointTor* tor[SIZE_TOR];
public:
	GraveTor();//constructor.
	GraveTor(const GraveTor & b) = delete;
	GraveTor & operator=(GraveTor &b);//creates a SHALLOW copy of GraveTor.
	void restart();//restarts the gravetor
	void print()const;//prints
	void print(char c)const;//prints
	void insertL(Board & brd, int xLoc);//inserting a dead board to the left location.
	void insertR(Board & brd, int xLoc);//inserting a dead board to the right location.
	int isFull()const;//checks if the array is full
	bool isEmpty()const;//checks if the array is empty
	GraveTor & getTor();//returns the gravetor by ref.
	const PointTor * getPoint(int place) const;//returns a pointer to point from the array in the needed place.
	int getSize()const;//returns the size.
	void pushX(int flag);//pushes the entire line to the back.
	void Check(GraveTor & prev, int flag);//checks if their space for a dead board.
	int IsEmpty(int index)const;//checks if the location is empty.
	void PushBoard(GraveTor & prev, int index, int flag);//push the dead board to it's new location.
	~GraveTor()//destructor.
	{
		int i;
		for (i = 0; i < SIZE_TOR; i++)
		{
			delete[] tor[i];
		}
	}
};




#endif // __GRAVETOR_