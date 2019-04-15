#pragma once
#include "MinesweeperBoard.h"
#include <string>
#include <SFML/Graphics.hpp>
//MSSFMLview(int squarsize,Minesweeperboard &msb,int square_position_x,int square_position_y,sf::RenderWindow &win);

class GraphicView
{
	int x0, y0, columns, rows, size, gap, windowHeight, windowWidth;
	const std::string windowName;
	MinesweeperBoard &msb;
	GameMode gameMode;
	std::vector<sf::RectangleShape> rectangles;
	
	sf::RenderWindow &window;
	sf::RectangleShape rectangle;
	sf::Texture texture_bomb, texture_flag, texture_0, texture_1, texture_2, texture_3, texture_4, texture_5, texture_6, texture_7, texture_8;

	
	
	
	
	
public:
	GraphicView();
	GraphicView(MinesweeperBoard &msb, sf::RenderWindow &window, int x0, int y0, int columns, int rows, int size, int gap,  int windowHeight, int windowWidth, GameMode gameMode);
	/*
	std::vector<sf::RectangleShape> getRectanglesVector();
	bool isWindowOpen();
	void eventsControl();
	void display();
	void draw();
	sf::RenderWindow *getWindow();*/
};

