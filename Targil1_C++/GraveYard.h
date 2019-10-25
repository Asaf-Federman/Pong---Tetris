#ifndef __GRAVEYARD_H
#define __GRAVEYARD_H

#include "GraveTor.h"
#include "Board.h"
//A grave yard class which contains an array of grave lines which builds the grave yard.
class GraveYard
{
	enum { SIZE_YARD = 20 };//size of the array
	GraveTor arr[SIZE_YARD];//array of pointer of GraveTor

public:
	int getSize()const;
	const GraveTor & getTor(int place) const;//returns a gravetor by ref.
	void insert(Board & brd, int flag);//inserting new values to the array.
	void print()const;//printing the array
	void print(char c)const;
	int isFull()const;//checking if the array is full.
	void pushArr(int index, int flag);//removing the current position(index) from the array, and moving all the positions afterward back by one.
	void restart();//restarting the array with default values.
	void check(int flag);//checks if we can move any dead boards back.
	bool isEmpty() const;//checks if the graveyard is empty.
};


#endif // __GRAVEYARD_H