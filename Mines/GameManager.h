#pragma once
#include "IntroController.h"
#include "ScoreController.h"
#include "MSSFMLController.h"

class GameManager {
	IntroController &introController;
	MSSFMLController &graphicController;
	ScoreController &scoreController;

	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
	
public:
	
	GameManager(IntroController &ic, MSSFMLController &mc, ScoreController &sc);

	void draw();
	void handleEvent();
	

};


