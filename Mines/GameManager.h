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
	
public:
	
	GameManager(IntroController &ic, GraphicController &mc, ScoreController &sc);

	void draw();
	void handleEvent();
	

};


