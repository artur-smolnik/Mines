// Mines.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "MinesweeperBoard.h"
#include <time.h> 
#include <conio.h>
#include "AdditionalFunctions.h"
using namespace std;
int main()
{
	//const int UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77;

	srand(time(NULL));
	MinesweeperBoard minesweeperBoard(10, 10);
	AdditionalFunctions af(minesweeperBoard);
	//minesweeperBoard.debug_display();
	af.move();

	//check for version control

}