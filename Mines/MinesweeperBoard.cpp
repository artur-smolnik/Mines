#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "MinesweeperBoard.h"


#ifndef MINESBOARD_H__
#define MINESBOARD_H__


using namespace std;
MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode ) {
	this->width = width;
	this->height = height;
	this->gameState = RUNNING;
	this->gameMode = mode;
	this->firstMove = true;
	setBoard();
	setMinesAmount();
	setMinesCords();
	setMines();	
	info = new char[6];

}

MinesweeperBoard::MinesweeperBoard()
{
}


void MinesweeperBoard::setMinesCords()  //fills vector of cords with new coordinates
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

void MinesweeperBoard::setMinesCordsFirstMove(int x, int y)  // used in revealField while during first turn user picks a field with a mine 
{
	int cordY, cordX, tmpX, tmpY;
	do {
		tmpX = 0;
		tmpY = 0;
		cordX = rand() % width;
		cordY = rand() % height;
		for (int i = 0; i < minesAmount; i++)
		{
			if (cordX == minesCords[i].x && tmpX == 0) tmpX++;
			if (cordY == minesCords[i].y && tmpY == 0) tmpY++;
		}
	} while (tmpX != 0 && tmpY !=0);

	for (int i = 0; i < minesAmount; i++)
	{
		if (minesCords[i].x == x && minesCords[i].y == y)
		{
			minesCords[i].x = cordX;
			minesCords[i].y = cordY;
		}
	}
	// Deletes the second element (vec[1])
	//vec.erase(vec.begin() + 1);
}


void MinesweeperBoard::setMines() {  // makes hasMine true according to the vector cords data
	
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


void MinesweeperBoard::setBoard()  // fills board with all fields' members set to false
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



void MinesweeperBoard::setMinesAmount()  // evaluates number of traps in our game
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





char* MinesweeperBoard::getFieldInfo(int x, int y) const
{
	
	if (x < 0 || x >= width || y < 0 || y >= height) info[0] = '#';	
	else info[0] = '*';
	if (board[x][y].hasFlag)info[1] = 'F';
	else info[0] = '*';
	if (!(board[x][y].isRevealed && board[x][y].hasMine)) info[2] = '_';
	else info[2] = '*';
	if(board[x][y].isRevealed && board[x][y].hasMine) info[3] = 'x';
	else info[3] = '*';
	if (board[x][y].isRevealed && countMines(x,y)==0) info[4]= ' ';
	else info[4] = '*';
	if (board[x][y].isRevealed && countMines(x, y) != 0) info[5] = static_cast<char>(countMines(x, y));
	else info[5] = '0';	
	
	return info;
}






void MinesweeperBoard::toggleFlag(int x, int y)
{
	if (!(x < 0 || x >= width || y < 0 || y >= height) && gameState==RUNNING)
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
		setMines();		
		firstMove = false;
	}
	else
	{
		board[x][y].isRevealed = true;
	}	
}




int MinesweeperBoard::countMines(int x, int y) const 
{	
	int minesAmount = 0;
	if (board[x][y].isRevealed)return -1;
	if (x < 0 || x >= width || y < 0 || y >= height) return -1;
	
	if (!(x - 1 < 0 || x - 1 >= width || y - 1 < 0 || y - 1 >= height) && board[x - 1][y - 1].hasMine) minesAmount++;
	if (!(x < 0 || x >= width || y - 1 < 0 || y - 1 >= height) && board[x][y - 1].hasMine) minesAmount++;
	if (!(x + 1 < 0 || x + 1 >= width || y - 1 < 0 || y - 1 >= height) && board[x + 1][y - 1].hasMine) minesAmount++;
	
	if (!(x - 1 < 0 || x - 1 >= width || y < 0 || y >= height) && board[x - 1][y].hasMine) minesAmount++;
	//if (!(x < 0 || x >= width || y < 0 || y >= height) && board[x][y].hasMine) minesAmount++;
	if (!(x + 1 < 0 || x + 1 >= width || y  < 0 || y >= height) && board[x + 1][y].hasMine) minesAmount++;
	
	if (!(x - 1 < 0 || x - 1 >= width || y + 1 < 0 || y + 1 >= height) && board[x - 1][y + 1].hasMine) minesAmount++;
	if (!(x < 0 || x >= width || y + 1 < 0 || y + 1 >= height) && board[x][y + 1].hasMine) minesAmount++;
	if (!(x + 1 < 0 || x + 1 >= width || y + 1 < 0 || y + 1 >= height) && board[x + 1][y + 1].hasMine) minesAmount++;

	return minesAmount;
}






void MinesweeperBoard::debug_display() const  
{	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << "[";

			if (board[j][i].hasMine == false)
			{
				cout << ".";
			}
			else 
			{
				cout << "M";
			}

			if (board[j][i].isRevealed == false)
			{
				cout << ".";
			}
			else
			{
				cout << "o";
			}

			if (board[j][i].hasFlag == false)
			{
				cout << ".";
			}
			else
			{
				cout << "F";
			}			
			cout << "]";
		}
		cout << endl;
	}	
}



int MinesweeperBoard::getBoardWidth() const {return width;}

int MinesweeperBoard::getBoardHeight() const { return height; }

int MinesweeperBoard::getMineCount() const { return minesAmount; }


#endif
