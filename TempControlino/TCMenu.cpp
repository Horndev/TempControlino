#include "TCMenu.h"



TCMenu::TCMenu(TCSingleton* tc)
{
	this->tc = tc;
}


TCMenu::~TCMenu()
{
}

void TCMenu::OnEvent(const EventButtonPressed & event)
{
	// This is activated when the user has pressed the push button.
	this->hoveredItem->NotifyClicked();
}

void TCMenu::draw()
{
}
