#pragma once
#include <SFML/Graphics.hpp>

class ScoreView {
	sf::RectangleShape rect;
	sf::Font font;
	sf::RenderWindow &renderWindow;
	sf::Text txt;

public:
	ScoreView(sf::RenderWindow &renderWindow);

	void draw();
	sf::RenderWindow &getWindow() { return renderWindow; };

	sf::RectangleShape getRectExit() { return rect; }
};

