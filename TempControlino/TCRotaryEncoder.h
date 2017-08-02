#pragma once

#include "TCSingleton.h"
#include "Events.h"
#include "EventButtonPressed.h"
#include "EventRotate.h"

#include <list>

class TCRotaryEncoder
	: public Subject<EventButtonPressed>
	, public Subject<EventRotate>
{
public:
	typedef typename Subject<EventButtonPressed>::ObserverType  ButtonPressObserver;
	typedef typename Subject<EventRotate>::ObserverType			RotationObserver;
	TCRotaryEncoder(TCSingleton* tc);
	~TCRotaryEncoder();

	void NotifyPressed() {};

	void NotifyRotated() 
	{
		int direction = 0;
		for (
			std::list<RotationObserver*>::iterator curr(_rotateObservers.begin());
			curr != _rotateObservers.end();
			++curr)
		{
			(*curr)->OnEvent(EventRotate(direction));
		}
	};

	virtual void attach(ButtonPressObserver* observer)
	{
		_buttonPressObservers.push_back(observer);
	}

	virtual void attach(RotationObserver* observer)
	{
		_rotateObservers.push_back(observer);
	}
private:
	std::list<ButtonPressObserver*> _buttonPressObservers;
	std::list<RotationObserver*>      _rotateObservers;
	TCSingleton* tc;
};

