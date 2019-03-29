#pragma once
#include "MinesweeperBoard.h"
#include <string>
#include <SFML/Graphics.hpp>
class GraphicController
{
	int x0, y0, columns, rows, size, gap, antialiasingLevel, windowHeight, windowWidth;
	const std::string windowName;
	MinesweeperBoard &msb;
	GameMode gameMode;
	std::vector<sf::RectangleShape> rectangles;
	sf::ContextSettings settings;
	sf::RenderWindow window;
	sf::RectangleShape rectangle;
	sf::Texture texture_bomb, texture_flag, texture_0, texture_1, texture_2, texture_3, texture_4, texture_5, texture_6, texture_7, texture_8;

	
	
	
	void loadTextures();
	void setRectanglesVector();
	void eventsControl();
	void display();
public:
	GraphicController();
	GraphicController(MinesweeperBoard &msb, int x0, int y0, int columns, int rows, int size, int gap, int antialiasingLevel, int windowHeight, int windowWidth, GameMode gameMode);
	~GraphicController();
	std::vector<sf::RectangleShape> getRectanglesVector();
	
};

