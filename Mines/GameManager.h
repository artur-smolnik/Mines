#pragma once
#include "IntroController.h"
#include "MinesweeperController.h"
#include "ScoreController.h"

class GameManager {
	IntroController &introController;
	MinesweeperController &minesweeperController;
	ScoreController &scoreController;

	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	//GameManager(IntroController &ic, MinesweeperController &mc, ScoreController &sc);
	GameManager(IntroController &ic, MinesweeperController &mc, ScoreController &sc);

	void draw(sf::RenderWindow &win);
	void handleEvent(sf::Event &event);
};


