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
	void display_mines_around(int x, int y);
};

