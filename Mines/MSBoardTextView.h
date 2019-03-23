#pragma once
#include "MinesweeperBoard.h"
class MSBoardTextView
{
	MinesweeperBoard &minesweeperBoard;

public:
	MSBoardTextView();
	MSBoardTextView(MinesweeperBoard &msb);
	void display(int x, int y) const;

};

