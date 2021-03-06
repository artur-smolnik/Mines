//#include "pch.h"
#include "IntroView.h"
#include <cstdlib> 



IntroView::IntroView(sf::RenderWindow &renderWindow) : renderWindow(renderWindow) {
	if (!font.loadFromFile("arial.ttf")) {
		abort();
	}

	rect.setSize(sf::Vector2f(100, 100));
	rect.setPosition(100, 100);
	txt_play.setFont(font);
	txt_play.setFillColor(sf::Color::Red);
	txt_play.setString("Play");
	txt_play.setPosition(120, 125);
	txt.setCharacterSize(20);

	txt.setFont(font);
	txt.setString("SAPER");
	txt.setPosition(300, 20);
	txt.setOutlineThickness(4);
	txt.setOutlineColor(sf::Color::Blue);
	txt.setFillColor(sf::Color::Green);
	txt.setCharacterSize(50);

	rect_easy_mode.setSize(sf::Vector2f(100, 50));
	rect_easy_mode.setPosition(250, 100);
	txt_easy.setFont(font);
	txt_easy.setString("Easy");
	txt_easy.setPosition(280, 100);
	txt_easy.setFillColor(sf::Color::Red);
	txt_easy.setCharacterSize(20);

	rect_normal_mode.setSize(sf::Vector2f(100, 50));
	rect_normal_mode.setPosition(250, 175);
	txt_normal.setFont(font);
	txt_normal.setString("Normal");
	txt_normal.setPosition(265, 175);
	txt_normal.setFillColor(sf::Color::Red);
	txt_normal.setCharacterSize(20);

	rect_hard_mode.setSize(sf::Vector2f(100, 50));
	rect_hard_mode.setPosition(250, 250);
	txt_hard.setFont(font);
	txt_hard.setString("Hard");
	txt_hard.setPosition(275, 250);
	txt_hard.setFillColor(sf::Color::Red);
	txt_hard.setCharacterSize(20);

	rect_small_size.setSize(sf::Vector2f(100, 50));
	rect_small_size.setPosition(400, 100);
	txt_small_size.setFont(font);
	txt_small_size.setString("10x10");
	txt_small_size.setPosition(425, 100);
	txt_small_size.setFillColor(sf::Color::Red);
	txt_small_size.setCharacterSize(20);

	rect_normal_size.setSize(sf::Vector2f(100, 50));
	rect_normal_size.setPosition(400, 175);
	txt_normal_size.setFont(font);
	txt_normal_size.setString("20x15");
	txt_normal_size.setPosition(425, 175);
	txt_normal_size.setFillColor(sf::Color::Red);
	txt_normal_size.setCharacterSize(20);

	rect_big_size.setSize(sf::Vector2f(100, 50));
	rect_big_size.setPosition(400, 250);
	txt_big_size.setFont(font);
	txt_big_size.setString("30x20");
	txt_big_size.setPosition(425, 250);
	txt_big_size.setFillColor(sf::Color::Red);
	txt_big_size.setCharacterSize(20);

	identities.setFont(font);
	identities.setString("Artur Smolnik 249092");
	identities.setPosition(100, 450);
	identities.setFillColor(sf::Color::Red);
	identities.setCharacterSize(15);


	rectangles.push_back(rect);
	rectangles.push_back(rect_easy_mode);
	rectangles.push_back(rect_normal_mode);
	rectangles.push_back(rect_hard_mode);
	rectangles.push_back(rect_small_size);
	rectangles.push_back(rect_normal_size);
	rectangles.push_back(rect_big_size);


}

void IntroView::draw() {
	renderWindow.draw(identities);
	renderWindow.draw(rect);
	renderWindow.draw(txt_play);
	renderWindow.draw(txt);
	renderWindow.draw(rect_easy_mode);
	renderWindow.draw(txt_easy);
	renderWindow.draw(rect_normal_mode);
	renderWindow.draw(txt_normal);
	renderWindow.draw(rect_hard_mode);
	renderWindow.draw(txt_hard);
	renderWindow.draw(rect_small_size);
	renderWindow.draw(txt_small_size);
	renderWindow.draw(rect_normal_size);
	renderWindow.draw(txt_normal_size);
	renderWindow.draw(rect_big_size);
	renderWindow.draw(txt_big_size);
}



sf::RenderWindow &IntroView::getWindow() const {
	return renderWindow;
}


sf::RectangleShape &IntroView::getRect() {
	return rect;
}

std::vector<sf::RectangleShape> &IntroView::getRectangles()
{
	return rectangles;
}

sf::RectangleShape &IntroView::getRect_easy_mode() {
	return rect_easy_mode;
}

sf::RectangleShape &IntroView::getRect_normal_mode() {
	return rect_normal_mode;
}

sf::RectangleShape &IntroView::getRect_hard_mode() {
	return rect_hard_mode;
}

sf::RectangleShape &IntroView::getRect_small_size() {
	return rect_small_size;
}

sf::RectangleShape &IntroView::getRect_normal_size() {
	return rect_normal_size;
}

sf::RectangleShape &IntroView::getRect_big_size() {
	return rect_big_size;
}
