#pragma once
#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
class MSSFMLController
{	
	MinesweeperBoard &minesweeperBoard;
	MSSFMLView &mSSFMLView;	
	bool finished = false;

public:
	MSSFMLController();
	MSSFMLController(MSSFMLView &mSSFMLView, MinesweeperBoard &minesweeperBoard);
	void draw();
	void handleEvent();	
	bool isFinished() const;
	void setFinishedToFalse() { finished = false; }

};

