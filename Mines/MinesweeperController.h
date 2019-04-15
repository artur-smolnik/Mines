#pragma once

#include <SFML/Graphics.hpp>
#include "MinesweeperView.h"
#include "MSFMLView.h"
#include "MinesweeperBoard.h"

class MinesweeperController {
	bool finished = false;

	MinesweeperView & view;
	sf::RenderWindow &win;
	MSFMLView &mssfmLview;
	MinesweeperBoard &msb;
	// ... & model;
public:
	MinesweeperController(MinesweeperView &v, sf::RenderWindow &win, MSFMLView &mssfmLview, MinesweeperBoard &msb);
	void handleEvent(sf::Event &event);

	// no need to change this
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
};
