// Mines.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "MinesweeperBoard.h"


int main()                //ogarnij twi sfml
{
	int x0 = 10, y0 = 10, columns = 10, rows = 10, size = 80, gap = 5;
	
	MinesweeperBoard msb(columns, rows, HARD);
	

	std::vector<sf::RectangleShape> rectangles;
	sf::ContextSettings settings;
	
	settings.antialiasingLevel = 32;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML window", sf::Style::Default, settings);

	sf::RectangleShape rectangle(sf::Vector2f(size, size));
	sf::Texture texture_bomb, texture_flag, texture_0, texture_1, texture_2, texture_3, texture_4, texture_5, texture_6, texture_7, texture_8;
	
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

		for (int i = 0; i < columns*rows; i++)
		{
			std::div_t divresult;
			divresult = std::div(i, rows);
			if (msb.getFieldInfo(i % columns, divresult.quot)=='F')
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
		
		window.clear();
		
		for (int i = 0; i < rectangles.size(); i++)
		{
			window.draw(rectangles[i]);
		}
		
		window.display();
		if (msb.getGameState() != RUNNING) std::cin.ignore();
	}
	
	std::cout<<std::endl << "Koniec gry";
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