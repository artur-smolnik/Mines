#include "pch.h"
#include "ScoreController.h"
#include "MinesweeperBoard.h"


ScoreController::ScoreController(ScoreView &scoreView) : scoreView(scoreView)
{
	 finished = false;
	 //playAgain = false;
}

void ScoreController::handleEvent() {
	scoreView.draw();
	

	auto mouse_pos = sf::Mouse::getPosition(scoreView.getWindow()); // Mouse position relative to the window
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
			
		}
	}

}

void ScoreController::draw()
{
}
