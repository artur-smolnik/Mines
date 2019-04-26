#include "pch.h"
#include "GraphicController.h"

GraphicController::GraphicController(GraphicView & graphicView, sf::RenderWindow & renderWindow, MinesweeperBoard &minesweeperBoard)
	:graphicView(graphicView),
	renderWindow(renderWindow),
	minesweeperBoard(minesweeperBoard)
{}

void GraphicController::handleEvent()
{
	draw(renderWindow);
	for (int i = 0; i < graphicView.getRectangles().size(); i++)
	{
		auto mouse_pos = sf::Mouse::getPosition(renderWindow); // Mouse position relative to the window
		auto translated_pos = renderWindow.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
		if (graphicView.getRectangles()[i].getGlobalBounds().contains(translated_pos))
		{                 
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				std::div_t divresult;
				divresult = std::div(i, graphicView.getColumns());
				minesweeperBoard.revealField(i % graphicView.getColumns(), divresult.quot);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
			{
				std::div_t divresult;
				divresult = std::div(i, graphicView.getColumns());
				minesweeperBoard.toggleFlag(i % graphicView.getColumns(), divresult.quot);
			}
		}
	}
		
}

void GraphicController::draw(sf::RenderWindow & win)
{
	graphicView.draw();
}

bool GraphicController::isFinished() const 
{
	if (minesweeperBoard.getGameState() != RUNNING) return true;
	else return false;
}


