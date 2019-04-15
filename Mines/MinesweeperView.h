#pragma once
#include <SFML/Graphics.hpp>
#include "MSFMLView.h"

class MinesweeperView {
	//    sf::Clock clk;
	//    sf::Font font;
	//    sf::Text txt;
	MSFMLView &mssfmLview;
public:
	//MinesweeperView();
	MinesweeperView(MSFMLView &mssfmLview);
	void draw(sf::RenderWindow &win);
};