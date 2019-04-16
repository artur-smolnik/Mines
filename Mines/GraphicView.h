#pragma once
#include "MinesweeperBoard.h"
#include <string>
#include <SFML/Graphics.hpp>
class GraphicView
{
	int x0, y0, columns, rows, size, gap;

	MinesweeperBoard &msb;
	GameMode gameMode;
	std::vector<sf::RectangleShape> rectangles;

	sf::RenderWindow &renderWindow;
	sf::Texture texture_bomb, texture_flag, texture_0, texture_1, texture_2, texture_3, texture_4, texture_5, texture_6, texture_7, texture_8;

	void loadTextures();
	void setRectanglesVector();

public:
	GraphicView(MinesweeperBoard &msb, sf::RenderWindow &renderWindow);
	
	void display();
	void draw();

	std::vector<sf::RectangleShape> &getRectangles();
	int getColumns();
};

