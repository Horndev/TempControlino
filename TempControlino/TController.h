#pragma once
class TController
{
public:
	TController();
	~TController();

private:
	double Setpoint, Input, Output;  //Define Variables we'll be connecting to
	int Kp;
	int Ki;
	int Kd;
};

