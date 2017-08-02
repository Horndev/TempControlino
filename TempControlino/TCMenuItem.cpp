#include "TCMenuItem.h"



TCMenuItem::TCMenuItem()
{
}


TCMenuItem::~TCMenuItem()
{
}

void TCMenuItem::NotifyClicked()
{
	// Let all observers know this item was clicked
	for (
		std::list<ClickObserver*>::iterator curr(_observers.begin());
		curr != _observers.end();
		++curr)
	{
		(*curr)->OnEvent(EventClicked());
	}
}
