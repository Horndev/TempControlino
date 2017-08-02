/*
 Name:		TempControlino.ino
 Created:	6/26/2017 10:11:14 PM
 Author:	Steven Horn
*/

#include <ArduinoSTL.h>
#include <Encoder.h>
#include <U8glib.h>

#include "TCSingleton.h"
#include "TCDisplay.h"
#include "TCMenu.h"
#include "TCRotaryEncoder.h"

// This is the temperature controller singleton - all interfaces are handled here.
TCSingleton tc;

TCDisplay* display;	// LED display
TCMenu* menu;
TCRotaryEncoder* encoder;

void setup() {
	display = new TCDisplay(&tc);
	menu = new TCMenu(&tc);
	encoder = new TCRotaryEncoder(&tc);

	//notify the menu when the encoder changes
	encoder->attach((TCRotaryEncoder::ButtonPressObserver*)menu);
	encoder->attach((TCRotaryEncoder::RotationObserver*)menu);
}

void loop() {
  
}
