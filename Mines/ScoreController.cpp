//#include "pch.h"
#include "ScoreController.h"
#include "MinesweeperBoard.h"


ScoreController::ScoreController(ScoreView &scoreView) : scoreView(scoreView)
{
	 finished = false;	 
}

void ScoreController::handleEvent() {	

	auto mouse_pos = sf::Mouse::getPosition(scoreView.getWindow());         // those two lines can be found on sfml forum 
	auto translated_pos = scoreView.getWindow().mapPixelToCoords(mouse_pos); 

	if (scoreView.getRectExit().getGlobalBounds().contains(translated_pos)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			finished = true;
		}
	}
	if (scoreView.getRectPlayAgain().getGlobalBounds().contains(translated_pos)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			again = true;
			scoreView.setIsWindowSetToFalse();
			
		}
	}

}

void ScoreController::draw()
{
	scoreView.draw();
}
