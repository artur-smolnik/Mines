#include "pch.h"

#include "MinesweeperView.h"
#include "MSFMLView.h"

MinesweeperView::MinesweeperView(GraphicView & graphicView)
:graphicView(graphicView)
{
}


void MinesweeperView::draw() {
	graphicView.draw();
}

