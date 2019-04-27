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
	int flagsAmount = 0;
	for (int i = 0; i < minesweeperBoard.getBoardHeight(); i++)
	{
		for (int j = 0; j < minesweeperBoard.getBoardWidth(); j++)
		{
			if (minesweeperBoard.getFieldInfo(j,i)=='F') flagsAmount++;
		}
	}

	txt.setFont(font);
	txt.setFillColor(sf::Color::Red);
	
	if (minesweeperBoard.getGameState() == FINISHED_LOSS)
	{
		txt.setString("YOU LOST!");
	}
	else if (minesweeperBoard.getGameState() == FINISHED_WIN)
	{
		std::string tmp = "YOU WON AND USED " + flagsAmount;
		tmp = tmp + " FLAGS";
		txt.setString(tmp);
	}
	//txt.setString("Your score: ");
	txt.setPosition(100, 500);
	txt.setCharacterSize(40);

	renderWindow.draw(txt);

	txt.setFont(font);
	txt.setFillColor(sf::Color::Red);
	txt.setString("w chuj punkciszy");
	txt.setPosition(350, 500);
	txt.setCharacterSize(40);

	renderWindow.draw(txt);

	rect.setSize(sf::Vector2f(100, 50));
	rect.setPosition(250, 175);
	rect.setFillColor(sf::Color::Green);
	txt.setFont(font);
	txt.setString("EXIT");
	txt.setPosition(265, 175);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(20);

	renderWindow.draw(txt);
	renderWindow.draw(rect);

	if (!isWindowSet)
	{
		sf::View view;
		view.setSize(renderWindow.getSize().x, renderWindow.getSize().y);
		renderWindow.setView(view);
		renderWindow.create(sf::VideoMode(500, 500), "SAPER");
		isWindowSet = true;
		//renderWindow.setView(view);
	}
}
