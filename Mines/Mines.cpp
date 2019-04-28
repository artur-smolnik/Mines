//// Mines.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
#include "pch.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "MinesweeperBoard.h"
#include "IntroView.h"
#include "IntroController.h"
#include "MinesweeperView.h"
#include "GraphicController.h"
#include "ScoreView.h"
#include "ScoreController.h"
#include "GameManager.h"

#include "GraphicView.h"

int main()
{
	srand(time(NULL));
	int x0 = 10, y0 = 10, columns = 4, rows = 2, size = 80, gap = 5;	
	
	sf::RenderWindow window(sf::VideoMode(600, 500), "SAPER");
	
	
	IntroView introView(window);
	
	MinesweeperBoard msb;

	GraphicView graphicView(msb, window);
	IntroController introController(introView, graphicView, msb);
	MinesweeperView minesweeperView(graphicView);
	GraphicController graphicController(graphicView, window, msb);
	ScoreView scoreView(window, msb);
	ScoreController scoreController(scoreView);
	

	GameManager gameManager(introController, graphicController, scoreController);
		
	while (window.isOpen())
	{

		sf::Event event;		
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)window.close();
				

		
		}
		
		
		window.clear();

		
		gameManager.handleEvent();
		
		window.display();
		
	}

	std::cout << std::endl << "Koniec gry";
	return EXIT_SUCCESS;
}
