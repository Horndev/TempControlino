#pragma once

#include <U8glib.h>
#include <Encoder.h>

#include "Config.h"

class TCSingleton
{
public:
	TCSingleton();
	~TCSingleton();

	U8GLIB* display;
	Encoder* knob;

	void* activeMenu;
	void* rootMenu;

	int pinA = ENCODER_PINA;
	int pinB = ENCODER_PINB;   // Connected to DT on KY-040   //has interrupt capability
	int pinC = ENCODER_PIN_PUSHBUTTON;   // Connected to push button
};

