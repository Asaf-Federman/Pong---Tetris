#ifndef __POINT_H
#define __POINT_H
#include <iostream>
#include "utils.h"
#include "Screen.h"
#include <stdio.h>
using namespace std;
class Point
{
	int m_x, m_y;
	const char ch;
public:
	Point(int x,int y,char ch);//constructor
	void move(int x = 0, int y = 0);//add/substract from the point's coordinates.
	void print(char c)const;//print the point's character.
	void print()const;//overloading
	int compare(const Point & p) const;
	int checkX()const;//check if the x coordinate reached limit limitation
	int checkY()const;//check if the y coordinate reached limit limitation
	int getX()const;//returning the x coordinate.
	int getY()const;//returning the y coordinate.
	int & getY();//returns Y coordinate by ref
	int & getX();//returns X coordinate by ref.
	void setX(int x);//sets X value.
	void setY(int y);//sets Y value.
	void addToX(int x);//adding/substracting from X coordinate.
	void addToY(int y);//adding/substracting from Y coordinate.
	void setValue(int x, int y);//gives the point new coordinates.
};



#endif 