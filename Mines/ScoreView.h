#pragma once
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class ScoreView {
	sf::RectangleShape rect;
	sf::Font font;
	sf::RenderWindow &renderWindow;
	sf::Text txt;
	bool isWindowSet;
	MinesweeperBoard &minesweeperBoard;

public:
	ScoreView(sf::RenderWindow &renderWindow, MinesweeperBoard &minesweeperBoard);

	void draw();
	sf::RenderWindow &getWindow() { return renderWindow; };
	sf::RectangleShape getRectExit() { return rect; }
};

