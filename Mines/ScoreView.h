#pragma once
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class ScoreView {
	sf::RectangleShape rect_exit;
	sf::RectangleShape rect_play_again;
	sf::Font font;
	sf::RenderWindow &renderWindow;
	sf::Text txt;
	bool isWindowSet; //prevent from window flickering
	MinesweeperBoard &minesweeperBoard;

public:
	ScoreView(sf::RenderWindow &renderWindow, MinesweeperBoard &minesweeperBoard);
	
	void draw();
	sf::RenderWindow &getWindow() { return renderWindow; };
	sf::RectangleShape getRectExit() { return rect_exit; }	
	sf::RectangleShape getRectPlayAgain() { return rect_play_again; }
	void setIsWindowSetToFalse() { isWindowSet = false; }
};

