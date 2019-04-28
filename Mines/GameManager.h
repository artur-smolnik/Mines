#pragma once
#include "IntroController.h"
#include "ScoreController.h"
#include "GraphicController.h"

class GameManager {
	IntroController &introController;
	GraphicController &graphicController;
	ScoreController &scoreController;

	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
	void playAgain(bool playAgain);
public:
	//GameManager(IntroController &ic, MinesweeperController &mc, ScoreController &sc);
	GameManager(IntroController &ic, GraphicController &mc, ScoreController &sc);

	void draw(sf::RenderWindow &win);
	void handleEvent();
	

};


