#pragma once

#include "TCSingleton.h"
#include "TCMenuItem.h"
#include "Events.h"
#include "EventButtonPressed.h"
#include "EventClicked.h"
#include "EventRotate.h"
#include <list>

class TCMenu
	: public Observer <EventButtonPressed> // Listens for button being pressed
	, public Observer <EventRotate>
{
public:
	TCMenu(TCSingleton* tc);
	~TCMenu();
	
	void update(void) {

	}
	
	// Adds the menuitem to the menu
	void AddMenuItem(TCMenuItem* mi)
	{
		menuItems.push_back(mi);
	}

	void draw();
private:
	TCSingleton* tc;	// Reference to the singleton class
	virtual void OnEvent(const EventButtonPressed &event);
	virtual void OnEvent(const EventRotate &event);

	TCMenu*	submenu;
	TCMenu* rootmenu;

	TCMenuItem* hoveredItem;	// This always points to the hovered menu item

	std::list<TCMenuItem*> menuItems;
	
};

