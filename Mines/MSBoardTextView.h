#pragma once
#include "MinesweeperBoard.h"
class MSBoardTextView
{
	MinesweeperBoard minesweeperBoard;

public:
	MSBoardTextView(MinesweeperBoard msb);
	//void debug_display(minesweeperBoard) const;
	void display() const;

};

