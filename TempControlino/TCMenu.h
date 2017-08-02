#pragma once

#include "TCSingleton.h"
#include "TCMenuItem.h"
#include "Events.h"
#include "EventButtonPressed.h"
#include <list>

class TCMenu :
	public Observer <EventButtonPressed> // Listens for button being pressed
{
public:
	TCMenu(TCSingleton* tc);
	~TCMenu();
	
private:
	TCSingleton* tc;	// Reference to the singleton class

	void draw();

	std::list<void*> menuItems;
};

