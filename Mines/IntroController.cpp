#include "pch.h"
#include "IntroController.h"
#include "GameManager.h"
#include <vector>

IntroController::IntroController(IntroView &v) : view(v)
{}

void IntroController::handleEvent(sf::Event &event) 
{
	int tmpMode = 0, tmpSize =0;
		
			auto mouse_pos = sf::Mouse::getPosition(view.getWindow()); // Mouse position relative to the window
			auto translated_pos = view.getWindow().mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
			            
				if (view.getRect_easy_mode().getGlobalBounds().contains(translated_pos)) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)  )
					{
						introGameMode = INTRO_EASY;
						tmpMode = 1;
					}
				}
				if (view.getRect_normal_mode().getGlobalBounds().contains(translated_pos)) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						introGameMode = INTRO_NORMAL;
						tmpMode = 1;
					}
				}
				if (view.getRect_hard_mode().getGlobalBounds().contains(translated_pos)) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						introGameMode = INTRO_HARD;
						tmpMode = 1;
					}
				}

				if (view.getRect_small_size().getGlobalBounds().contains(translated_pos)) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						introSize = intro_small;
						tmpSize = 1;
					}
				}
				else if (view.getRect_normal_size().getGlobalBounds().contains(translated_pos)) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						introSize = intro_normal;
						tmpSize = 1;
					}
				}
				else if (view.getRect_big_size().getGlobalBounds().contains(translated_pos)) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						introSize = intro_big;
						tmpSize = 1;
						
					}
				}
				
				if (view.getRect().getGlobalBounds().contains(translated_pos)) {
					if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					{
						finished = true;
					}
				}
			
				
		}
		
	

