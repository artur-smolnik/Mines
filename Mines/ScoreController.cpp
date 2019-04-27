#include "pch.h"
#include "ScoreController.h"

ScoreController::ScoreController(ScoreView &scoreView) : scoreView(scoreView) {}

void ScoreController::handleEvent(sf::Event &event) {
	scoreView.draw();
	

	auto mouse_pos = sf::Mouse::getPosition(scoreView.getWindow()); // Mouse position relative to the window
	auto translated_pos = scoreView.getWindow().mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates

	if (scoreView.getRectExit().getGlobalBounds().contains(translated_pos)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			exit(0);
		}
	}

}

void ScoreController::draw()
{
}
