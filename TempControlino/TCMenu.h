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
	
	void update(void)
	{}
private:
	TCSingleton* tc;	// Reference to the singleton class
	virtual void OnEvent(const EventButtonPressed &event);
	virtual void OnEvent(const EventRotate &event);

	void draw();

	TCMenuItem* hoveredItem;	// This always points to the hovered menu item

	std::list<TCMenuItem*> menuItems;
	
};

