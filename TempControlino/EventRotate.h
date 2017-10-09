#pragma once
class EventRotate
{
public:
	EventRotate(int direction, long position);
	~EventRotate();

	int direction;
	long position;
};

