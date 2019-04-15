#include "pch.h"
#include "GameManager.h"
GameManager::GameManager(IntroController &ic , GraphicController &mc, ScoreController &sc)
	: introController(ic), graphicController(mc), scoreController(sc)
{

	state = INTRO;
}

void GameManager::updateState() {
	switch (state) {
	case INTRO:
		if (introController.isFinished())
			state = GAME;
		break;
	case GAME:
		if (graphicController.isFinished())
			state = SCORE;
		break;
	case SCORE:
		// oops - tu powinniœmy jakoœ zamkn¹æ aplikacjê
		break;
	}
}

void GameManager::handleEvent(sf::Event &event)
{
	updateState();
	switch (state) {
	case INTRO:
		introController.handleEvent(event);
		break;
	case GAME:
		graphicController.handleEvent();
		//graphicController.handleEvent(event);
		break;
	case SCORE:
		scoreController.handleEvent(event);
		break;
	}
	
}

void GameManager::draw(sf::RenderWindow &win) {
	updateState();
	switch (state) {
	case INTRO:
		introController.draw(win);
		break;
	case GAME:
		//minesweeperController.draw(win);
		break;
	case SCORE:
		scoreController.draw(win);
		break;
	}
}
