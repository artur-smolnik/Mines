#include "pch.h"
#include "GameManager.h"
#include <Windows.h>



GameManager::GameManager(IntroController &ic , MSSFMLController &mc, ScoreController &sc)
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
		{
			state = SCORE;			
		}

			
		break;
	case SCORE:
		if (scoreController.playAgain())
		{
			state = INTRO;
			scoreController.setPlayAgainToFalse();
			introController.setFinishedToFalse();
			graphicController.setFinishedToFalse();			
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
		break;
	case SCORE:
		scoreController.handleEvent();
		break;
	}
	updateState();

}

void GameManager::draw() {
	updateState();
	switch (state) {
	case INTRO:
		introController.draw();
		break;
	case GAME:
		graphicController.draw();
		break;
	case SCORE:
		scoreController.draw();
		break;
	}
}
