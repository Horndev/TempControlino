#include "TCRotaryEncoder.h"

TCRotaryEncoder::TCRotaryEncoder(TCSingleton* tc)
{
	this->tc = tc;
	buttonPushed = false;

	pinMode(tc->pinA, INPUT);
	pinMode(tc->pinB, INPUT);
	pinMode(tc->pinC, INPUT_PULLUP);

	tc->knob->write(200);
	pinALast = digitalRead(tc->pinA);  // Get initial state of rotary
	attachPinChangeInterrupt(
		digitalPinToPinChangeInterrupt(tc->pinC), 
		::handleButtonInterrupt, RISING);
}


TCRotaryEncoder::~TCRotaryEncoder()
{
}
