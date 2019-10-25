#include "Ball.h"
#include "playerBoard.h"
#include "computerBoard.h"
#include <conio.h>
#include "screenManager.h"


screenManager::screenManager()
{
	brd[Board::LEFT] = nullptr;
	brd[Board::RIGHT] = nullptr;
	ShowConsoleCursor(false);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Screen::DEFAULT_COLOR);
	consoleManage();
}

void screenManager::print()
{
	ball.print();
	brd[Board::LEFT]->print();
	brd[Board::RIGHT]->print();
}

void screenManager::sleepFunc()
{
	Sleep(65);
}

void screenManager::consoleManage()
{
	printMenu();
	char c;
	c = _getch();
	switch (c)
	{
	case('1'):
	{
		brd[Board::LEFT] = new playerBoard(4, 10);
		brd[Board::RIGHT] = new playerBoard(76, 10);
		startGame();
	}
	break;
	case('2'):
	{
		getLevelMenu(1);
		brd[Board::LEFT] = new playerBoard(4, 10);
		startGame();
	}
	break;
	case('3'):
	{
		getLevelMenu(2);
		startGame();
	}
	break;
	case('8'):
		instruction();
		break;
	case('9'):
	case(Screen::EXIT):
		break;
	default:
		instruction();
		break;
	}
}

void screenManager::consoleManage(char k)
{
	printMenu(k);
	char c;
	c = _getch();
	switch (c)
	{
	case('1'):
	{
		restart();
		delete[] brd[Board::LEFT];
		delete[] brd[Board::RIGHT];
		brd[Board::LEFT] = new playerBoard(4, 10);
		brd[Board::RIGHT] = new playerBoard(76, 10);
		startGame();
	}
	break;
	case('2'):
	{
		restart();
		delete[] brd[Board::LEFT];
		delete[] brd[Board::RIGHT];
		getLevelMenu(1);
		brd[Board::LEFT] = new playerBoard(4, 10);
		startGame();
	}
	break;
	case('3'):
	{
		restart();
		delete[] brd[Board::LEFT];
		delete[] brd[Board::RIGHT];
		getLevelMenu(2);
		startGame();
	}
	break;
	case('4'):
	{
		if (k == '1')
			startGame();
		else if (k == '2')
			startGame();
		else if (k == '3')
			startGame();
	}
	break;
	case('8'):
		instruction(Screen::EXIT);
		break;
	case('9'):
	case(Screen::EXIT):
	{
		delete[] brd[0];
		delete[] brd[1];
		brd[0] = nullptr;
		brd[1] = nullptr;
	}
	break;
	default:
	{
		delete[] brd[0];
		delete[] brd[1];
		brd[0] = nullptr;
		brd[1] = nullptr;
	}
	break;
	}
}
void screenManager::restart()
{
	playerBoard::getCountL() = -1;
	playerBoard::getCountR() = -1;
	ballBehavior::getCounter() = 0;
	ball.restart();
	yardR.restart();
	yardL.restart();
}
int screenManager::interSection()
{
	int x = ball.getX();
	ball.restart();
	brd[Board::LEFT]->print();
	brd[Board::RIGHT]->print();
	yardR.print();
	yardL.print();
	Sleep(150);
	int index = 0;
	if (x < LSCREEN)
	{
		yardL.insert(*brd[Board::LEFT], 0);
		brd[Board::LEFT]->changePos(1);
	}
	else if (x > RSCREEN)
	{
		yardR.insert(*brd[Board::RIGHT], 1);
		brd[Board::RIGHT]->changePos(-1);
	}
	int endGameR = brd[Board::RIGHT]->endGame(Board::RIGHT);
	int endGameL = brd[Board::LEFT]->endGame(Board::LEFT);
	if (endGameR == TRUE || endGameL == TRUE)
	{

		char c;
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 1);
		gotoxy(30, 8);
		cout << "~~~~~~ Game Over ~~~~~~~" << endl;
		gotoxy(30, 10);
		if (endGameR == TRUE)
			cout << "PLAYER LEFT WON !!! ";
		else
			cout << "PLAYER RIGHT WON !!! ";
		gotoxy(30, 12);
		Sleep(150);
		cout << "Press any key to continue" << endl;
		SetConsoleTextAttribute(hConsole, Screen::DEFAULT_COLOR);
		c = _getch();
		if (c = ' ')
			return TRUE;
		else
			return TRUE;
	}
	return FALSE;
}
void screenManager::printLimits()
{
	int i;
	for (i = 1; i <= Screen::MAX_X + 1; i++)
	{
		gotoxy(i, 3);
		cout << ",";
		gotoxy(i, 25);
		cout << "'";
	}
	for (i = Screen::MIN_Y; i <= Screen::MAX_Y; i++)
	{
		gotoxy(Screen::MAX_X + 1, i);
		cout << "|";
	}
}

void screenManager::startGame()
{
	int check = FALSE;
	char k = '0';
	system("cls");
	printLimits();
	yardL.print();
	yardR.print();
	print();
	playerBoard* playerArr[2];
	computerBoard* computerArr[2];
	playerArr[Board::LEFT] = dynamic_cast<playerBoard *>(brd[Board::LEFT]);
	playerArr[Board::RIGHT] = dynamic_cast<playerBoard *>(brd[Board::RIGHT]);
	computerArr[Board::LEFT] = dynamic_cast<computerBoard *>(brd[Board::LEFT]);
	computerArr[Board::RIGHT] = dynamic_cast<computerBoard *>(brd[Board::RIGHT]);
	do {
		ball.move();
		if (check == TRUE)
		{
			brd[Board::LEFT]->print();
			brd[Board::RIGHT]->print();
		}
		yardL.check(0);
		yardR.check(1);
		check = ball.Behave(brd[Board::LEFT], brd[Board::RIGHT], yardL, yardR);
		if (check == 2)
			if (interSection() == TRUE)
				break;
		int index = yardR.isFull();
		if (index != -1)
		{
			yardR.pushArr(index, 1);
			brd[Board::RIGHT]->changePos(+5);
		}
		index = yardL.isFull();
		if (index != -1)
		{
			yardL.pushArr(index, 0);
			brd[Board::LEFT]->changePos(-5);
		}
		if (playerArr[Board::LEFT] && playerArr[Board::RIGHT])
		{
			k = move(playerArr[Board::LEFT], ball, playerArr[Board::RIGHT]);
		}
		else if (playerArr[Board::LEFT] && computerArr[Board::RIGHT])
		{
			k = move(playerArr[Board::LEFT], ball);
			computerArr[Board::RIGHT]->moveRight(ball);
		}
		else
		{
			computerArr[Board::LEFT]->moveLeft(ball);
			computerArr[Board::RIGHT]->moveRight(ball);
			if (_kbhit())
			{
				k = _getch();
			}
		}
		sleepFunc();
	} while (k != Screen::EXIT);
	k = '2';
	system("cls");
	consoleManage(k);
}

void screenManager::getLevelMenu(int numOfPlayers)
{
	system("cls");
	char c;
	int lvl;
	cout << "Please enter the difficulty for the computer on the right : " << endl;
	cout << "(a) BEST" << endl;
	cout << "(b) GOOD" << endl;
	cout << "(c) NOVICE" << endl;
	c = tolower(_getch());
	switch (c) {
	case 'a': lvl = computerBoard::BEST;
		break;
	case 'b': lvl = computerBoard::GOOD;
		break;
	case 'c': lvl = computerBoard::NOVICE;
		break;
	default:
		lvl = computerBoard::NOVICE;
		break;
	}
	brd[Board::RIGHT] = new computerBoard(76, 10, lvl);

	if (numOfPlayers == 2)
	{
		cout << "Please enter the difficulty for the computer on the right : " << endl;
		cout << "(a) BEST" << endl;
		cout << "(b) GOOD" << endl;
		cout << "(c) NOVICE" << endl;
		c = tolower(_getch());
		switch (c) {
		case 'a': lvl = computerBoard::BEST;
			break;
		case 'b': lvl = computerBoard::GOOD;
			break;
		case 'c': lvl = computerBoard::NOVICE;
			break;
		default:
			lvl = computerBoard::NOVICE;
			break;
		}
		brd[Board::LEFT] = new computerBoard(4, 10, lvl);
	}

}
void screenManager::instruction(char c)
{
	cout << "INSTRUCTIONS!" << endl;
	cout << "You can play in the following modes :" << endl;
	cout << "A player vs player \nA player vs the machine (the player will always be on the left)\nThe machine against the machine" << endl;
	cout << "The keys for player 1 (left player) are :" << endl;
	cout << "To move the board up press Q or q" << endl;
	cout << "To move the board down press A or a" << endl;
	cout << "The keys for player 2 (right player) are :" << endl;
	cout << "To move the board up press P or p" << endl;
	cout << "To move the board down press L or l" << endl;
	cout << "Once a player misses the ball,his board will appear on the lowest position of his side of the screen." << endl;
	cout << "Incase dropped boards complete a full line, the entire line would disappear and the board would go back five lines" << endl;
	cout << "The game will end once a player's board gets to far from his starting position\n" << endl;
	consoleManage(c);
}

void screenManager::printMenu(char k)
{
	cout << "MENU" << endl;
	cout << "Please enter the key below" << endl;
	cout << "(1) Start a new game - a player against a player" << endl;
	cout << "(2) Start a new game - a player against the machine" << endl;
	cout << "(3) Start a new game - the machine against the machine" << endl;
	if (k == '1' || k == '2' || k == '3')
		cout << "(4) Continue a paused game" << endl;
	cout << "(8) Instructions and keys" << endl;
	cout << "(9) EXIT\n" << endl;
}

