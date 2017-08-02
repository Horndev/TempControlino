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
private:
	TCSingleton* tc;	// Reference to the singleton class
};

