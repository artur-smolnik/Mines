#pragma once
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"

class MSFMLView
{
	int x0, y0, columns, rows, size, gap, windowHeight, windowWidth;
	const std::string windowName;
	MinesweeperBoard &msb;
	
	std::vector<sf::RectangleShape> rectangles;
	
	sf::RenderWindow &window;
	sf::RectangleShape rectangle;
	sf::Texture texture_bomb, texture_flag, texture_0, texture_1, texture_2, texture_3, texture_4, texture_5, texture_6, texture_7, texture_8;

	
public:
	
	MSFMLView(MinesweeperBoard &msb, sf::RenderWindow &window, int x0, int y0, int columns, int rows, int size, int gap);
	void draw();
};

