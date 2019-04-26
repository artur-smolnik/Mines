#pragma once
#include "SFML/Graphics.hpp"
#include "MinesweeperView.h"
#include "MinesweeperBoard.h"
class GraphicController
{
	bool finished = false;
	//MinesweeperView &minesweeperView;
	MinesweeperBoard &minesweeperBoard;
	GraphicView &graphicView;
	sf::RenderWindow & renderWindow;

public:
	GraphicController();
	GraphicController(GraphicView &graphicView, sf::RenderWindow & renderWindow, MinesweeperBoard &minesweeperBoard);

	void handleEvent();

	// no need to change this
	void draw(sf::RenderWindow & win);
	bool isFinished() const;

};

