#pragma once

struct Field
{
	bool hasMine;
	bool isRevealed;
	bool hasFlag;	
};

class MinesweeperBoard
{
	enum GameMode { DEBUG, EASY, NORMAL, HARD };
	enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
	GameMode difficultyLevel;
	GameState gameState;
	int width;
	int height;
	Field board[100][100];
	void setBoard();
	void setMines(GameMode gameMode);
	
	void toggleFlag(int x, int y);
	void revealField(int x, int y);
	
//	private
public:
	MinesweeperBoard();
	MinesweeperBoard(int width, int height);
	
	int countMines(int x, int y) const;			
	void debug_display() const;
	void display_info(int x, int y);
	char getFieldInfo(int x, int y) const;
	bool hasFlag(int x, int y) const;
	bool hasMine(int x, int y) const;
	bool isRevealed(int x, int y) const;
	


	int getBoardWidth() const;
	int getBoardHeight() const;
	
	
};