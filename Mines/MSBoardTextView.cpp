#include "pch.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <iostream>


MSBoardTextView::MSBoardTextView(MinesweeperBoard msb)
{
	this->minesweeperBoard = msb;
}


void MSBoardTextView::display() const
{
	minesweeperBoard.debug_display();	
}


