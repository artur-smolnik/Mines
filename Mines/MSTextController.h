#pragma once
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"

class MSTextController
{
	MSBoardTextView msbtv;
	MinesweeperBoard minesweeperBoard;

public:
	MSTextController();
	MSTextController(MinesweeperBoard msb, MSBoardTextView msbtv);
	void move();

	
};

