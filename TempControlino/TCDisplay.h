#pragma once
/* Wrapper class for the LED display module */

#include "U8glib.h"
#include "Config.h"
#include "TCSingleton.h"

class TCDisplay
{
public:
	TCDisplay(TCSingleton* tc);
	~TCDisplay();

	void update(void)
	{

	}

private:
	TCSingleton* tc;	// Reference to the singleton class
};

