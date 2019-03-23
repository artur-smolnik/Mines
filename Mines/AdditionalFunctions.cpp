#include "pch.h"
#include "AdditionalFunctions.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

AdditionalFunctions::AdditionalFunctions()
{
}

AdditionalFunctions::AdditionalFunctions(MinesweeperBoard msb)
{
	this->minesweeperBoard = msb;
}
//
//void AdditionalFunctions::debug_display_move(int x, int y)
//{
//	for (int i = 0; i < minesweeperBoard.getBoardHeight(); i++)
//	{
//		for (int j = 0; j < minesweeperBoard.getBoardWidth(); j++)
//		{
//			if (j == x && i == y)
//			{
//				cout << "{";
//			}
//			else
//			{
//				cout << "[";
//			}
//			if (minesweeperBoard.hasMine(j,i) == false)
//			{
//				cout << ".";
//			}
//			else
//			{
//				cout << "M";
//			}
//
//			if (minesweeperBoard.isRevealed(j,i) == false)
//			{
//				cout << ".";
//			}
//			else
//			{
//				cout << "o";
//			}
//
//			if (minesweeperBoard.hasFlag(j,i) == false)
//			{
//				cout << ".";
//			}
//			else
//			{
//				cout << "F";
//			}
//			if (j == x && i == y)
//			{
//				cout << "}";
//			}
//			else
//			{
//				cout << "]";
//			}
//		}
//		cout << endl;
//	}
//}
//void AdditionalFunctions::move()
//{
//	//const int UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77;
//
//	unsigned char znak;
//	int x = 0, y = 0;
//	minesweeperBoard.debug_display();
//	display_mines_around(x, y);
//	do
//	{
//		znak = _getch();
//
//		if (znak == 'f')
//		{	
//			if (!(minesweeperBoard.isRevealed(x, y) && minesweeperBoard.hasFlag(x, y)))
//			{
//				minesweeperBoard.toggleFlag(x, y);
//				system("CLS");
//				debug_display_move(x, y);
//				display_mines_around(x, y);
//			}
//		}
//		else if (znak == 'r')
//		{
//			minesweeperBoard.revealField(x, y);
//			system("CLS");
//			debug_display_move(x, y);
//			display_mines_around(x, y);
//
//		}
//		else
//		{
//
//
//			while (_kbhit())
//			{
//				znak = _getch();
//				switch (static_cast <int>(znak)) {
//				case 72:
//					if (y - 1 < 0)y = minesweeperBoard.getBoardHeight() - 1;
//					else y = y - 1;
//					system("CLS");
//					debug_display_move(x, y);
//					display_mines_around(x, y);
//					break;
//				case 80:
//					if (y + 1 >= minesweeperBoard.getBoardHeight()) y = 0;
//					else y = y + 1;
//					system("CLS");
//					debug_display_move(x, y);
//					display_mines_around(x, y);
//					break;
//				case 75:
//					if (x - 1 < 0)x = minesweeperBoard.getBoardWidth() - 1;
//					else x = x - 1;
//					system("CLS");
//					debug_display_move(x, y);
//					display_mines_around(x, y);
//					break;
//				case 77:
//					if (x + 1 >= minesweeperBoard.getBoardWidth())x = 0;
//					else x = x + 1;
//					system("CLS");
//					debug_display_move(x, y);
//					display_mines_around(x, y);
//					break;
//				default:
//					continue;
//				}
//			}
//		}
//	} while (znak != 27); //ESC
//}
//
//
//
//void AdditionalFunctions::display_mines_around(int x, int y)
//{
//	cout << "Mines around: " << minesweeperBoard.countMines(x, y) << endl;
//}
