#pragma once

#include "TCSingleton.h"
#include "Events.h"
#include "EventButtonPressed.h"
#include "EventRotateLeft.h"
#include "EventRotateRight.h"

#include <list>

class TCRotaryEncoder
	: public Subject<EventButtonPressed>
	, public Subject<EventRotateLeft>
	, public Subject<EventRotateRight>
{
public:
	typedef typename Subject<EventButtonPressed>::ObserverType ButtonPressObserver;
	typedef typename Subject<EventRotateLeft>::ObserverType    RotateLeftObserver;
	typedef typename Subject<EventRotateRight>::ObserverType   RotateRightObserver;
	TCRotaryEncoder();
	~TCRotaryEncoder();

	void NotifyPressed() {};
private:
	std::list<ButtonPressObserver*> _buttonPressObservers;
};

