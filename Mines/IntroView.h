#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

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
	sf::RenderWindow &window;
	std::vector<sf::RectangleShape> rectangles;

	
	
	

	

public:
	std::vector<sf::RectangleShape> &getRectangles();

	const sf::RectangleShape &getRect_easy_mode() const;
	const sf::RectangleShape &getRect_normal_mode() const;
	const sf::RectangleShape &getRect_hard_mode() const;
	sf::RenderWindow &getWindow() const;
	IntroView(sf::RenderWindow &window);
	const sf::RectangleShape &getRect() const;
	void draw(sf::RenderWindow &win);
	const sf::RectangleShape &getRect_small_size() const;
	const sf::RectangleShape &getRect_normal_size() const;
	const sf::RectangleShape &getRect_big_size() const;

	
};
