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

void TCMenu::OnEvent(const EventRotate & event)
{
	if (this->hoveredItem->IsActive())
	{
		// rotation should update hovered item value
		//[TODO]
		if (event.direction == 0)
		{
			this->hoveredItem->NotifyRotateLeft(1);
		}
		else
		{
			this->hoveredItem->NotifyRotateRight(1);
		}
	}
}

void TCMenu::draw()
{
	if (this == tc->activeMenu)
	{
		// needs to be rendered
	}
}
