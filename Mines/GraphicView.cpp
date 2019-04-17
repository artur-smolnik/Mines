#include "pch.h"
#include "GraphicView.h"
#include <iostream>
#include <vector>
#include "MinesweeperBoard.h"




GraphicView::GraphicView(MinesweeperBoard &msb, sf::RenderWindow &renderWindow)
	:msb(msb),
	renderWindow(renderWindow)
{
	this->x0 = 20;
	this->y0 = 20;	
	this->size = 20;
	this->gap = 5;
	
}

void GraphicView::setWidthAndHeightAndGameMode(int width, int height, GameMode gameMode)
{
	this->columns = width;
	this->rows = height;
	this->gameMode = gameMode;
	
	loadTextures();
	setRectanglesVector();
}

void GraphicView::loadTextures()
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

void GraphicView::setRectanglesVector()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sf::RectangleShape rectangle(sf::Vector2f(size, size));
			rectangle.setPosition(x0 + j * size + j * gap, y0 + i * size + i * gap); //cols,rows
			rectangles.push_back(rectangle);
		}
	}
}


void GraphicView::display()
{
	for (int i = 0; i < columns*rows; i++)
	{
		std::div_t divresult;
		divresult = std::div(i, columns);
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

void GraphicView::draw()
{
	display();
	for (int i = 0; i < rectangles.size(); i++)
	{
		renderWindow.draw(rectangles[i]);
	}
}

std::vector<sf::RectangleShape>& GraphicView::getRectangles()
{
	return rectangles;
}

int GraphicView::getColumns()
{
	return columns;
}

void GraphicView::setColumns(int newColumns)
{
	 columns = newColumns;
}

