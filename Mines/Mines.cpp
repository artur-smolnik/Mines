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
	IntroController introController(introView);
	MinesweeperBoard msb(introController.getSettings().columns, introController.getSettings().rows, introController.getSettings().gameMode);
	GraphicView graphicView(msb, window, x0, y0, columns, rows, size, gap);
	MinesweeperView minesweeperView(graphicView);
	GraphicController graphicController(minesweeperView, graphicView, window, msb);
	ScoreView scoreView;
	ScoreController scoreController(scoreView);
	

	GameManager gameManager(introController, graphicController, scoreController);

		
	while (window.isOpen())
	{

		sf::Event event;
		
		
		
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)window.close();
				

			//gameManager.handleEvent(event);
			//graphicController.handleEvent();
			//gameManager.handleEvent(event);
			//introController.handleEvent();
			//introController.draw();
		}
		
		
		//gc.display();
		window.clear();

		//introController.handleEvent(event);
		//graphicView.draw();
		gameManager.handleEvent(event);
		
		window.display();
		//if (msb.getGameState() != RUNNING) std::cin.ignore();
	}

	std::cout << std::endl << "Koniec gry";
	return EXIT_SUCCESS;
}

//
//int main()                //ogarnij twi sfml
//{
//	int x0 = 100, y0 = 100, columns = 5, rows = 5, size = 80, gap = 5;
//
//	sf::RenderWindow win(sf::VideoMode(800, 600), "SFML window");
//
//	IntroView iv(win);
//	IntroController ic(iv);
//	MinesweeperBoard msb(columns, rows, HARD);
//	MSFMLView msfmlView(msb, win, x0, y0, columns, rows, size, gap);
//
//	//MSFMLView(MinesweeperBoard &msb, sf::RenderWindow &window, int x0, int y0, int columns, int rows, int size, int gap);
//	// generalnie - do kontrolera przeka�emy referencje na widok i model, czyli
//    //IntroController ic(iv, im);
//	// w tym przypadku model jest tak prosty, �e "zintegrowa�em" go z widokiem
//
//	// fake - zast�pcie Wasz� klas�, dodajcie model planszy
//	MinesweeperView mv(msfmlView);
//	MinesweeperController mc(mv,win, msfmlView, msb);
//
//	// uwagi jak do Intro
//	ScoreView sv;
//	ScoreController sc(sv);
//
//	GameManager gm(ic, mc, sc);
//
//	// Start the game loop
//	while (win.isOpen()) {
//		// Process events
//		sf::Event event;
//		while (win.pollEvent(event)) {
//			// Close window : exit
//			if (event.type == sf::Event::Closed)
//				win.close();
//
//			
//			gm.handleEvent(event);
//		}
//
//		// Clear screen
//		win.clear();
//
//		// Draw current state
//		gm.draw(win);
//
//		// Update the window
//		win.display();
//	}
//
//
//
//	
//	std::cout << std::endl << "Koniec gry";
//	return EXIT_SUCCESS;
//}