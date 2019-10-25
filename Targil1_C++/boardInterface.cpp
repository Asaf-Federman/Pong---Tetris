//#include "boardInterface.h"
//
//void boardInterface::move(char c)
//{
//	switch (c) {
//	case 'q':
//	case 'Q':
//		brd[0].print(' ');
//		brd[0].move(Screen::UP);
//		brd[0].print();
//		break;
//	case 'a':
//	case 'A':
//		brd[0].print(' ');
//		brd[0].move(Screen::DOWN);
//		brd[0].print();
//		break;
//	case 'p':
//	case 'P':
//		brd[1].print(' ');
//		brd[1].move(Screen::UP);
//		brd[1].print();
//		break;
//	case 'l':
//	case 'L':
//		brd[1].print(' ');
//		brd[1].move(Screen::DOWN);
//		brd[1].print();
//		break;
//	default:
//		break;
//	}
//}
//void boardInterface:: print()const
//{
//	brd[LEFT].print();
//	brd[RIGHT].print();
//}
//
//int boardInterface::intersection(Ball &b)
//{
//	if (brd[LEFT].HandleLeft(b) == 2 || brd[RIGHT].HandleRight(b) == 2)
//		return 2;
//	return 1;
//}
//
//void boardInterface::restart()
//{
//	brd[LEFT].restart(4,10);
//	brd[RIGHT].restart(76,10);
//}
//
//Board & boardInterface::getL()
//{
//	return brd[LEFT];
//}
//
//Board & boardInterface::getR()
//{
//	return brd[RIGHT];
//}
//
//int boardInterface::endGame()const
//{
//	if (brd[RIGHT].endGame() == 1 )
//		return RIGHT;
//	else if (brd[LEFT].endGame() == 1)
//		return LEFT;
//	return -1;
//}
