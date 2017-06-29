#pragma once

#include <U8glib.h>
#include <Encoder.h>

class TCSingleton
{
public:
	TCSingleton();
	~TCSingleton();

private:
	U8GLIB* display;
	Encoder* knob;

	int pinA = 2;
	int pinB = 3;   // Connected to DT on KY-040   //has interrupt capability
	int pinC = 7;   // Connected to push button
};

