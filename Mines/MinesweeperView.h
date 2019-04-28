#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicView.h"

class MinesweeperView {
	
	GraphicView &graphicView;
	sf::RenderWindow renderWindow;

public:	
	MinesweeperView(GraphicView &graphicView);

	void draw();
};