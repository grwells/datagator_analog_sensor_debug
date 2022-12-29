#ifndef TEROS10_H
#define TEROS10_H

#include <Arduino.h>

class Teros10{
private:
	int analog_pin; // pin the sensor is connected to and can be read from
	int pwr_pin;	// pin that must be powered to read from the sensor

public:
	enum SoilMedia {MINERAL_SOIL, SOILLESS};

	Teros10(int analog_pin, int pwr_pin);
	Teros10(){}
	float readVoltage();					// read just the voltage measured by the sensor
	double getVWC(SoilMedia media);			// read the sensor and return the VWC as a decimal which represents the VWC as a percentage
	double getVWC(SoilMedia media, double voltage);
	double apparentDialectricPermitivity(); // read dialectric permitivity which can then be converted to VWC using Topp equation
};

#endif