#include "pch.h"

#include "MinesweeperView.h"

MinesweeperView::MinesweeperView(GraphicView & graphicView)
:graphicView(graphicView)
{
}


void MinesweeperView::draw() {
	graphicView.draw();
}

