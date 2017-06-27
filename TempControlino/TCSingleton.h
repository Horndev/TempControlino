#pragma once

#include <U8glib.h>

class TCSingleton
{
public:
	TCSingleton();
	~TCSingleton();

private:
	U8GLIB* display;
};

