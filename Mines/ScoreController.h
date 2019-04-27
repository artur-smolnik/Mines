#pragma once
#include <SFML/Graphics.hpp>
#include "ScoreView.h"

class ScoreController {
	bool finished = false;
	ScoreView &scoreView;
public:
	explicit ScoreController(ScoreView &scoreView);
	void handleEvent(sf::Event &event);

	// no need to change this
	void draw();
	bool isFinished() const { return finished; }
};

