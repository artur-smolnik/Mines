#include "pch.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <iostream>

using namespace std;


MSBoardTextView::MSBoardTextView()
{
}

MSBoardTextView::MSBoardTextView(MinesweeperBoard &msb)
{
	minesweeperBoard = msb;
}


void MSBoardTextView::display(int x, int y) const
{
	for (int i = 0; i < minesweeperBoard.getBoardHeight(); i++)
	{
		for (int j = 0; j < minesweeperBoard.getBoardWidth(); j++)
		{
			if (j == x && i == y)
			{
				cout << "{";
			}
			else
			{
				cout << "[";
			}
			if (minesweeperBoard.hasMine(j, i) == false)
			{
				cout << ".";
			}
			else
			{
				cout << "M";
			}

			if (minesweeperBoard.isRevealed(j, i) == false)
			{
				cout << ".";
			}
			else
			{
				cout << "o";
			}

			if (minesweeperBoard.hasFlag(j, i) == false)
			{
				cout << ".";
			}
			else
			{
				cout << "F";
			}
			if (j == x && i == y)
			{
				cout << "}";
			}
			else
			{
				cout << "]";
			}
		}
		cout << endl;
	}

}


