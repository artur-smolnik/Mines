#include "pch.h"
#include "ScoreView.h"
#include <string>

ScoreView::ScoreView(sf::RenderWindow &renderWindow, MinesweeperBoard &minesweeperBoard)
	:renderWindow(renderWindow),
	minesweeperBoard(minesweeperBoard)
{
	isWindowSet = false;

	if (!font.loadFromFile("arial.ttf")) {
		abort();
	}
	

	
}

void ScoreView::draw() 
{
	
	if (!isWindowSet)
	{
		sf::View view;
		view.setSize(renderWindow.getSize().x, renderWindow.getSize().y);
		renderWindow.setView(view);
		renderWindow.create(sf::VideoMode(500, 500), "SAPER");
		isWindowSet = true;
		//renderWindow.setView(view);
	}
	int flagsAmount = 0;
	for (int i = 0; i < minesweeperBoard.getBoardHeight(); i++)
	{
		for (int j = 0; j < minesweeperBoard.getBoardWidth(); j++)
		{
			if (minesweeperBoard.getFieldInfo(j,i)=='F') flagsAmount++;
		}
	}

	
	
	if (minesweeperBoard.getGameState() == FINISHED_LOSS)
	{
		txt.setString("YOU LOST! " + std::to_string(minesweeperBoard.getMineCount()) + " MINES REMAMINED!");
	}
	else if (minesweeperBoard.getGameState() == FINISHED_WIN)
	{		
		txt.setString("YOU WON AND USED " + std::to_string(flagsAmount) + " FLAGS");
	}
	txt.setFont(font);
	txt.setFillColor(sf::Color::Red);
	txt.setPosition(135, 100);
	txt.setCharacterSize(20);
	renderWindow.draw(txt);


	rect_exit.setSize(sf::Vector2f(100, 50));
	rect_exit.setPosition(195, 190);
	rect_exit.setFillColor(sf::Color::Green);
	txt.setFont(font);
	txt.setString("EXIT");
	txt.setPosition(220, 200);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(20);

	renderWindow.draw(rect_exit);
	renderWindow.draw(txt);

	rect_play_again.setSize(sf::Vector2f(150, 50));
	rect_play_again.setPosition(170, 300);//setPosition(195, 100);
	rect_play_again.setFillColor(sf::Color::Green);
	txt.setFont(font);
	txt.setString("PLAY AGAIN");
	txt.setPosition(180, 310);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(20);

	renderWindow.draw(rect_play_again);
	renderWindow.draw(txt);

	
}
