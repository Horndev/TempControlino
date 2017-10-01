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
#include "TCMenuItem.h"
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
// Menu
// 1 - no input for 5 seconds = return to home
// 2 ****** HOME
// Set     : 50.0 *C
// Actual  : 34.3 *C
// Heating : 84.0 % 
// 3 ****** MENU
// -- MENU --
// > Heating Mode <
//   PID Tune
//   Firmware
//   Exit Menu
// 4 ****** HEATING MODE
// -- HEATING --
// > Continuous <
//   Switching
//   Settings
//   Exit Menu
// 5 ****** HEATING
// -- HEAT SETTINGS --
// > Max Output : 0.82        (user clicks, then rotation changes value 0 -- 1)
//   Sw Window  : 2.00        (user clicks, then rotation changes value 0.1 -- 5.0)
//   Exit Menu
// 6 ******* PID Tune
// -- PID TUNE --
// > Kp : 12
//   Ki : 3
//   Kd : 9
//   Auto
//   Exit Menu
// 7 ******* Firmware
// -- FIRMWARE --
// Version 1.1
// (C) Steven Horn
// > Exit Menu
void setup() {
	display = new TCDisplay(&tc);
	encoder = new TCRotaryEncoder(&tc);
	controller = new TCController(&tc);

	menu = new TCMenu(&tc);	//this is the root menu
	tc.rootMenu = menu;
	tc.activeMenu = menu;
	TCMenuItem* root_setpoint = new TCMenuItem(F("Set  :"));	// Shows the current set temperature
	TCMenuItem* root_currtemp = new TCMenuItem(F("Temp :"));	// Shows the current temperature
	TCMenuItem* root_heating  = new TCMenuItem(F("Heat :"));	// Shows current heating level (on/off or %)
	TCMenuItem* root_showmenu = new TCMenuItem(F("Menu"));		// Opens the configuration menu

	menu->AddMenuItem(root_setpoint);
	menu->AddMenuItem(root_currtemp);
	menu->AddMenuItem(root_heating);
	menu->AddMenuItem(root_showmenu);
	
	TCMenu* configmenu = new TCMenu(&tc);
	root_showmenu->SetSubMenu(configmenu);
	TCMenuItem* config_hmode = new TCMenuItem(F("Heating Mode"));
	TCMenuItem* config_pid   = new TCMenuItem(F("PID Tune"));
	TCMenuItem* config_fw    = new TCMenuItem(F("Firmware"));
	TCMenuItem* config_exit  = new TCMenuItem(F("Exit Menu"));

	TCMenu* heatmenu = new TCMenu(&tc);
	TCMenuItem* heat_max  = new TCMenuItem(F("Max Output :"));
	TCMenuItem* heat_sw   = new TCMenuItem(F("Sw Window  :"));
	TCMenuItem* heat_exit = new TCMenuItem(F("Exit Menu"));

	TCMenu* pidmenu = new TCMenu(&tc);


	config_exit->SetSubMenu(menu);

	//encoder->subscribe((TCRotaryEncoder::RotationObserver*)root_setpoint);

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
