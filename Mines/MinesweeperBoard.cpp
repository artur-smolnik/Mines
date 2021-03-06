//#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include "MinesweeperBoard.h"


#ifndef MINESBOARD_H__  // in other classes im using #pragma once because it's generated automatically in visual studio 
#define MINESBOARD_H__


using namespace std;


MinesweeperBoard::MinesweeperBoard()
{	
	this->gameState = RUNNING;	
	this->firstMove = true;
	this->remainingMines = getMineCount();
}


void MinesweeperBoard::setWidthAndHeightAndGameMode(int width, int height, GameMode gameMode)
{		
	this->firstMove = true;
	minesCords.clear();
	this->width = width;
	this->height = height;
	this->gameMode = gameMode;
	setBoard();
	setMinesAmount();
	setMinesCords();
	setMines();
	this->remainingMines = getMineCount();
}

//fills vector of cords with new coordinates
void MinesweeperBoard::setMinesCords()  
{
	int cordX, cordY;
	for (int i = 0; i < minesAmount; i++)
	{
		do
		{
			cordX = rand() % width;
			cordY = rand() % height;
		} while (board[cordX][cordY].hasMine);

		mineCords tmp;
		tmp.x = cordX;
		tmp.y = cordY;
		minesCords.push_back(tmp);
	}
}

// used in revealField while  first turn user picks a field with a mine 
void MinesweeperBoard::setMinesCordsFirstMove(int x, int y)  
{
	int cordY, cordX, tmp;
	do {
		tmp = 0;
		cordX = rand() % width;
		cordY = rand() % height;
		for (int i = 0; i < minesAmount; i++)
		{
			if (cordX == minesCords[i].x && cordY == minesCords[i].y) tmp++;
		}
	} while (tmp != 0);

	for (int i = 0; i < minesAmount; i++)
	{
		if (minesCords[i].x == x && minesCords[i].y == y)
		{
			board[x][y].hasMine = false;
			board[cordX][cordY].hasMine = true;
			minesCords[i].x = cordX;
			minesCords[i].y = cordY;
			break;
		}
	}
}

// makes hasMine true according to the vector minesCords data
void MinesweeperBoard::setMines() {  

	if (gameMode != DEBUG)
	{
		for (int i = 0; i < minesAmount; i++)
		{
			board[minesCords[i].x][minesCords[i].y].hasMine = true;
		}
	}
	else
	{
		for (int i = 0; i < width; i++)
		{
			board[i][0].hasMine = true;
		}
		for (int i = 0; i < height; i += 2)
		{
			board[0][i].hasMine = true;
		}

		for (int i = 0; i <= height && i <= width; i++)
		{
			board[i][i].hasMine = true;
		}
	}

}

// fills board with all fields' members set to false
void MinesweeperBoard::setBoard()  
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			board[j][i].hasMine = false;
			board[j][i].isRevealed = false;
			board[j][i].hasFlag = false;
		}
	}
}


// evaluates number of traps in our game
void MinesweeperBoard::setMinesAmount()  
{
	if (gameMode != DEBUG)
	{
		switch (gameMode)
		{
		case EASY:
			minesAmount = (width*height) / 10;
			break;
		case NORMAL:
			minesAmount = (width*height) / 5;
			break;
		case HARD:
			minesAmount = (width*height) / 3;
			break;
		default:
			break;
		}
	}
}

void MinesweeperBoard::setGameState(int x, int y)  // niezywane
{
	if (getFieldInfo(x, y) == 'x')
	{
		gameState = FINISHED_LOSS;
		return;
	}
	else if (getFieldInfo(x, y) != '#' && getFieldInfo(x, y) != 'F' && getFieldInfo(x, y) != '_')
	{
		remainingMines--;
		if (remainingMines == 0) gameState = FINISHED_WIN;

	}
}




char MinesweeperBoard::getFieldInfo(int x, int y) const
{
	if (x < 0 || x >= width || y < 0 || y >= height) return '#';
	if (board[x][y].hasFlag) return 'F';
	if (!(board[x][y].isRevealed || board[x][y].hasFlag)) return '_';
	if (board[x][y].isRevealed && board[x][y].hasMine) return 'x';
	if (board[x][y].isRevealed && countMines(x, y) == 0) return ' ';
	if (board[x][y].isRevealed && countMines(x, y) != 0)
	{
		return static_cast<char>(countMines(x, y)+48);
	}	
}

void MinesweeperBoard::toggleFlag(int x, int y)
{
	if (!(x < 0 || x >= width || y < 0 || y >= height) && gameState == RUNNING)
	{
		if (board[x][y].isRevealed == false && board[x][y].hasFlag == false) board[x][y].hasFlag = true;
	}
}

bool MinesweeperBoard::hasFlag(int x, int y) const
{
	if (!(x < 0 || x >= width || y < 0 || y >= height || board[x][y].isRevealed)) return board[x][y].hasFlag;
	else return false;

}



bool MinesweeperBoard::hasMine(int x, int y) const
{
	if (!(x < 0 || x >= width || y < 0 || y >= height)) return board[x][y].hasMine;
}


bool MinesweeperBoard::isRevealed(int x, int y) const
{
	if (!(x < 0 || x >= width || y < 0 || y >= height))
		return board[x][y].isRevealed;
}


void MinesweeperBoard::revealField(int x, int y)
{
	if (x < 0 || x >= width || y < 0 || y >= height) return;

	if (board[x][y].isRevealed || gameState != RUNNING || board[x][y].hasFlag) return;

	if (board[x][y].hasMine && firstMove)
	{
		setMinesCordsFirstMove(x, y);
		firstMove = false;
		board[x][y].isRevealed = true;
	}
	else
	{
		board[x][y].isRevealed = true;
		firstMove = false;
	}
}




int MinesweeperBoard::countMines(int x, int y) const
{
	int minesAmount = 0;	

	if (!(x - 1 < 0 || x - 1 >= width || y - 1 < 0 || y - 1 >= height) && board[x - 1][y - 1].hasMine) minesAmount++;
	if (!(x < 0 || x >= width || y - 1 < 0 || y - 1 >= height) && board[x][y - 1].hasMine) minesAmount++;
	if (!(x + 1 < 0 || x + 1 >= width || y - 1 < 0 || y - 1 >= height) && board[x + 1][y - 1].hasMine) minesAmount++;

	if (!(x - 1 < 0 || x - 1 >= width || y < 0 || y >= height) && board[x - 1][y].hasMine) minesAmount++;
	if (!(x + 1 < 0 || x + 1 >= width || y < 0 || y >= height) && board[x + 1][y].hasMine) minesAmount++;

	if (!(x - 1 < 0 || x - 1 >= width || y + 1 < 0 || y + 1 >= height) && board[x - 1][y + 1].hasMine) minesAmount++;
	if (!(x < 0 || x >= width || y + 1 < 0 || y + 1 >= height) && board[x][y + 1].hasMine) minesAmount++;
	if (!(x + 1 < 0 || x + 1 >= width || y + 1 < 0 || y + 1 >= height) && board[x + 1][y + 1].hasMine) minesAmount++;

	return minesAmount;
}





void MinesweeperBoard::display_mines_around(int x, int y)
{
	cout << "Mines around: " << countMines(x, y) << endl;
}



int MinesweeperBoard::getBoardWidth() const { return this->width; }

int MinesweeperBoard::getBoardHeight() const { return this->height; }

int MinesweeperBoard::getMineCount() const
{
	int remainingMines = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[j][i].hasMine && !board[j][i].hasFlag) remainingMines++;
		}
	}
	return remainingMines;
}

GameState MinesweeperBoard::getGameState() 
{
	int revealedFields = 0;
	if (!getMineCount()) return FINISHED_WIN;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[j][i].isRevealed && board[j][i].hasMine) return FINISHED_LOSS;
			
		}
	}	
	return RUNNING;

}
#endif
