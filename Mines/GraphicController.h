#pragma once
#include "SFML/Graphics.hpp"
#include "MinesweeperView.h"
#include "MinesweeperBoard.h"
class GraphicController
{	
	MinesweeperBoard &minesweeperBoard;
	GraphicView &graphicView;	
	bool finished = false;

public:
	GraphicController();
	GraphicController(GraphicView &graphicView, MinesweeperBoard &minesweeperBoard);
	void draw();
	void handleEvent();	
	bool isFinished() const;
	void setFinishedToFalse() { finished = false; }

};

