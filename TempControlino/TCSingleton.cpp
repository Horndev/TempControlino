#include "TCSingleton.h"



TCSingleton::TCSingleton()
{
	this->display = new U8GLIB_SH1106_128X64 (U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_FAST);  // Dev 0, Fast I2C / TWI
	this->knob = new Encoder (pinB, pinA);

}


TCSingleton::~TCSingleton()
{
}
