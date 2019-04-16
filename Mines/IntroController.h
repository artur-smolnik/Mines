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
	
	sSettings settings;
	// IntroModel & model;
public:
	explicit IntroController(IntroView & introView);

	void handleEvent(sf::Event event);
	sSettings getSettings();

	// no need to change this
	void draw() { introView.draw(); }
	bool isFinished() const { return finished; }
};
