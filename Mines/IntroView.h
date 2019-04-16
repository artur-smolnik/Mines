#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "MinesweeperBoard.h"

class IntroView {
	
	

	sf::RectangleShape rect;
	sf::RectangleShape rect_easy_mode;
	sf::RectangleShape rect_normal_mode;
	sf::RectangleShape rect_hard_mode;
	sf::RectangleShape rect_small_size;
	sf::RectangleShape rect_normal_size;
	sf::RectangleShape rect_big_size;
	sf::Font font;
	sf::Text txt;
	sf::Text txt_easy;
	sf::Text txt_normal;
	sf::Text txt_hard;
	sf::Text txt_play;
	sf::Text txt_small_size;
	sf::Text txt_normal_size;
	sf::Text txt_big_size;
	sf::RenderWindow &renderWindow;
	std::vector<sf::RectangleShape> rectangles;	
	
public:
	IntroView(sf::RenderWindow &renderWindow);
	std::vector<sf::RectangleShape> &getRectangles();
	sf::RenderWindow &getWindow() const;
	
	void draw();
	const sf::RectangleShape &getRect_easy_mode() const;
	const sf::RectangleShape &getRect_normal_mode() const;
	const sf::RectangleShape &getRect_hard_mode() const;
	const sf::RectangleShape &getRect() const;
	const sf::RectangleShape &getRect_small_size() const;
	const sf::RectangleShape &getRect_normal_size() const;
	const sf::RectangleShape &getRect_big_size() const;
	void setFillColorEasyMode();
	void setFillColorSmallSize();
	
};
