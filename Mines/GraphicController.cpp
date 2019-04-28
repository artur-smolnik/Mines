#include "pch.h"
#include "GraphicController.h"

GraphicController::GraphicController(GraphicView &graphicView, MinesweeperBoard &minesweeperBoard)
	:graphicView(graphicView),	
	minesweeperBoard(minesweeperBoard)
{}

void GraphicController::draw()
{
	graphicView.draw();
}

void GraphicController::handleEvent()
{

	for (int i = 0; i < graphicView.getRectangles().size(); i++)
	{
		auto mouse_pos = sf::Mouse::getPosition(graphicView.getWindow());                // those two lines can be found on sfml forum 
		auto translated_pos = graphicView.getWindow().mapPixelToCoords(mouse_pos);
		if (graphicView.getRectangles()[i].getGlobalBounds().contains(translated_pos))
		{                 
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				std::div_t divresult;  //integer div and modulo div finds right field on main minesweeper board according to selected graphic rectangle on grid
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

bool GraphicController::isFinished() const 
{
	if (minesweeperBoard.getGameState() != RUNNING) return true;
	else return false;
}


