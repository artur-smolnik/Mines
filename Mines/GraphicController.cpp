#include "pch.h"
#include "GraphicController.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "MinesweeperBoard.h"




GraphicController::GraphicController(MinesweeperBoard &msb, int x0, int y0, int columns, int rows, int size, int gap, int antialiasingLevel, int windowHeight, int windowWidth, GameMode gameMode)
	:msb(msb),
	settings(0, 0, antialiasingLevel, 1, 1, 0, false),
	window(sf::VideoMode(windowWidth, windowHeight), windowName, sf::Style::Default, settings),
	rectangle(sf::Vector2f(size, size))
	
{
	this->x0 = x0;
	this->y0 = y0;
	this->columns = columns;
	this->rows = rows;
	this->size = size;
	this->gap = gap;
	this->antialiasingLevel = antialiasingLevel;
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->gameMode = gameMode;
	
	loadTextures();
	setRectanglesVector();
}

std::vector<sf::RectangleShape> GraphicController::getRectanglesVector()
{
	return rectangles;
}

void GraphicController::loadTextures()
{
	if (!texture_flag.loadFromFile("flaga.png"))std::cout << "ERROR flag";
	if (!texture_bomb.loadFromFile("bomb.jpg"))std::cout << "ERROR bomb";
	if (!texture_0.loadFromFile("0.jpg"))std::cout << "ERROR 0";
	if (!texture_1.loadFromFile("1.jpg"))std::cout << "ERROR 1";
	if (!texture_2.loadFromFile("2.png"))std::cout << "ERROR 2";
	if (!texture_3.loadFromFile("3.png"))std::cout << "ERROR 3";
	if (!texture_4.loadFromFile("4.jpg"))std::cout << "ERROR 4";
	if (!texture_5.loadFromFile("5.jpg"))std::cout << "ERROR 5";
	if (!texture_6.loadFromFile("6.jpg"))std::cout << "ERROR 6";
	if (!texture_7.loadFromFile("7.jpg"))std::cout << "ERROR 7";
	if (!texture_8.loadFromFile("8.jpg"))std::cout << "ERROR 8";
}

void GraphicController::setRectanglesVector()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sf::RectangleShape rectangle;
			rectangle.setPosition(x0 + i * size + i * gap, y0 + j * size + j * gap); //cols,rows
			rectangles.push_back(rectangle);
		}
	}
}

void GraphicController::eventsControl()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		for (int i = 0; i < rectangles.size(); i++)
		{
			auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
			auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
			if (rectangles[i].getGlobalBounds().contains(translated_pos))
			{// Rectangle-contains-point check
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					std::div_t divresult;
					divresult = std::div(i, rows);
					msb.revealField(i % columns, divresult.quot);
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
				{
					std::div_t divresult;
					divresult = std::div(i, rows);
					msb.toggleFlag(i % columns, divresult.quot);
				}
			}
		}
	}
}

void GraphicController::display()
{
	for (int i = 0; i < columns*rows; i++)
	{
		std::div_t divresult;
		divresult = std::div(i, rows);
		if (msb.getFieldInfo(i % columns, divresult.quot) == 'F')
		{
			rectangles[i].setTexture(&texture_flag);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == 'x')
		{
			rectangles[i].setTexture(&texture_bomb);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == '_')
		{
			rectangles[i].setFillColor(sf::Color::Cyan);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == ' ')
		{
			rectangles[i].setTexture(&texture_0);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == '1')
		{
			rectangles[i].setTexture(&texture_1);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == '2')
		{
			rectangles[i].setTexture(&texture_2);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == '3')
		{
			rectangles[i].setTexture(&texture_3);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == '4')
		{
			rectangles[i].setTexture(&texture_4);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == '5')
		{
			rectangles[i].setTexture(&texture_5);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == '6')
		{
			rectangles[i].setTexture(&texture_6);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == '7')
		{
			rectangles[i].setTexture(&texture_7);
		}
		else if (msb.getFieldInfo(i % columns, divresult.quot) == '8')
		{
			rectangles[i].setTexture(&texture_8);
		}
	}
}
