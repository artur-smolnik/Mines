#include "pch.h"

#include "MinesweeperView.h"
#include "MSFMLView.h"

MinesweeperView::MinesweeperView(MSFMLView &mssfmLview) :mssfmLview(mssfmLview) {}

void MinesweeperView::draw(sf::RenderWindow &win) {
	mssfmLview.draw();
}

