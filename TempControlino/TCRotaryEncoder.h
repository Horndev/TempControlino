#pragma once

#include "PinChangeInterrupt.h"
#include "TCSingleton.h"
#include "Events.h"
#include "EventButtonPressed.h"
#include "EventRotate.h"
#include "Config.h"

#include <list>

void handleButtonInterrupt(void);

class TCRotaryEncoder
	: public Subject<EventButtonPressed>
	, public Subject<EventRotate>
{
public:
	typedef typename Subject<EventButtonPressed>::ObserverType  ButtonPressObserver;
	typedef typename Subject<EventRotate>::ObserverType			RotationObserver;
	TCRotaryEncoder(TCSingleton* tc);
	~TCRotaryEncoder();

	void NotifyPressed() 
	{
		int direction = 0;
		for (
			std::list<ButtonPressObserver*>::iterator curr(_buttonPressObservers.begin());
			curr != _buttonPressObservers.end();
			++curr)
		{
			(*curr)->OnEvent(EventButtonPressed());
		}
	};
	void NotifyRotated(int direction = 0)
	{
		for (
			std::list<RotationObserver*>::iterator curr(_rotateObservers.begin());
			curr != _rotateObservers.end();
			++curr)
		{
			(*curr)->OnEvent(EventRotate(direction));
		}
	};

	virtual void subscribe(ButtonPressObserver* observer)
	{
		_buttonPressObservers.push_back(observer);
	}

	virtual void subscribe(RotationObserver* observer)
	{
		_rotateObservers.push_back(observer);
	}

	// This function is called repeatedly in the loop
	void update(void)
	{
		if (buttonPushed)
		{
			buttonPushed = false;
			NotifyPressed();
		}

		long newPosition = tc->knob->read();
		if (newPosition != encoderPosCount) {
			// Check for turning left or right
			// [TODO] - include amount rotated
			if (encoderPosCount > newPosition) {
				NotifyRotated(0); // Left
			}
			else {
				NotifyRotated(1); // Right
			}
			encoderPosCount = newPosition;
		}
	}

	long encoderPosCount = 0;	// Keeps track of how it is rotating
	int pinALast;
	long buttonPushedTime;	// Used to keep track of how long since the user pushed the button
	bool buttonPushed;		// Used to connect the interrupt to this class

private:
	std::list<ButtonPressObserver*> _buttonPressObservers;
	std::list<RotationObserver*>    _rotateObservers;
	TCSingleton* tc;

};

