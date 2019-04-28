#include "pch.h"
#include "GameManager.h"
#include "ScoreController.h"

void GameManager::playAgain(bool playAgain)
{
	if (playAgain) state = INTRO;
}
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
		if (scoreController.playAgain())
		{
			state = INTRO;
			scoreController.setPlayAgainToFalse();
			introController.setFinishedToFalse();
			graphicController.setFinishedToFalse();
			//handleEvent();
			//introController.handleEvent();
		}
		if(scoreController.isFinished()) exit(0);
		break;
	}
}

void GameManager::handleEvent()
{
	switch (state) {
	case INTRO:
		
		introController.handleEvent();
		break;
	case GAME:
		graphicController.handleEvent();
		//graphicController.handleEvent(event);
		break;
	case SCORE:
		scoreController.handleEvent();
		break;
	}
	updateState();

}

void GameManager::draw(sf::RenderWindow &win) {
	updateState();
	switch (state) {
	case INTRO:
		//introController.draw();
		break;
	case GAME:
		//minesweeperController.draw(win);
		break;
	case SCORE:
		//scoreController.draw();
		break;
	}
}
