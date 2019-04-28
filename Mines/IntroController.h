#pragma once
#include <SFML/Graphics.hpp>
#include "IntroView.h"
#include "MinesweeperBoard.h"
#include "GraphicView.h"

struct sSettings {
	int columns;
	int rows;
	GameMode gameMode;
};

class IntroController {
	bool finished = false;
	IntroView & introView;
	MinesweeperBoard &minesweeperBoard;
	GraphicView &graphicView;	
	sSettings settings;
	
public:
	IntroController(IntroView & introView, GraphicView &graphicView, MinesweeperBoard &minesweeperBoard);

	void handleEvent();
	sSettings getSettings();

	void draw();
	bool isFinished() const { return finished; }	
	void setFinishedToFalse() { finished = false; }
	
};
