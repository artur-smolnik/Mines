// Mines.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "MinesweeperBoard.h"
#include <time.h> 
#include <conio.h>
#include "AdditionalFunctions.h"
#include "Rectangle.h"
using namespace std;
int main()
{
	////const int UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77;

	//srand(time(NULL));
	//MinesweeperBoard minesweeperBoard(10, 10, GameMode::HARD);
	//AdditionalFunctions af(minesweeperBoard);
	////minesweeperBoard.debug_display();
	//af.move();
	// Create the main window
	sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

	Rectangle rect;

	// Start the game loop
	while (app.isOpen())
	{
		// Process events
		sf::Event event;
		while (app.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				app.close();
		}

		// Clear screen
		app.clear();

		// Draw rectangle
		rect.draw(app);

		// Update the window
		app.display();
	}

	return EXIT_SUCCESS;
	

}