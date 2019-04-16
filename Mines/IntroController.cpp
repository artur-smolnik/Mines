#include "pch.h"
#include "IntroController.h"
#include "GameManager.h"
#include <vector>
#include <iostream>

IntroController::IntroController(IntroView &introView)

//IntroController::IntroController(IntroView &introView, MinesweeperBoard &minesweeperBoard)
	: introView(introView)
	
{
	settings.columns = 0;
	settings.rows = 0;
	settings.gameMode = DEBUG;
	
}

void IntroController::handleEvent(sf::Event event)
{		
		
		auto mouse_pos = sf::Mouse::getPosition(introView.getWindow()); // Mouse position relative to the window
		auto translated_pos = introView.getWindow().mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
		std::cout << mouse_pos.x << " " << mouse_pos.y << std::endl ;
		if (introView.getRect_easy_mode().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				
				//introView.setFillColorEasyMode();
				settings.gameMode = EASY;
				gm = EASY;
				//minesweeperBoard.setGameMode(settings.gameMode);
			}
		}
		if (introView.getRect_normal_mode().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				//settings.gameMode = NORMAL;
				gm = NORMAL;
			//minesweeperBoard.setGameMode(settings.gameMode);
			}
		}
		if (introView.getRect_hard_mode().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.gameMode = HARD;
				gm = NORMAL;
				//minesweeperBoard.setGameMode(settings.gameMode);
			}
		}

		if (introView.getRect_small_size().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				//introView.setFillColorSmallSize();
				settings.columns = 10;
				settings.rows = 10;
				cols = 10;
				rows = 10;
				//minesweeperBoard.setColumns(settings.columns);
				//minesweeperBoard.setRows(settings.rows);
			}
		}
		if (introView.getRect_normal_size().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.columns = 20;
				settings.rows = 15;
				cols = 20;
				rows = 15;

				//minesweeperBoard.setColumns(settings.columns);
				//minesweeperBoard.setRows(settings.rows);
			}
		}
		if (introView.getRect_big_size().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.columns = 30;
				settings.rows = 20;
				cols = 30;
				rows = 20;

				//minesweeperBoard.setColumns(settings.columns);
				//minesweeperBoard.setRows(settings.rows);
			}
		}

		if (introView.getRect().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				if (settings.columns != 0 && settings.rows != 0 && settings.gameMode != DEBUG)
				{
					//minesweeperBoard = MinesweeperBoard(settings.columns, settings.rows, HARD);
					//std::cout << minesweeperBoard.getBoardHeight() << std::endl;
					//std::cout << minesweeperBoard.getBoardWidth() << settings.gameMode<< std::endl;
					finished = true;
				}
			}
		}		
		
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "the right button was pressed" << std::endl;
				
			}
		}

		draw();
}

void IntroController::draw()
{
	introView.draw();
}


sSettings IntroController::getSettings()
{
	return settings;
}
