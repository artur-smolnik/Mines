// Mines.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>

int main()                //ogarnij twi sfml
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 32;


	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Default, settings);

	sf::VertexArray piramida(sf::Lines);

	int x0 = 50, y0 = 50, rows = 5, columns = 7, cellSize = 50;
	
		sf::Vertex poczatek, koniec;
		
		for (int i = 0; i <= rows; i++)
		{
			poczatek.position = sf::Vector2f(x0+(i*cellSize), y0);  //rows
			poczatek.color = sf::Color(200, 200, 200); // RGB

			koniec.position = sf::Vector2f(x0+(i*cellSize), (y0 + rows*cellSize));
			koniec.color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
			piramida.append(poczatek);

			piramida.append(koniec);

			

		}

		for (int i = 0; i <= columns; i++)    //columns
		{
			
			poczatek.position = sf::Vector2f(x0, y0 + (i*cellSize));
			poczatek.color = sf::Color(200, 200, 200); // RGB

			koniec.position = sf::Vector2f((x0+columns*cellSize), y0 + (i*cellSize));
			koniec.color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
			
			piramida.append(poczatek);
			piramida.append(koniec);

		}


		

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear screen
		window.clear();

		window.draw(piramida);

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}





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