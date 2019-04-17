#include "pch.h"
#include "ScoreView.h"

ScoreView::ScoreView(sf::RenderWindow &renderWindow)
	:renderWindow(renderWindow)
{
	if (!font.loadFromFile("arial.ttf")) {
		abort();
	}


	
}

void ScoreView::draw() 
{
	txt.setFont(font);
	txt.setFillColor(sf::Color::Red);
	txt.setString("Your score: ");
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

	
}
