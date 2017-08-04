#pragma once

#include "TCSingleton.h"

class TCController
{
public:
	TCController(TCSingleton* tc);
	~TCController();

	void update(void) {};
private:
	TCSingleton* tc;
};

