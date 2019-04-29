//#include "pch.h"
#include "MSSFMLController.h"

MSSFMLController::MSSFMLController(MSSFMLView &mSSFMLView, MinesweeperBoard &minesweeperBoard)
	:mSSFMLView(mSSFMLView),
	minesweeperBoard(minesweeperBoard)
{}

void MSSFMLController::draw()
{
	mSSFMLView.draw();
}

void MSSFMLController::handleEvent()
{
	for (int i = 0; i < mSSFMLView.getRectangles().size(); i++)
	{
		auto mouse_pos = sf::Mouse::getPosition(mSSFMLView.getWindow());                // those two lines can be found on sfml forum 
		auto translated_pos = mSSFMLView.getWindow().mapPixelToCoords(mouse_pos);
		if (mSSFMLView.getRectangles()[i].getGlobalBounds().contains(translated_pos))
		{                 
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				std::div_t divresult;  //integer div and modulo div finds right field on main minesweeper board according to selected graphic rectangle on grid
				divresult = std::div(i, mSSFMLView.getColumns());
				minesweeperBoard.revealField(i % mSSFMLView.getColumns(), divresult.quot);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
			{
				std::div_t divresult;
				divresult = std::div(i, mSSFMLView.getColumns());
				minesweeperBoard.toggleFlag(i % mSSFMLView.getColumns(), divresult.quot);
			}
		}
	}		
}

bool MSSFMLController::isFinished() const 
{
	if (minesweeperBoard.getGameState() != RUNNING) return true;
	else return false;
}


