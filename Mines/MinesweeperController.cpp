#include "pch.h"
#include "MinesweeperController.h"
#include <SFML/Graphics.hpp>
#include <cmath>

MinesweeperController::MinesweeperController(MinesweeperView &v, sf::RenderWindow &win, MSFMLView &mssfmLview, MinesweeperBoard &msb) :view(v),
win(win),
mssfmLview(mssfmLview),
msb(msb)
{}

void MinesweeperController::handleEvent(sf::Event &event) {
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			msb.revealField(0, 0); // albo na odwrót - zale¿nie jak to sobie zdefiniowaliœcie
			msb.revealField(0, 1);
		}
		else if (event.mouseButton.button == sf::Mouse::Right)
		{
			msb.toggleFlag(5, 3); // albo na odwrót - zale¿nie jak to sobie zdefiniowaliœcie
		}
	}

}