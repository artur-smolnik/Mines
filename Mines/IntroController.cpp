#include "pch.h"
#include "IntroController.h"
#include "GameManager.h"
#include <vector>
#include <iostream>

IntroController::IntroController(IntroView &introView, GraphicView &graphicView, MinesweeperBoard &minesweeperBoard)

//IntroController::IntroController(IntroView &introView, MinesweeperBoard &minesweeperBoard)
	: introView(introView),
	graphicView(graphicView),
	minesweeperBoard(minesweeperBoard)
	
{
	settings.columns = 0;
	settings.rows = 0;
	settings.gameMode = DEBUG;
	
}

void IntroController::handleEvent()
{		
		
		auto mouse_pos = sf::Mouse::getPosition(introView.getWindow());  // those two lines can be found on sfml forum 
		auto translated_pos = introView.getWindow().mapPixelToCoords(mouse_pos);
		
		if (introView.getRect_easy_mode().getGlobalBounds().contains(translated_pos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{			
				settings.gameMode = EASY;	
				introView.getRect_easy_mode().setFillColor(sf::Color::Green);
				introView.getRect_normal_mode().setFillColor(sf::Color::White);
				introView.getRect_hard_mode().setFillColor(sf::Color::White);
				

			}
		}
		if (introView.getRect_normal_mode().getGlobalBounds().contains(translated_pos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.gameMode = NORMAL;
				introView.getRect_easy_mode().setFillColor(sf::Color::White);
				introView.getRect_normal_mode().setFillColor(sf::Color::Green);
				introView.getRect_hard_mode().setFillColor(sf::Color::White);
			}
		}
		if (introView.getRect_hard_mode().getGlobalBounds().contains(translated_pos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.gameMode = HARD;		
				introView.getRect_easy_mode().setFillColor(sf::Color::White);
				introView.getRect_normal_mode().setFillColor(sf::Color::White);
				introView.getRect_hard_mode().setFillColor(sf::Color::Green);
			}
		}

		if (introView.getRect_small_size().getGlobalBounds().contains(translated_pos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.columns = 10;
				settings.rows = 10;			
				introView.getRect_small_size().setFillColor(sf::Color::Green);
				introView.getRect_normal_size().setFillColor(sf::Color::White);
				introView.getRect_big_size().setFillColor(sf::Color::White);
			}
		}
		if (introView.getRect_normal_size().getGlobalBounds().contains(translated_pos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.columns = 20;
				settings.rows = 15;	
				introView.getRect_small_size().setFillColor(sf::Color::White);
				introView.getRect_normal_size().setFillColor(sf::Color::Green);
				introView.getRect_big_size().setFillColor(sf::Color::White);
			}
		}
		if (introView.getRect_big_size().getGlobalBounds().contains(translated_pos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.columns = 30;
				settings.rows = 20;	
				introView.getRect_small_size().setFillColor(sf::Color::White);
				introView.getRect_normal_size().setFillColor(sf::Color::White);
				introView.getRect_big_size().setFillColor(sf::Color::Green);
			}
		}

		if (introView.getRect().getGlobalBounds().contains(translated_pos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				if (settings.columns != 0 && settings.rows != 0 && settings.gameMode != DEBUG)
				{					
					minesweeperBoard.setWidthAndHeightAndGameMode(settings.columns, settings.rows, settings.gameMode);
					graphicView.setWidthAndHeightAndGameMode(settings.columns, settings.rows, settings.gameMode);
					
					finished = true;
				}
			}
		}		
		

		
}



sSettings IntroController::getSettings()
{
	return settings;
}

void IntroController::draw()
{
	introView.draw();
}
