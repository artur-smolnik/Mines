#pragma once
#include "IntroController.h"
#include "GraphicController.h"
#include "ScoreController.h"

class GameManager {
	IntroController &introController;
	GraphicController &graphicController;
	ScoreController &scoreController;

	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	//GameManager(IntroController &ic, MinesweeperController &mc, ScoreController &sc);
	GameManager(IntroController &ic, GraphicController &mc, ScoreController &sc);

	void draw(sf::RenderWindow &win);
	void handleEvent(sf::Event &event);
};


