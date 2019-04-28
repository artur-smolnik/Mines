#pragma once
#include <SFML/Graphics.hpp>
#include "ScoreView.h"

class ScoreController {
	
	ScoreView &scoreView;
	
	bool finished;
	bool again = false;

public:
	ScoreController(ScoreView &scoreView);
	void handleEvent();
	
	void draw();
	bool isFinished() const { return finished; }
	bool playAgain()  { return again; }
	void setPlayAgainToFalse() { again = false; }
	void setFinishedToFalse() { finished = false; }
};

