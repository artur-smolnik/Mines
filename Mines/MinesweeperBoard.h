#pragma once
#include <vector>

struct Field
{
	bool hasMine;
	bool isRevealed;
	bool hasFlag;	
};

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

class MinesweeperBoard
{
	struct mineCords
	{ 
		int x, y;
	};

	
	GameMode gameMode;
	GameState gameState;
	int width, height, minesAmount;
	Field board[100][100];
	char* info;
	std::vector<mineCords> minesCords;
	void setMinesCords();
	void setMinesCords(int x, int y);
	void setBoard();
	void setMines(int minesAmount);
	void setMinesAmount(GameMode gameMode);	
	

public:
	MinesweeperBoard();
	MinesweeperBoard(int width, int height, GameMode mode);
	
	int countMines(int x, int y) const;			
	int getBoardWidth() const;
	int getBoardHeight() const;
	int getMineCount() const;
	char* getFieldInfo(int x, int y) const;
	bool hasFlag(int x, int y) const;
	bool hasMine(int x, int y) const;
	bool isRevealed(int x, int y) const;
	
	void debug_display() const;
	void display_mines_around(int x, int y); //additional func
	void toggleFlag(int x, int y);
	void revealField(int x, int y);	
	
	
};