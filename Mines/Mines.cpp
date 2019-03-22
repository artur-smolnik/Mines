// Mines.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h> 
#include <conio.h>
#include "Rectangle.h"
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include "MSTextController.h"


using namespace std;
int main()
{	
	//const int UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77;

	srand(time(NULL));
	MinesweeperBoard board(10, 10, GameMode::HARD);
	MSBoardTextView view(board);
	MSTextController ctrl(board, view);
	ctrl.move();
	

}