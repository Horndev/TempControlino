/*
 Name:		TempControlino.ino
 Created:	6/26/2017 10:11:14 PM
 Author:	Steven Horn
*/

#include "PinChangeInterrupt.h""
#include <ArduinoSTL.h>
#include <Encoder.h>
#include <U8glib.h>

#include "Arduino.h"
#include "TCSingleton.h"
#include "TCDisplay.h"
#include "TCMenu.h"
#include "TCRotaryEncoder.h"
#include "TCController.h"
#include "TCMemory.h"

// This is the temperature controller singleton - all interfaces are handled here.
TCSingleton tc;

TCDisplay* display;			// LED display
TCMenu* menu;				// User interface
TCRotaryEncoder* encoder;	// Rotary encoder
TCController* controller;	// PID controller
TCMemory memory;			// Used for non-volatile storage

void handleButtonInterrupt(void)
{
	encoder->buttonPushed = true;
	encoder->buttonPushedTime = millis();
}

void setup() {
	display = new TCDisplay(&tc);
	menu = new TCMenu(&tc);
	encoder = new TCRotaryEncoder(&tc);
	controller = new TCController(&tc);

	//notify the menu when the encoder changes
	encoder->subscribe((TCRotaryEncoder::ButtonPressObserver*)menu);
	encoder->subscribe((TCRotaryEncoder::RotationObserver*)menu);
}

void loop() {
	encoder->update();
	menu->update();
	display->update();
	controller->update();
}
