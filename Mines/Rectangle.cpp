#include "pch.h"
#include "Rectangle.h"

Rectangle::Rectangle()
{
	lines.setPrimitiveType(sf::Quads);          // czworok�t definiowany przez 4 punkty
	lines.append(sf::Vector2f(20, 20));         // wspolrzedne rog�w prostokata
	lines.append(sf::Vector2f(200, 20));
	lines.append(sf::Vector2f(200, 80));
	lines.append(sf::Vector2f(20, 80));
}


void Rectangle::draw(sf::RenderWindow & window)
{
	window.draw(lines);
}
