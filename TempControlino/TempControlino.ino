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

// This is the temperature controller singleton - all interfaces are handled here.
TCSingleton tc;

TCDisplay* display;	// LED display
TCMenu* menu;

void setup() {
	display = new TCDisplay(&tc);
	menu = new TCMenu(&tc);
}

void loop() {
  
}
