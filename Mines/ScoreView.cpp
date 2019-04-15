#include "pch.h"
#include "ScoreView.h"

ScoreView::ScoreView() {
	rect.setSize(sf::Vector2f(200, 100));
	rect.setPosition(100, 200);
}

void ScoreView::draw(sf::RenderWindow &win) {
	win.draw(rect);
}
