#pragma once
#include "MinesweeperBoard.h"
class AdditionalFunctions
{
	MinesweeperBoard minesweeperBoard;

public:
	AdditionalFunctions();
	AdditionalFunctions(MinesweeperBoard msb);
	
	void debug_display_move(int x, int y); //additional
	void move();  //additional
};

