#include "pch.h"
#include "MSTextController.h"
//#include <cstdlib>
#include "conio.h"



MSTextController::MSTextController(MinesweeperBoard &msb, MSBoardTextView &msbtv)
	:msbtv(msbtv), minesweeperBoard(msb) {}


void MSTextController::move()
{
	//const int UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77;

	unsigned char znak;
	int x = 0, y = 0;
	msbtv.display(x, y);
	minesweeperBoard.display_mines_around(x, y);
	do
	{
		znak = _getch();

		if (znak == 'f')
		{
			if (!(minesweeperBoard.isRevealed(x, y) && minesweeperBoard.hasFlag(x, y)))
			{
				minesweeperBoard.toggleFlag(x, y);
				system("CLS");
				msbtv.display(x, y);
				minesweeperBoard.display_mines_around(x, y);
			}
		}
		else if (znak == 'r')
		{
			minesweeperBoard.revealField(x, y);
			system("CLS");
			msbtv.display(x, y);
			minesweeperBoard.display_mines_around(x, y);
		}
		else
		{
			while (_kbhit())
			{
				znak = _getch();
				switch (static_cast <int>(znak)) {
				case 72:
					if (y - 1 < 0)y = minesweeperBoard.getBoardHeight() - 1;
					else y = y - 1;
					system("CLS");
					msbtv.display(x, y);
					minesweeperBoard.display_mines_around(x, y);

					break;
				case 80:
					if (y + 1 >= minesweeperBoard.getBoardHeight()) y = 0;
					else y = y + 1;
					system("CLS");
					msbtv.display(x, y);
					minesweeperBoard.display_mines_around(x, y);

					break;
				case 75:
					if (x - 1 < 0)x = minesweeperBoard.getBoardWidth() - 1;
					else x = x - 1;
					system("CLS");
					msbtv.display(x, y);
					minesweeperBoard.display_mines_around(x, y);

					break;
				case 77:
					if (x + 1 >= minesweeperBoard.getBoardWidth())x = 0;
					else x = x + 1;
					system("CLS");
					msbtv.display(x, y);
					minesweeperBoard.display_mines_around(x, y);

					break;
				default:
					continue;
				}
			}
		}
	} while (znak != 27); //ESC
}

