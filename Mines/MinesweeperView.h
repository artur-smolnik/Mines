#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicView.h"

class MinesweeperView {
	
	GraphicView &graphicView;
	sf::RenderWindow renderWindow;

public:
	//MinesweeperView();
	MinesweeperView(GraphicView &graphicView);

	void draw();
};