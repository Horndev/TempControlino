#pragma once

#include <U8glib.h>
#include <Encoder.h>

#include "Config.h"

class TCSingleton
{
public:
	TCSingleton();
	~TCSingleton();

private:
	U8GLIB* display;
	Encoder* knob;

	int pinA = ENCODER_PINA;
	int pinB = ENCODER_PINB;   // Connected to DT on KY-040   //has interrupt capability
	int pinC = ENCODER_PIN_PUSHBUTTON;   // Connected to push button
};

