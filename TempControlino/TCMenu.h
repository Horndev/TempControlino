#pragma once

#include "TCSingleton.h"
#include "TCMenuItem.h"
#include "Events.h"
#include "EventButtonPressed.h"
#include "EventClicked.h"
#include <list>

class TCMenu
	: public Observer <EventButtonPressed> // Listens for button being pressed
{
public:
	TCMenu(TCSingleton* tc);
	~TCMenu();
	
private:
	TCSingleton* tc;	// Reference to the singleton class
	virtual void OnEvent(const EventButtonPressed &event);

	void draw();

	TCMenuItem* hoveredItem;	// This always points to the hovered menu item

	std::list<TCMenuItem*> menuItems;
	
};

