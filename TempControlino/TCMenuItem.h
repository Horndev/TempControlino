#pragma once

#include "TCSingleton.h"
#include "Events.h"
#include "EventClicked.h"

#include <list>
//#include "TCMenu.h"

class TCMenuItem :
	public Subject<EventClicked>
{
public:
	typedef typename Subject<EventClicked>::ObserverType ClickObserver;
	TCMenuItem(String txt = "", String val = "");
	~TCMenuItem();

	int MenuPosition;	//This is the 0-indexed position of this item in the menu

	void NotifyClicked();

	void SetText(String txt)
	{
		text = txt;
	}

	void SetValue(String val)
	{
		value = val;
	}

	virtual void subscribe(ClickObserver* observer)
	{
		_observers.push_back(observer);
	}
private:
	bool isHighlighted;	//Is this menu item highlighted?

	String text;	// Static text shown by menu item
	String value;	// Optional - if the menu item should display a value of some kind.

	TCSingleton*	tc;	//Points to the singleton object, which also contains the root menu which we navigate to on time-out.
	//TCMenu* parent;		//Point to the parent menu
	//TCMenu* submenu;	//If not null, activating this item navigates to this menu
	
	std::list<ClickObserver*> _observers;
};

