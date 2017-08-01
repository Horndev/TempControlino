#pragma once

#include "TCSingleton.h"
#include "TCMenuItem.h"
#include <list>

class TCMenu
{
public:
	TCMenu(TCSingleton* tc);
	~TCMenu();

	void update();
	
private:
	TCSingleton* tc;	// Reference to the singleton class

	void draw();

	std::list<void*> menuItems;
};

