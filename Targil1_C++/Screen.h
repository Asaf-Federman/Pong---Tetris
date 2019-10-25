#ifndef __SCREEN_H
#define __SCREEN_H
//holds the screen limit values.
class Screen {
public:
	enum { OppositeDir = -1, CONSTANT = 0, SameDir = 1 };
	enum { DOWN = 1, UP = -1 };
	enum { MIN_X = 1, MAX_X = 79, MIN_Y = 4, MAX_Y = 24 };
	enum { EXIT = 27 };
	enum { DEFAULT_COLOR = 15 };
};

#endif // __SCREEN_H
