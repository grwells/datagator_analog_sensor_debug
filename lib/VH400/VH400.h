#ifndef VH400_H
#define VH400_H

#include <Arduino.h>

class VH400 {
private:
	int analog_pin;
	int pwr_pin;

public:	
	VH400(int analog_pin, int pwr_pin);
	VH400(){}
	float readVoltage();
	double getVWC();
	double getVWC(double voltage);
};

#endif