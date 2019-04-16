#include "pch.h"
#include "IntroController.h"
#include "GameManager.h"
#include <vector>
#include <iostream>

IntroController::IntroController(IntroView &introView, GraphicView &graphicView)

//IntroController::IntroController(IntroView &introView, MinesweeperBoard &minesweeperBoard)
	: introView(introView),
	graphicView(graphicView)
	
{
	settings.columns = 0;
	settings.rows = 0;
	settings.gameMode = DEBUG;
	
}

void IntroController::handleEvent(sf::Event event)
{		
		
		auto mouse_pos = sf::Mouse::getPosition(introView.getWindow()); // Mouse position relative to the window
		auto translated_pos = introView.getWindow().mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
		
		if (introView.getRect_easy_mode().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{			
				settings.gameMode = EASY;				
			}
		}
		if (introView.getRect_normal_mode().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				gm = NORMAL;
			}
		}
		if (introView.getRect_hard_mode().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.gameMode = HARD;				
			}
		}

		if (introView.getRect_small_size().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.columns = 10;
				settings.rows = 10;				
			}
		}
		if (introView.getRect_normal_size().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.columns = 20;
				settings.rows = 15;				
			}
		}
		if (introView.getRect_big_size().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				settings.columns = 30;
				settings.rows = 20;				
			}
		}

		if (introView.getRect().getGlobalBounds().contains(translated_pos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				if (settings.columns != 0 && settings.rows != 0 && settings.gameMode != DEBUG)
				{					
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
