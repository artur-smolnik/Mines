#pragma once
#include <SFML/Graphics.hpp>
#include "IntroView.h"
#include "MinesweeperBoard.h"

struct sSettings {
	int columns =0;
	int rows = 0;
	GameMode gameMode;
};

class IntroController {
	bool finished = false;
	IntroView & introView;
	
	sSettings settings;
	// IntroModel & model;
public:
	explicit IntroController(IntroView & introView);

	void handleEvent();
	sSettings getSettings();

	// no need to change this
	void draw();
	bool isFinished() const { return finished; }
};
