// Mines.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "MinesweeperBoard.h"


int main()                //ogarnij twi sfml
{
	int x0 = 100, y0 = 100, columns = 5, rows = 5, size = 80, gap = 5;
	
	MinesweeperBoard msb(columns, rows, HARD);
	

	std::vector<sf::RectangleShape> rectangles;
	sf::ContextSettings settings;
	
	settings.antialiasingLevel = 32;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML window", sf::Style::Default, settings);

	sf::RectangleShape rectangle(sf::Vector2f(size, size));
	sf::Texture texture;
	if(!texture.loadFromFile("fuckyou.jpg"))std::cout << "ERROR";
	//rectangle.setTexture(&texture);
	

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{			
			rectangle.setPosition(x0 + i * size + i * gap, y0 + j * size + j * gap); //cols,rows
			rectangles.push_back(rectangle);
		}
	}

	

	while (window.isOpen())
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
						for (int j = 0; j < msb.getMinesCords().size(); j++)
						{
							std::div_t divresult;
							divresult = std::div(i, rows);
							if (msb.getMinesCords()[j].x == i % columns && msb.getMinesCords()[j].y == divresult.quot)
							{
								rectangles[i].setTexture(&texture);
							}
						}

					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
					{
						rectangles[i].setFillColor(sf::Color::Blue);
					}
				}
			}
		
		}


		
		window.clear();
		
		for (int i = 0; i < rectangles.size(); i++)
		{
			window.draw(rectangles[i]);
		}
		
		window.display();
	}

	return EXIT_SUCCESS;
}


//sf::VertexArray grid(sf::Lines);

//int x0 = 50, y0 = 50, rows = 7, columns = 10, cellSize = 50;
//
//sf::Vertex poczatek, koniec;

//for (int i = 0; i <= columns; i++)
//{
//	poczatek.position = sf::Vector2f(x0 + (i*cellSize), y0);  //columns
//	poczatek.color = sf::Color(200, 200, 200); // RGB

//	koniec.position = sf::Vector2f(x0 + (i*cellSize), (y0 + rows * cellSize));
//	koniec.color = sf::Color(rand() % 255, rand() % 255, rand() % 255);

//	grid.append(poczatek);
//	grid.append(koniec);
//}

//for (int i = 0; i <= rows; i++)    //rows
//{

//	poczatek.position = sf::Vector2f(x0, y0 + (i*cellSize));
//	poczatek.color = sf::Color(200, 200, 200); // RGB

//	koniec.position = sf::Vector2f((x0 + columns * cellSize), y0 + (i*cellSize));
//	koniec.color = sf::Color(rand() % 255, rand() % 255, rand() % 255);

//	grid.append(poczatek);
//	grid.append(koniec);

//}




//#include <iostream>
//#include <time.h> 
//#include <conio.h>
//#include "Rectangle.h"
//#include "MSBoardTextView.h"
//#include "MinesweeperBoard.h"
//#include "MSTextController.h"
//#include "SFML/"
//
//
//using namespace std;
//int main()
//{	
//	//const int UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77;
//
//	/*srand(time(NULL));
//	MinesweeperBoard board(10, 10, GameMode::HARD);
//	MSBoardTextView view(board);
//	MSTextController ctrl(board, view);
//	ctrl.move();*/
//
//
//
//
//}