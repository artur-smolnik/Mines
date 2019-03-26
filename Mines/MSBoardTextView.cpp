#include "pch.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <iostream>

using namespace std;


//MSBoardTextView::MSBoardTextView(){}

MSBoardTextView::MSBoardTextView(MinesweeperBoard &msb)
:minesweeperBoard(msb){}





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
			cout << minesweeperBoard.getFieldInfo(j, i);
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


