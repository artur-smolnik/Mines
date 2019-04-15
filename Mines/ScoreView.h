#pragma once
#include <SFML/Graphics.hpp>

class ScoreView {
	sf::RectangleShape rect;
public:
	ScoreView();

	void draw(sf::RenderWindow &win);
};

