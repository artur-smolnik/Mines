#include "pch.h"
#include "ScoreController.h"
#include "MinesweeperBoard.h"


ScoreController::ScoreController(ScoreView &scoreView) : scoreView(scoreView)
{
	 finished = false;	 
}

void ScoreController::handleEvent() {
	scoreView.draw();
	

	auto mouse_pos = sf::Mouse::getPosition(scoreView.getWindow()); // those two lines found on sfml forum 
	auto translated_pos = scoreView.getWindow().mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates

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
}
