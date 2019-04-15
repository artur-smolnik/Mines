#pragma once
#include <SFML/Graphics.hpp>
#include "IntroView.h"
enum IntroGameMode { INTRO_EASY, INTRO_NORMAL, INTRO_HARD };
enum IntroSize { intro_small, intro_normal, intro_big };


class IntroController {
	bool finished = false;
	IntroView & view;
	IntroGameMode introGameMode;
	IntroSize introSize;
	
	// IntroModel & model;
public:
	explicit IntroController(IntroView & iv);

	void handleEvent(sf::Event &event);

	// no need to change this
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
};
