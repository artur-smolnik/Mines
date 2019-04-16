#pragma once
#include <SFML/Graphics.hpp>
#include "IntroView.h"
#include "MinesweeperBoard.h"

struct sSettings {
	int columns;
	int rows;
	GameMode gameMode;
};

class IntroController {
	bool finished = false;
	IntroView & introView;
	//MinesweeperBoard &minesweeperBoard;
	
	GameMode gm = DEBUG;
	int cols =0, rows=0;
	
	sSettings settings;
	// IntroModel & model;
public:
	 IntroController(IntroView & introView);

	void handleEvent(sf::Event event);
	sSettings getSettings();

	// no need to change this
	void draw();
	bool isFinished() const { return finished; }
	int getCols() { return cols; }
	int getRows() { return rows; }
	
};
