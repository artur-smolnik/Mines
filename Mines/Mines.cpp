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
	int x0 = 10, y0 = 10, columns = 4, rows = 2, size = 80, gap = 5;	
	
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SAPER");
	
	
	IntroView introView(window);
	
	MinesweeperBoard msb;

	GraphicView graphicView(msb, window);
	IntroController introController(introView, graphicView, msb);
	MinesweeperView minesweeperView(graphicView);
	GraphicController graphicController(minesweeperView, graphicView, window, msb);
	ScoreView scoreView(window);
	ScoreController scoreController(scoreView);
	

	GameManager gameManager(introController, graphicController, scoreController);
	/*scoreView.draw();
	window.display();
	std::cin.ignore(2);*/
		
	while (window.isOpen())
	{

		sf::Event event;
		
		
		
		//window.display();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)window.close();
			
			window.display();
			//introController.handleEvent(event);
			scoreController.handleEvent(event);
			window.display();
		}
		
		
		
		window.display();
		window.clear();
		//gameManager.handleEvent(event);
		
		
		
	}

	std::cout << std::endl << "Koniec gry";
	return EXIT_SUCCESS;
}
